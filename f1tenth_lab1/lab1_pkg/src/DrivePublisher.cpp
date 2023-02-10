#include "lab1_pkg/DrivePublisher.hpp"

DrivePublisher::DrivePublisher(const std::string& name) : Node(name)
{
    this->declare_parameter("v", 0.0f);
    this->declare_parameter("d", 0.0f);
    // std::vector<std::string> param_names = {"v", "d"};

    // Do the task each 200ms
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(200),
        std::bind(&DrivePublisher::publish_drive, this));

    // for (auto& param : params)
    // {
    //     RCLCPP_INFO(this->get_logger(), "param name: %s, value: %s",
    //                 param.get_name().c_str(), param.value_to_string().c_str());
    // }

    publisher_ = this->create_publisher<ackermann_msgs::msg::AckermannDriveStamped>("drive", 10);

    // param_callback_handle_ = this->add_on_set_parameters_callback(
    //     std::bind(&DrivePublisher::param_call_back, this, std::placeholders::_1));
}

void DrivePublisher::publish_drive()
{
    // Read parameters
    // std::vector<rclcpp::Parameter> params = this->get_parameters(param_names);
    v_ = this->get_parameter("v").as_double();
    d_ = this->get_parameter("d").as_double();
    // Build message
    ackermann_msgs::msg::AckermannDriveStamped message{};
    message.drive.speed = static_cast<float>(v_);
    message.drive.steering_angle = static_cast<float>(d_); 
    // Publish message
    publisher_->publish(message);
}

rcl_interfaces::msg::SetParametersResult DrivePublisher::param_call_back(const std::vector<rclcpp::Parameter> &params)
{
    rcl_interfaces::msg::SetParametersResult result;
    result.successful = true;
    result.reason = "success";
    // Here update class attributes, do some actions, etc.
    return result;
}