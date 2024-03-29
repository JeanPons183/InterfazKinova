#include "kinovarobot.h"

#include <iostream>

KinovaRobot::KinovaRobot(const std::string& ip, const std::string& user, const std::string& password, unsigned int PORT, unsigned int PORT_REAL_TIME)
{
    robot_ip = ip;
    robot_username = user;
    robot_password = password;
    robot_PORT = PORT;
    robot_PORT_REAL_TIME = PORT_REAL_TIME;
}

KinovaRobot::~KinovaRobot()
{
    Disconnect();
}

bool KinovaRobot::Init()
{
    // ************************************************************************
    // *************            CONEXIÓN              *************************
    //*************************************************************************

    if (robotIsConnected) {
        Disconnect();
    }

    auto error_callback = [](Kinova::Api::KError err){ cout << "_________ callback error _________" << err.toString(); };
    robot_transport = new Kinova::Api::TransportClientTcp();
    robot_router = new Kinova::Api::RouterClient(robot_transport, error_callback);

    auto create_session_info = Kinova::Api::Session::CreateSessionInfo();
    create_session_info.set_username(robot_username);
    create_session_info.set_password(robot_password);
    create_session_info.set_session_inactivity_timeout(60000);   // (milliseconds)
    create_session_info.set_connection_inactivity_timeout(2000); // (milliseconds)

    robot_transport->connect(robot_ip, robot_PORT);



    if (!robot_transport->connect(robot_ip, robot_PORT))
    {

        Disconnect();
        return false; //failed to connect TCP
    }
    try {   //Conectamos con el puerto TCP y configuramos el robot a un modo de control inicial SINGLE_LEVEL_SERVOING (Alto nivel)
        robot_session_manager = new Kinova::Api::SessionManager(robot_router);
        robot_session_manager->CreateSession(create_session_info);

        //Acceder a la base del robot
        robot_deviceConfigClient = new Kinova::Api::DeviceConfig::DeviceConfigClient(robot_router);
        robot_base = new Kinova::Api::Base::BaseClient(robot_router);
        robot_controlConfigClient = new Kinova::Api::ControlConfig::ControlConfigClient(robot_router);

        auto servoingMode = Kinova::Api::Base::ServoingModeInformation();

        servoingMode.set_servoing_mode(Kinova::Api::Base::ServoingMode::SINGLE_LEVEL_SERVOING);

        //robot_base->SetServoingMode(servoingMode);


       // robot_DoF = robot_base->GetActuatorCount().count();
    }
    catch (Kinova::Api::KDetailedException ex) {
        OnError(ex);
        Disconnect();
        return false;
    }

    // Conectamos con el puerto - UDP
    robot_transport_real_time = new Kinova::Api::TransportClientUdp();
    robot_router_real_time = new Kinova::Api::RouterClient(robot_transport_real_time, error_callback);

    robot_transport_real_time->connect(robot_ip, robot_PORT_REAL_TIME);

    if (!robot_transport_real_time->connect(robot_ip, robot_PORT_REAL_TIME))
    {
        Disconnect();
        return false; //failed to connect UDP
    }

    try {
        robot_session_manager_real_time = new Kinova::Api::SessionManager(robot_router_real_time);
        robot_session_manager_real_time->CreateSession(create_session_info);
        robot_base_cyclic = new Kinova::Api::BaseCyclic::BaseCyclicClient(robot_router_real_time);
        robot_actuator_config = new Kinova::Api::ActuatorConfig::ActuatorConfigClient(robot_router_real_time);

    }
    catch (Kinova::Api::KDetailedException ex) {
        OnError(ex);
        Disconnect();
        return false;
    }

    robotIsConnected = true;

    return true;
}

void KinovaRobot::Disconnect()
{
    if (robotIsConnected) {
        // Close API session
        //ui->label_EstadoActual->setText("Cerrando sesión con el Robot");
        robot_session_manager->CloseSession();
        robot_session_manager_real_time->CloseSession();

        // Deactivate the router and cleanly disconnect from the transport object
        robot_router->SetActivationStatus(false);
        robot_router_real_time->SetActivationStatus(false);

        robot_transport->disconnect();
        robot_transport_real_time->disconnect();
    }
    // Destroy the API

    robotIsConnected = false;

    if (robot_base != nullptr)
    {
        delete robot_base;
        robot_base = nullptr;
    }

    if (robot_base_cyclic != nullptr)
    {
        delete robot_base_cyclic;
        robot_base_cyclic = nullptr;
    }

    if (robot_actuator_config != nullptr)
    {
        delete robot_actuator_config;
        robot_actuator_config = nullptr;
    }

    if (robot_session_manager != nullptr)
    {
        delete robot_session_manager;
        robot_session_manager = nullptr;
    }

    if (robot_session_manager_real_time != nullptr)
    {
        delete robot_session_manager_real_time;
        robot_session_manager_real_time = nullptr;
    }

    if (robot_router != nullptr)
    {
        delete robot_router;
        robot_router = nullptr;
    }

    if (robot_router_real_time != nullptr)
    {
        delete robot_router_real_time;
        robot_router_real_time = nullptr;
    }

    if (robot_transport != nullptr)
    {
        delete robot_transport;
        robot_transport = nullptr;
    }

    if (robot_transport_real_time != nullptr)
    {
        delete robot_transport_real_time;
        robot_transport_real_time = nullptr;
    }
}

/*
void KinovaRobot::SubscribeToNotification()
{
    if (!robotIsConnected) {
        return;
    }

    Kinova::Api::Common::NotificationOptions options;
    options.set_type(Kinova::Api::Common::NOTIFICATION_TYPE_EVENT);

    using namespace std::placeholders;

    std::function<void(Kinova::Api::Base::ActionNotification)> actionCallback = std::bind(&KinovaRobot::OnActionNotificationCallBack, this, _1);
    auto handle = robot_base->OnNotificationActionTopic(actionCallback, options);
    robot_NotificationHandleList.push_back(handle);
}

void KinovaRobot::UnsubscribeToNotification()
{
    if (!robotIsConnected) {
        return;
    }
    for (auto handle : robot_NotificationHandleList) {
        robot_base->Unsubscribe(handle);
    }
}
*/

void KinovaRobot::OnError(Kinova::Api::KDetailedException &ex)
{
    auto error_info = ex.getErrorInfo().getError();

    std::cout << ex.what()<< std::endl;
    /*
    ui->MostrarErrores->append("KDetailedoption detectó:" + ex.what());

    ui->MostrarErrores->append("KError error_code: " + error_info_error_code());
    ui->MostrarErrores->append("KError sub_code: " + error_info_error_sub_code());
    ui->MostrarErrores->append("KError sub_string: " + error_info_error_sub_string());

    ui->MostrarErrores->append("Error code string equivalent: " + Kinova::Api::ErrorCodes_Name(Kinova::Api::ErrorCodes(error_info.error_code())));
    ui->MostrarErrores->append("Error sub_code string equivalent: " + Kinova::Api::SubErrorCodes_Name(Kinova::Api::SubErrorCodes(error_info.error_sub_code())));
*/
}

void KinovaRobot::OnActionNotificationCallBack(Kinova::Api::Base::ActionNotification &notif)
{
    switch (notif.action_event())
    {
    case Kinova::Api::Base::ACTION_START:
    {
        robot_ocupado = true;

        break;
    }
    case Kinova::Api::Base::ACTION_END:
    {
        robot_ocupado = false;

        break;
    }
    case Kinova::Api::Base::ACTION_ABORT:
    {
        robot_ocupado = false;

        break;
    }
    case Kinova::Api::Base::ACTION_PAUSE:
    {
        robot_ocupado = false;

        break;
    }
    default:
        break;
    }
}

bool KinovaRobot::Mover_Alto_Nivel_Accion(const std::string& nombreAccion, Kinova::Api::Base::RequestedActionType& tipoDeAccion)
{
    if (!robotIsConnected || robot_ocupado)
    {
        return false;
    }
    try {
        auto action_list = robot_base->ReadAllActions(tipoDeAccion);
        auto action_handle = Kinova::Api::Base::ActionHandle();
        action_handle.set_identifier(0);
        for (auto action : action_list.action_list())
        {
            if (action.name() == nombreAccion)
            {
                action_handle = action.handle();
            }
        }

        if (action_handle.identifier() == 0)
        {
            return false;
        }
        else {
            robot_base->ExecuteActionFromReference(action_handle);
        }
    }
    catch (Kinova::Api::KDetailedException& ex)
    {
        OnError(ex);
        return false;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    return true;
}

bool KinovaRobot::Esperar_Robot_Movimiento(const int timeout)
{
    if (!robotIsConnected)
    {
        return false;
    }
    int cycle = 0;

    while (robot_ocupado && cycle < timeout)
    {
        cycle++;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    if (cycle > timeout) {
        return false;
    }
    return true;
}

bool KinovaRobot::Stop()
{
    if (!robotIsConnected)
    {
        return false;
    }
    try
    {
        robot_base->Stop();
    }
    catch (Kinova::Api::KDetailedException& ex)
    {
        OnError(ex);
        return false;
    }

    return true;
}

Kinova::Api::BaseCyclic::ActuatorFeedback KinovaRobot::GetActuatorFeedback(const int actIdx) const
{
    if (actIdx >= robot_DoF) {
        return Kinova::Api::BaseCyclic::ActuatorFeedback();
    }
    return robot_feedback.actuators(actIdx);
}

std::vector<float> KinovaRobot::GetJointPosition() const
{
    std::vector<float> positions;
    if (!robotIsConnected)
    {
        return positions;
    }
    for (int i = 0; i < robot_DoF; i++)
    {
        positions.push_back(robot_feedback.actuators(i).position());
    }
    return positions;
}

std::vector<float> KinovaRobot::GetJointVelocities() const
{
    std::vector<float> velocities;
    if (!robotIsConnected)
    {
        return velocities;
    }
    for (int i = 0; i < robot_DoF; i++)
    {
        velocities.push_back(robot_feedback.actuators(i).velocity());
    }
    return velocities;
}

std::vector<float> KinovaRobot::GetJointTorques() const
{
    std::vector<float> torques;
    if (!robotIsConnected)
    {
        return torques;
    }
    for (int i = 0; i < robot_DoF; i++)
    {
        torques.push_back(robot_feedback.actuators(i).torque());
    }
    return torques;
}

bool KinovaRobot::SetCustomData(std::vector<float> data)
{
    if (data.size() == robot_DoF)
    {
        robot_customData = data;
        return true;
    }
    return false;
}

bool KinovaRobot::RefreshFeedback()
{
    if (!robotIsConnected)
    {
        return false;
    }
    try
    {
        auto lambda_fct_callback = [this](const Kinova::Api::Error &err, const Kinova::Api::BaseCyclic::Feedback data)
        {
            OnRefreshFeedbackCallback(err, data);
        };
        robot_base_cyclic->RefreshFeedback_callback(lambda_fct_callback);
    }
    catch (Kinova::Api::KDetailedException& ex)
    {
        OnError(ex);
        return false;
    }
    return true;
}

void KinovaRobot::OnRefreshFeedbackCallback(const Kinova::Api::Error &err, const Kinova::Api::BaseCyclic::Feedback& feedback)
{
    robot_feedback = feedback;

    //Insertar algoritmo de detección de colisiones aqui
    std::vector<float> torques = GetJointTorques();

    if (!robot_customData.empty())
    {
        for (int i = 0; i < robot_DoF; i++)
        {
            if (fabsf(torques[i] - robot_customData[i] > 0.5f)) // este es un algoritmo que detecta colisiones cuando el robot está estatico, si se quiere que se detecten colisiones mientras el robot se mueve se tiene que cambiar la customData por el valor del torque del vector de gravedad + el torque dinamico en el movimiento del robot
            {
                // colision detectada en la articulación i
                break;
            }
        }
    }
}

/* llamada dentro del main
KinovaRobot robot = KinovaRobot(ip_address, username, password, PORT, PORT_REAL_TIME);

if (robot.IsConnected()) {
    robot.SubscribeToNotifications();

    auto tipoDeAccion = Kinova::Api::RequestedActionType();
    tipoDeAccion.set_action_type(Kinova::Api::Base::REACH_JOINT_ANGLES);
    robot.Mover_Alto_Nivel_Accion("Home", tipoDeAccion);
    robot.Esperar_Robot_Movimiento(100000);

    robot.UnsuscribeToNotifications();
}
*/
