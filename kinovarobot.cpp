#include "kinovarobot.h"

KinovaRobot::KinovaRobot()
{

}

KinovaRobot::KinovaRobot(const std::string &ip, const std::string &user, const std::string &pass)
{
    ip_address=
}

KinovaRobot::~KinovaRobot()
{
    if(robotIsConnected){
        // Close API session
        ui->label_EstadoActual->setText("Cerrando sesión con el Robot");
        session_manager->CloseSession();
        session_manager_real_time->CloseSession();

        // Deactivate the router and cleanly disconnect from the transport object
        router->SetActivationStatus(false);
        transport->disconnect();
        router_real_time->SetActivationStatus(false);
        transport_real_time->disconnect();

    }
    // Destroy the API

    delete base;
    delete base_cyclic;
    delete actuator_config;
    delete session_manager;
    delete session_manager_real_time;
    delete router;
    delete router_real_time;
    delete transport;
    delete transport_real_time;

}

bool KinovaRobot::Init()
{
    // ************************************************************************
    // *************    PASO 1. CONEXIÓN              *************************
    //*************************************************************************

    // * High level communication connection - TCP
    auto error_callback = [](k_api::KError err){ ui->MostrarErrores->append("_________ callback error _________" + err.toString()) };
    transport = new k_api::TransportClientTcp();
    router = new k_api::RouterClient(transport, error_callback);
    transport->connect(ip_address, PORT);

    if(!transport->connect(ip_address, PORT)){
        return false; //failed to connect TCP
    }

    // * Low level communication connection - UDP
    transport_real_time = new k_api::TransportClientUdp();
    router_real_time = new k_api::RouterClient(transport_real_time, error_callback);
    transport_real_time->connect(robot_ip, PORT_REAL_TIME);

    if(!transport_real_time->connect(ip_address, PORT_REAL_TIME)){
        return false; //failed to connect UDP
    }

    try{
        // Set session data connection information
        session_manager = new k_api::SessionManager(router);
        session_manager_real_time = new k_api::SessionManager(router_real_time);

        auto create_session_info = k_api::Session::CreateSessionInfo();
        create_session_info.set_username(username);
        create_session_info.set_password(password);
        create_session_info.set_session_inactivity_timeout(60000);   // (milliseconds)
        create_session_info.set_connection_inactivity_timeout(2000); // (milliseconds)

        session_manager->CreateSession(create_session_info);
        session_manager_real_time->CreateSession(create_session_info);

        robotIsConnected=true;

        //Acceder a la base del robot
        base = new k_api::Base::BaseClient(router);
        base_cyclic = new k_api::BaseCyclic::BaseCyclicClient(router);
        actuator_config = new k_api::ActuatorConfig::ActuatorConfigClient(router);
    }catch(){
        OnError(ex);
    }
    return true;
}

void KinovaRobot::SubscribeToNotification()
{
    if(!robotIsConnected){
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
    if(!robotIsConnected){
        return;
    }
    for(auto handle:robot_NotificationHandleList){
        base->Unsubscribe(handle);
    }
}

void KinovaRobot::OnError(k_api::KDetailedException &ex)
{
    auto error_info = ex.getErrorInfo().getError();
    ui->MostrarErrores->append("KDetailedoption detectó:" + ex.what());

    ui->MostrarErrores->append("KError error_code: " + error_info_error_code());
    ui->MostrarErrores->append("KError sub_code: " + error_info_error_sub_code());
    ui->MostrarErrores->append("KError sub_string: " + error_info_error_sub_string());

    ui->MostrarErrores->append("Error code string equivalent: " + k_api::ErrorCodes_Name(k_api::ErrorCodes(error_info.error_code())));
    ui->MostrarErrores->append("Error sub_code string equivalent: " + k_api::SubErrorCodes_Name(k_api::SubErrorCodes(error_info.error_sub_code())));

}

void KinovaRobot::OnActionNotificationHandle(k_api::Base::ActionNotification &notif)
{

}
