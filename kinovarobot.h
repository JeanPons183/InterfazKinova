#ifndef KINOVAROBOT_H
#define KINOVAROBOT_H

#include <string>
#include <vector>

namespace k_api = Kinova::Api;

class KinovaRobot
{
public:
    KinovaRobot(const std::string& ip, const std::string& user, const std::string& pass);
    ~KinovaRobot();

    bool Init();
    void SubscribeToNotification();
    void UnsubscribeToNotification();

protected:
    void OnError(k_api::KDetailedException& ex);
    void OnActionNotificationHandle(k_api::Base::ActionNotification& notif);


protected:
    std::string robot_ip;
    std::string robot_username;
    std::string robot_password;
    bool robotIsConnected;
    std::vector<k_api::Common::NotificationHandle> robot_NotificationHandleList;
    auto transport;
    auto router;
    auto transport_real_time;
    auto router_real_time;
    auto session_manager;
    auto session_manager_real_time;
    auto base;
    auto base_cyclic;
    auto actuator_config;
};


#endif // KINOVAROBOT_H
