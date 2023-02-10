#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

# from std_msgs.msg import String
from ackermann_msgs.msg import AckermannDriveStamped

class RelaySubscriber(Node):

    def __init__(self, name):
        super().__init__(name)
        self.subscription = self.create_subscription(
            AckermannDriveStamped,
            'drive',
            self.listener_callback,
            10)
        # self.subscription  # prevent unused variable warning
        self.publisher = self.create_publisher(
            AckermannDriveStamped,
            "drive_relay",
            10
        )

    def listener_callback(self, msg):
        # self.get_logger().info('I heard: "%s"' % msg.data)
        relay_msg = AckermannDriveStamped()
        relay_msg.drive.speed =  msg.drive.speed * 3
        relay_msg.drive.steering_angle = msg.drive.steering_angle * 3
        self.publisher.publish(relay_msg)

def main(args=None):
    rclpy.init(args=args)
    node = RelaySubscriber("relay")
    rclpy.spin(node)
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()