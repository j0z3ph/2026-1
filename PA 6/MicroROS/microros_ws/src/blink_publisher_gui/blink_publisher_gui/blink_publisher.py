import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32
from PySide6.QtWidgets import QMainWindow
from PySide6 import QtWidgets
from PySide6.QtCore import QTimer
from blink_publisher_gui.gui.Window_ui import *
import sys

class ROSNode(Node):
    def __init__(self):
        super().__init__('gui_node')
        self.running = True
        self.publisher = self.create_publisher(Int32, 'digital_write_topic', 10)
        
    def publish_message(self, value):
        msg = Int32()
        msg.data = value
        self.publisher.publish(msg)

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        rclpy.init()
        self.ros_node = ROSNode()
        self.value = 0
        self.pushButton.clicked.connect(self.click_button)
        self.subscriber = self.ros_node.create_subscription(Int32,'analog_read_topic', self.update_progress_bar, 10)
        self.timer = QTimer()
        self.timer.timeout.connect(self.timer_subscriber_update)
        self.timer.start(10)
        
    def click_button(self):
        if self.value == 0: 
            self.value = 1
            self.pushButton.setText("Apagar LED")
        else: 
            self.value = 0
            self.pushButton.setText("Encender LED")
            
        self.ros_node.publish_message(self.value)
    
    def timer_subscriber_update(self):
        rclpy.spin_once(self.ros_node, timeout_sec=0)
        self.timer.start(10)
    
    def update_progress_bar(self, value: Int32):
        self.progressBar.setValue(value.data * (100/4095))
        
    def closeEvent(self, event):
        self.ros_node.destroy_node()
        rclpy.shutdown()
        self.timer.stop()
        return super().closeEvent(event)

def main(args=None):
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())

    
if __name__ == "__main__":
    main()    