#ifndef KINOVAROBOT_H
#define KINOVAROBOT_H

//function headers
#include <array>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>
#include <numeric>

// Kinova Headers
#include <KDetailedException.h>
#include <BaseClientRpc.h>
#include <BaseCyclicClientRpc.h>
#include <ActuatorConfigClientRpc.h>
#include <SessionClientRpc.h>
#include <SessionManager.h>
#include <RouterClient.h>
#include <TransportClientUdp.h>
#include <TransportClientTcp.h>
#include <DeviceManagerClientRpc.h>
#include <DeviceConfigClientRpc.h>
#include <ControlConfigClientRpc.h>
#include <Common.pb.h>
#include <argh.h>
#include <google/protobuf/util/json_util.h>

// Time count / managment
#if defined(_MSC_VER)
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <time.h>


class KinovaRobot
{
public:

    KinovaRobot(const std::string& ip, const std::string& user, const std::string& password, unsigned int PORT, unsigned int PORT_REAL_TIME);   //Contructor
    ~KinovaRobot(); //Destructor

    bool Init();                            // Crea el objeto robot
    void Disconnect();                      // Cierra las sesiones y elimina el objeto

    //void SubscribeToNotification();
    //void UnsubscribeToNotification();

    //Getters
    bool                                        IsConnected() { return robotIsConnected;}
    int                                         GetNDoF() const { return robot_DoF;}
    Kinova::Api::BaseCyclic::Feedback           GetFeedback() const { return robot_feedback;}
    Kinova::Api::BaseCyclic::ActuatorFeedback   GetActuatorFeedback(const int actIdx) const;
    std::vector<float>                          GetJointPosition() const;
    std::vector<float>                          GetJointVelocities() const;
    std::vector<float>                          GetJointTorques() const;

    bool RefreshFeedback();
    bool SetCustomData(std::vector<float> data);

    //Accion a alto nivel
    bool Mover_Alto_Nivel_Accion(const std::string& nombreAccion, Kinova::Api::Base::RequestedActionType &tipoDeAccion);

    bool Esperar_Robot_Movimiento(const int timeout);   //Esperar al robot
    bool Stop();    //Funcion Stop de la API manda un twist command com velocidades 0 a todos los actuadores, esta acción tiene prioridad a cualquier otro comando a los actuadores. (No usar)



protected:
    void OnError(Kinova::Api::KDetailedException& ex);
    void OnActionNotificationCallBack(Kinova::Api::Base::ActionNotification& notif);
    void OnRefreshFeedbackCallback(const Kinova::Api::Error& err, const Kinova::Api::BaseCyclic::Feedback& feedback);

protected:
    // Especificaciones del robot
    int robot_DoF;
    bool robot_ocupado;


    Kinova::Api::Base::Action robot_accion;

    std::string robot_ip;
    std::string robot_username;
    std::string robot_password;


    unsigned int robot_PORT;
    unsigned int robot_PORT_REAL_TIME;

    bool robotIsConnected;

    Kinova::Api::Error err;
    std::vector<Kinova::Api::Common::NotificationHandle> robot_NotificationHandleList;
    std::vector<float> robot_customData;

    Kinova::Api::TransportClientTcp* robot_transport;
    Kinova::Api::TransportClientUdp* robot_transport_real_time;

    Kinova::Api::RouterClient* robot_router;
    Kinova::Api::RouterClient* robot_router_real_time;

    Kinova::Api::SessionManager* robot_session_manager;
    Kinova::Api::SessionManager* robot_session_manager_real_time;

    Kinova::Api::ActuatorConfig::ActuatorConfigClient* robot_actuator_config;
    Kinova::Api::DeviceConfig::DeviceConfigClient* robot_deviceConfigClient;
    Kinova::Api::ControlConfig::ControlConfigClient* robot_controlConfigClient;

    Kinova::Api::Base::BaseClient* robot_base;
    Kinova::Api::BaseCyclic::BaseCyclicClient* robot_base_cyclic;
    Kinova::Api::BaseCyclic::Feedback robot_feedback;

};


#endif // KINOVAROBOT_H

