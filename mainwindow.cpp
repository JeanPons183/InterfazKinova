#include "mainwindow.h"
#include "./ui_mainwindow.h"

//function headers
#include <array>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>
#include <numeric>

// To save data to a file -----
#include <fstream>
#include <cstring>

// Kinova Headers
#include <BaseClientRpc.h>
#include <BaseCyclicClientRpc.h>
#include <ActuatorConfigClientRpc.h>
#include <SessionClientRpc.h>
#include <SessionManager.h>
#include <RouterClient.h>
#include <TransportClientUdp.h>
#include <TransportClientTcp.h>
#include <argh.h>
#include <google/protobuf/util/json_util.h>

// Time count / managment
#if defined(_MSC_VER)
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <time.h>

// Mini matrices library
#include "mat.h"

// Gen3 lite specific funcions
// -- i.e. Gravity Vector, Jacobian & Pose calculation
#include "Gen3lite_model.h"

using namespace KinovaGen3lite;

using namespace std;

//---------------------------------------------------------------------
namespace k_api = Kinova::Api;

#define PORT 10000
#define PORT_REAL_TIME 10001

// deg2rad: Convertion degrees to radians
const float deg2rad = 3.1415926565359 / 180.0f;
// rad2deg : Convertion radians to degrees
const float rad2deg = 180.0f / 3.1415926565359 ;
// dt : Low Level time step
const float dt = 0.001;
// TIME_DURATION : Experiment duration (seconds)
float TIME_DURATION = 10.0f;

// Maximum allowed waiting time during actions
constexpr auto TIMEOUT_PROMISE_DURATION = std::chrono::seconds{20};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::RobotConnect(int argc, char **argv)
{
    // ************************************************************************
    // *************    PASO 1. CONEXIÓN              *************************
    //*************************************************************************

    // Input options / parameters
    argh::parser cmdl({"ip","t","time","username","password"});
    cmdl.parse(argc, argv);
    // Default Parameters
    string ip_address = cmdl("ip", "192.168.2.10").str();
    string username = cmdl("username", "admin").str();
    string password = cmdl("password", "admin").str();
    float simTime;

    // Check for missing parameter and/or bad (inconvertible) parameter value
    if ((cmdl({"t","time"}) >> simTime))
    {
        TIME_DURATION = simTime;
    }

    // Create KORTEX API objects
    auto error_callback = [](k_api::KError err)
    { cout << "_________ callback error _________" << err.toString(); };

    // ************** 1.1 Sesión TDP para conexión con la base *********************
    // * High level communication connection - TCP
    std::cout << "Creating transport objects" << std::endl;
    auto transport = new k_api::TransportClientTcp();
    auto router = new k_api::RouterClient(transport, error_callback);
    //transport->connect(parsed_args.ip_address, PORT);
    transport->connect(ip_address, PORT);

    // **************** 1.2 Sesión TDP para conexión con la base *******************
    // * Low level communication connection - UDP
    std::cout << "Creating transport real time objects" << std::endl;
    auto transport_real_time = new k_api::TransportClientUdp();
    auto router_real_time = new k_api::RouterClient(transport_real_time, error_callback);
    //transport_real_time->connect(parsed_args.ip_address, PORT_REAL_TIME);
    transport_real_time->connect(ip_address, PORT_REAL_TIME);

    // Set session data connection information
    auto create_session_info = k_api::Session::CreateSessionInfo();
    create_session_info.set_username(username);
    create_session_info.set_password(password);
    create_session_info.set_session_inactivity_timeout(60000);   // (milliseconds)
    create_session_info.set_connection_inactivity_timeout(2000); // (milliseconds)


    // Example core

    bool success = true;
    //success &= example_move_to_home_position(base);
    //success &= example_cartesian_action_movement(base, base_cyclic);
    //success &= example_angular_action_movement(base);

    // You can also refer to the 110-Waypoints examples if you want to execute
    // a trajectory defined by a series of waypoints in joint space or in Cartesian space

    // Close API session
    session_manager->CloseSession();

    // Deactivate the router and cleanly disconnect from the transport object
    router->SetActivationStatus(false);
    transport->disconnect();

    // Destroy the API
    delete base;
    delete session_manager;
    delete router;
    delete transport;

    return success? 0: 1;
}

//GetMeasuredJointAngles Retrieves the currently measured joint angles for each joint
//SendGripperCommand
//GetMeasuredGripperMovement
//GetArmState Retrieves current robot arm state
//GetTrajectoryErrorReport
//ComputeForwardKinematics
bool move_to_zeros_position(k_api::Base::BaseClient* base) //Move the robot to zeros using high level control using the api - angular movement
{
    std::cout << "Starting angular action movement ..." << std::endl;

    auto action = k_api::Base::Action();
    action.set_name("Moving robot to positions zero");
    action.set_application_data("");

    auto reach_joint_angles = action.mutable_reach_joint_angles();
    auto joint_angles = reach_joint_angles->mutable_joint_angles();

    auto actuator_count = base->GetActuatorCount();

    // Arm straight up
    for (size_t i = 0; i < actuator_count.count(); ++i)
    {
        auto joint_angle = joint_angles->add_joint_angles();
        joint_angle->set_joint_identifier(i);
        joint_angle->set_value(0);
    }

    // Connect to notification action topic
    // (Promise alternative)
    // See cartesian examples for Reference alternative
    std::promise<k_api::Base::ActionEvent> finish_promise;
    auto finish_future = finish_promise.get_future();
    auto promise_notification_handle = base->OnNotificationActionTopic(
        create_event_listener_by_promise(finish_promise),
        k_api::Common::NotificationOptions()
        );

    std::cout << "Executing action" << std::endl;
    base->ExecuteAction(action);

    std::cout << "Waiting for movement to finish ..." << std::endl;

    // Wait for future value from promise
    // (Promise alternative)
    // See cartesian examples for Reference alternative
    const auto status = finish_future.wait_for(TIMEOUT_DURATION);
    base->Unsubscribe(promise_notification_handle);

    if(status != std::future_status::ready)
    {
        std::cout << "Timeout on action notification wait" << std::endl;
        return false;
    }
    const auto promise_event = finish_future.get();

    std::cout << "Angular movement completed" << std::endl;
    std::cout << "Promise value : " << k_api::Base::ActionEvent_Name(promise_event) << std::endl;

    return true;
}
