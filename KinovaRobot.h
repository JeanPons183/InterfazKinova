#pragma once

class KinovaRobot
{
public:
    KinovaRobot(const std::string& ip, const std::string& user, const std::string& password, unsigned int PORT, unsigned int PORT_REAL_TIME);
    ~KinovaRobot();

    bool Init();                            // Crea el objeto robot
    void Disconnect();                      // Cierra las sesiones y elimina el objeto
    bool IsConnected() { return robotIsConnected;}

    void SubscribeToNotification();
    void UnsubscribeToNotification();

    bool Mover_Alto_Nivel_Accion(const std::string& nombreAccion, Kinova::Api::Base::RequestActionType& accion);
    bool Esperar_Robot_Movimiento(const int timeout);
    bool Stop();

    //bool Ejecutar_Accion(const Kinova::Api::Base::Action& accion);

protected:
    void OnError(k_api::KDetailedException& ex);
    void OnActionNotificationCallBack(k_api::Base::ActionNotification& notif);


protected:

    // Especificaciones del robot
    int robot_Dofs;
    bool robot_ocupado;

    Kinova::Api::Base::Action accion;
    Kinova::Api::ControlConfig::ControlConfigClient* controlConfigClient;

    std::string robot_ip;
    std::string robot_username;
    std::string robot_password;

    unsigned int robot_PORT;
    unsigned int robot_POR_REAL_TIME;

    bool robotIsConnected;
    std::vector<Kinova::Api::Common::NotificationHandle> robot_NotificationHandleList;

    Kinova::Api::TransportClientTcp* transport;
    Kinova::Api:: transport_real_time;
    Kinova::Api:: router_real_time;
    Kinova::Api:: session_manager;
    Kinova::Api:: router;
    Kinova::Api:: session_manager_real_time;
    Kinova::Api:: base;
    Kinova::Api:: base_cyclic;
    Kinova::Api:: actuator_config;
};


#endif // KINOVAROBOT_H


#include "kinovarobot.h"

KinovaRobot::KinovaRobot(const std::string& ip, const std::string& user, const std::string& password, unsigned int PORT, unsigned int PORT_REAL_TIME)
{
    robot_ip = ip;
    robot_username = user;
    robot_password = password;
    robot_PORT = PORT;
    robot_POR_REAL_TIME = PORT_REAL_TIME;
    Init();
}

KinovaRobot::~KinovaRobot()
{
    
    Disconnect();
}

bool KinovaRobot::Init()
{
    // ************************************************************************
    // *************    PASO 1. CONEXIÓN              *************************
    //*************************************************************************

    if (robotIsConnected) {
        Disconnect();
    }

    // * High level communication connection - TCP
    auto error_callback = [](Kinova::Api::KError err) { ui->MostrarErrores->append("_________ callback error _________" + err.toString()) };
    transport = new Kinova::Api::TransportClientTcp();
    router = new Kinova::Api::RouterClient(transport, error_callback);
    transport->connect(robot_ip, robot_PORT);

    if (!transport->connect(robot_ip, robot_PORT)) {
        return false; //failed to connect TCP
    }

    // * Low level communication connection - UDP
    transport_real_time = new Kinova::Api::TransportClientUdp();
    router_real_time = new Kinova::Api::RouterClient(transport_real_time, error_callback);
    transport_real_time->connect(robot_ip, robot_PORT_REAL_TIME);

    if (!transport_real_time->connect(robot_ip, robot_PORT_REAL_TIME)) {
        return false; //failed to connect UDP
    }

    try {
        // Set session data connection information
        session_manager = new Kinova::Api::SessionManager(router);
        session_manager_real_time = new Kinova::Api::SessionManager(router_real_time);

        auto create_session_info = Kinova::Api::Session::CreateSessionInfo();
        create_session_info.set_username(robot_username);
        create_session_info.set_password(robot_password);
        create_session_info.set_session_inactivity_timeout(60000);   // (milliseconds)
        create_session_info.set_connection_inactivity_timeout(2000); // (milliseconds)

        session_manager->CreateSession(create_session_info);
        session_manager_real_time->CreateSession(create_session_info);

        robotIsConnected = true;

        //Acceder a la base del robot
        base = new Kinova::Api::Base::BaseClient(router);
        base_cyclic = new Kinova::Api::BaseCyclic::BaseCyclicClient(router);
        actuator_config = new Kinova::Api:::ActuatorConfig::ActuatorConfigClient(router);

    }
    catch () {
        OnError(ex);
    }
    return true;
}

bool KinovaRobot::Disconnect()
{
    if (robotIsConnected) {
        // Close API session
        //ui->label_EstadoActual->setText("Cerrando sesión con el Robot");
        session_manager->CloseSession();
        session_manager_real_time->CloseSession();

        // Deactivate the router and cleanly disconnect from the transport object
        router->SetActivationStatus(false);
        transport->disconnect();
        router_real_time->SetActivationStatus(false);
        transport_real_time->disconnect();

    }
    // Destroy the API

    robotIsConnected = false;

    if (base != nullptr)
    {
        delete base;
        base = nullptr;
    }
    
    if (base_cyclic != nullptr)
    {
        delete base_cyclic;
        base_cyclic = nullptr;
    }

    if (actuator_config != nullptr)
    {
        delete actuator_config;
        actuator_config = nullptr;
    }

    if (session_manager != nullptr)
    {
        delete session_manager;
        session_manager = nullptr;
    }

    if (session_manager_real_time != nullptr)
    {
        delete session_manager_real_time;
        session_manager_real_time = nullptr;
    }

    if (router != nullptr)
    {
        delete router;
        router = nullptr;
    }

    if (router_real_time != nullptr)
    {
        delete router_real_time;
        router_real_time = nullptr;
    }
    
    if (transport != nullptr)
    {
        delete transport;
        transport = nullptr;
    }
    
    if (transport_real_time != nullptr)
    {
        delete transport_real_time;
        transport_real_time = nullptr;
    }
}

void KinovaRobot::SubscribeToNotification()
{
    if (!robotIsConnected) {
        return;
    }
    k_api::Common::NotificationOptions options;
    options.set_type(k_api::Common::NOTIFICATION_TYPE_EVENT);

    std::function<void(k_api::Base::ActionNotification)> actionCallBack = std::bind(&KinovaRobot::OnActionNotificationCallback, this, _1);
    auto handle = base->OnNotificationActionTopic(actionCallback, options);
    robot_NotificationHandleList.push_back(handle);
}

void KinovaRobot::UnsubscribeToNotification()
{
    if (!robotIsConnected) {
        return;
    }
    for (auto handle : robot_NotificationHandleList) {
        base->Unsubscribe(handle);
    }
}

void KinovaRobot::OnError(Kinova::Api::KDetailedException& ex)
{
    auto error_info = ex.getErrorInfo().getError();
    ui->MostrarErrores->append("KDetailedoption detectó:" + ex.what());

    ui->MostrarErrores->append("KError error_code: " + error_info_error_code());
    ui->MostrarErrores->append("KError sub_code: " + error_info_error_sub_code());
    ui->MostrarErrores->append("KError sub_string: " + error_info_error_sub_string());

    ui->MostrarErrores->append("Error code string equivalent: " + Kinova::Api::ErrorCodes_Name(k_api::ErrorCodes(error_info.error_code())));
    ui->MostrarErrores->append("Error sub_code string equivalent: " + Kinova::Api::SubErrorCodes_Name(k_api::SubErrorCodes(error_info.error_sub_code())));

}

void KinovaRobot::OnActionNotificationCallBack(Kinova::Api::Base::ActionNotification& notif)
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

bool KinovaRobot::Mover_Alto_Nivel_Accion(const std::string& nombreAccion, Kinova::Api::Base::RequestActionType& tipoDeAccion)
{
    if (robotIsConnected || robot_ocupado)
    {
        return false;
    }
    try {
        auto action_list = base->ReadAllActions(tipoDeAccion);
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
            base->ExecuteActionFromReference(action_handle);
        }
    }
    catch (Kinova::Api::KDetailedException& ex)
    {
        OnError(ex);
    }
    std::this_thread::sleep_for(tiempe std::chrono::miliseconds(_val 500));

    return true;
}

bool KinovaRobot::Esperar_Robot_Movimiento(const int timeout)
{
    if (robotIsConnected)
    {
        return false;
    }
    int cycle = 0;

    while (robot_ocupado && cycle < timeout) 
    {
        cycle++;
        std::this_thread::sleep_for(tiempe std::chrono::miliseconds(_val 10));
    }
    if (cycle > timeout) {
        return false;
    }
    return true;
}

bool KinovaRobot::Stop()
{
    if (robotIsConnected)
    {
        return false;
    }
    try 
    {
        base->Stop();
    }
    catch (Kinova::Api::KDetailedException& ex)
    {
        OnError(ex);
    }

    return true;
}

KinovaRobot robot = KinovaRobot(ip_address, username, password, PORT, PORT_REAL_TIME);

if (robot.IsConnected()) {
    robot.SubscribeToNotifications();

    auto tipoDeAccion = Kinova::Api::RequestedActionType();
    tipoDeAccion.set_action_type(Kinova::Api::Base::REACH_JOINT_ANGLES);
    robot.Mover_Alto_Nivel_Accion("Home", tipoDeAccion);
    robot.Esperar_Robot_Movimiento(100000);

    robot.UnsuscribeToNotifications();
}
