from PySide6.QtWidgets import QMainWindow 
from PySide6 import QtWidgets, QtGui
from untitled_ui import *
import sys
import cv2
import numpy as np

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        self.cachi = cv2.imread("cachirula.jpg")
        self.imagen.setPixmap(self.convert_cv_qt(self.cachi))
        self.brisho.valueChanged.connect(self.cambia_brisho)
        
    def cambia_brisho(self):
        im2 = np.clip(self.cachi.astype('int32') + self.brisho.value(), 0, 255).astype('uint8')
        self.imagen.setPixmap(self.convert_cv_qt(im2))
        
    def convert_cv_qt(self, cv_img):
        rgb_image = cv2.cvtColor(cv_img, cv2.COLOR_BGR2RGB)
        h, w, ch = rgb_image.shape
        bytes_per_line = ch * w
        converted_image = QtGui.QImage(rgb_image.data, w, h, bytes_per_line, QtGui.QImage.Format.Format_RGB888)
        return QtGui.QPixmap.fromImage(converted_image)
    
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
