from PySide6.QtWidgets import QMainWindow 
from PySide6 import QtWidgets, QtGui
from PySide6.QtCore import QThread, Signal
from untitled_ui import *
import sys
import cv2
import numpy as np

class VideoThread(QThread):
    newframe = Signal(np.ndarray)
    
    def __init__(self):
        super().__init__()
        self.running = True
    
    def run(self):
        self.camara = cv2.VideoCapture(0)
        if self.camara.isOpened():
            while self.running:
                ret, img = self.camara.read()
                if ret:
                    self.newframe.emit(img)
                #time.sleep(0.1) 
    
    def stop(self):
        self.running = False
        self.wait()       
        self.camara.release()
            

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        
        self.video_hilo = VideoThread()
        self.video_hilo.newframe.connect(self.update_img)
        self.video_hilo.start()
        
        self.brisho.valueChanged.connect(self.cambia_brisho)
        
    def update_img(self, img):
        self.cachi = img
        
        img_hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
        hmin = self.HMin.value()
        hmax = self.HMax.value()
        smin = self.SMin.value()
        smax = self.SMax.value()
        vmin = self.VMin.value()
        vmax = self.VMax.value()
        
        rango_min = np.array([hmin, smin, vmin])
        rango_max = np.array([hmax, smax, vmax])
        
        mascara = cv2.inRange(img_hsv, rango_min, rango_max)
        
        #cv2.imshow("Mascara", mascara)
        self.cachi = cv2.bitwise_and(img, img, mask=mascara)
        
        contornos, _ = cv2.findContours(mascara, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE )
        
        area_max = 0.0
        idx = -1
        cont = 0
        for contorno in contornos:
            if cv2.contourArea(contorno) > area_max:
                area_max = cv2.contourArea(contorno)
                idx = cont
            cont = cont + 1
        
        if idx >= 0:
            rect = cv2.boundingRect(contornos[idx])
            cv2.rectangle(self.cachi, rect, (0, 255, 0), 3)
        
        #for contorno in contornos:
        #    rect = cv2.boundingRect(contorno)
        #    cv2.rectangle(self.cachi, rect, (0, 255, 0), 3)
        
        self.cambia_brisho()
        
    def cambia_brisho(self):
        im2 = np.clip(self.cachi.astype('int32') + self.brisho.value(), 0, 255).astype('uint8')
        self.imagen.setPixmap(self.convert_cv_qt(im2))
            
    def convert_cv_qt(self, cv_img):
        rgb_image = cv2.cvtColor(cv_img, cv2.COLOR_BGR2RGB)
        h, w, ch = rgb_image.shape
        bytes_per_line = ch * w
        converted_image = QtGui.QImage(rgb_image.data, w, h, bytes_per_line, QtGui.QImage.Format.Format_RGB888)
        return QtGui.QPixmap.fromImage(converted_image)
    
    def closeEvent(self, event):
        self.video_hilo.stop()
        return super().closeEvent(event)
    
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
