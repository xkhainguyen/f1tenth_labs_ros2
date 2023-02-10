#ifndef DRIVEPUBLISHER_HPP
#define DRIVEPUBLISHER_HPP

#include <chrono>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "ackermann_msgs/msg/ackermann_drive_stamped.hpp"
#include "rcl_interfaces/msg/set_parameters_result.hpp"

class DrivePublisher : public rclcpp::Node
{
public:
    DrivePublisher(const std::string& name);
    rcl_interfaces::msg::SetParametersResult param_call_back(const std::vector<rclcpp::Parameter> &params);

private:
    rclcpp::Publisher<ackermann_msgs::msg::AckermannDriveStamped>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    OnSetParametersCallbackHandle::SharedPtr param_callback_handle_;
    double v_;
    double d_;
    void publish_drive();
};

#endif
