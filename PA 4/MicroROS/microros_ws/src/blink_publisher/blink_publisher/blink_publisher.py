import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32

class BlinkPublisher(Node):

    def __init__(self):
        super().__init__('blink_publisher')
        self.publisher_ = self.create_publisher(Int32, 'blink_topic', 10)
        timer_period = 1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = Int32()
        msg.data = self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: %s' % msg.data)
        if self.i == 0: self.i = 1
        else: self.i = 0

def main(args=None):
    rclpy.init(args=args)
    blink_publisher = BlinkPublisher()
    rclpy.spin(blink_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    blink_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
    
    