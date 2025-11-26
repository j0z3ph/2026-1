from PySide6.QtWidgets import QMainWindow 
from PySide6 import QtWidgets, QtGui
from PySide6.QtCore import QThread, Signal
from Camara_ui import *
import sys
import numpy as np
import cv2

class VideoThread(QThread):
    new_video_frame = Signal(np.ndarray)
    
    def __init__(self):
        super().__init__()
        self.running_flag = True
    
    def run(self):
        self.camara = cv2.VideoCapture(0)
        if self.camara.isOpened():
            while self.running_flag:
                ret, img = self.camara.read()
                if ret:
                    self.new_video_frame.emit(img)
    
    def stop(self):
        self.running_flag = False
        self.wait()
        self.camara.release()

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        
        self.video_hilo = VideoThread()
        self.video_hilo.new_video_frame.connect(self.nueva_imagen)
        self.video_hilo.start()
        
        self.brillo.valueChanged.connect(self.muestra_imagen)
        
        #self.hmin.valueChanged.connect(self.segmentacion)
        #self.hmax.valueChanged.connect(self.segmentacion)
        #self.smin.valueChanged.connect(self.segmentacion)
        #self.smax.valueChanged.connect(self.segmentacion)
        #self.vmin.valueChanged.connect(self.segmentacion)
        #self.vmax.valueChanged.connect(self.segmentacion)
        
    def segmentacion(self):
        hmin = self.hmin.value()
        hmax = self.hmax.value()
        smin = self.smin.value()
        smax = self.smax.value()
        vmin = self.vmin.value()
        vmax = self.vmax.value()
        
        rango_minimo = np.array([hmin, smin, vmin])
        rango_maximo = np.array([hmax, smax, vmax])
        
        hvs_img = cv2.cvtColor(self.cv_image, cv2.COLOR_BGR2HSV)
        mascara = cv2.inRange(hvs_img, rango_minimo, rango_maximo)
        
        cv2.imshow("Mascara", mascara)
        
        mascara = cv2.erode(mascara,cv2.getStructuringElement(cv2.MORPH_CROSS, (11,11)))
        cv2.imshow("Mascara Erosionada", mascara)
        
        mascara = cv2.dilate(mascara,cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (11,11)))
        cv2.imshow("Mascara Dilatada", mascara)
        
        
        self.cv_image = cv2.bitwise_and(self.cv_image, self.cv_image, mask=mascara)
        
        ## Contornos
        contornos, _ =cv2.findContours(mascara, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
        maxArea = 0.0
        cont = 0
        idx = -1
        for contorno in contornos:
            if(cv2.contourArea(contorno) > maxArea):
                maxArea = cv2.contourArea(contorno)
                idx = cont
            cont = cont + 1
        rect = cv2.boundingRect(contornos[idx])
        cv2.rectangle(self.cv_image, rect, (0,255,0), 2)
        
        
        
        self.muestra_imagen()
        
    def muestra_imagen(self):
        nueva_imagen =  np.clip(self.cv_image + [self.brillo.value()], 0, 255).astype('uint8')
        imagen_qt = self.convert_cv_qt(nueva_imagen)
        self.video.setPixmap(imagen_qt)
        
    def nueva_imagen(self, img):
        self.cv_image = img.copy()
        self.segmentacion()
        
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
