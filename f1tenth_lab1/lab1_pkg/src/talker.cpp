#include "lab1_pkg/DrivePublisher.hpp"


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DrivePublisher>("talker");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
