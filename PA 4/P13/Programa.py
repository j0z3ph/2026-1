from PySide6.QtWidgets import QMainWindow 
from PySide6 import QtWidgets
from PySide6.QtCore import QThread, Signal
from Puertos_ui import *
import sys
import simplecontroller as sc
import time

class ReadThread(QThread):
    lectura = Signal(float)
    boton = Signal(bool)
    
    def __init__(self, board:sc.Board, port:int, portbtn:int):
        super().__init__()
        self.running_flag = True
        self.esp32 = board
        self.port = port
        self.portbtn = portbtn
        self.esp32.pinMode(port, sc.INPUT)
        self.esp32.pinMode(portbtn, sc.INPUT)
            
    def run(self):
        while self.running_flag:
            value = self.esp32.analogRead(self.port)
            btn = self.esp32.digitalRead(self.portbtn)
            time.sleep(0.1)
            self.lectura.emit(value)
            self.boton.emit(btn)
            
    def stop(self):
        self.running_flag = False
        self.wait()
        

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        self.LED = 2
        self.encendido = False
        self.esp32 = sc.Board("COM4")
        
        self.lecturaHilo = ReadThread(self.esp32, 13, 4)
        self.lecturaHilo.lectura.connect(self.analog_read)
        self.lecturaHilo.boton.connect(self.digital_read)
        self.lecturaHilo.start()
        
        self.pushButton.clicked.connect(self.digital_write)
        self.dial.valueChanged.connect(self.analog_write)
       
    def digital_read(self, value:bool):
        if value:
            self.label.setText("Pushado")
        else:
            self.label.setText("Despushado")
    
    def analog_read(self, value):
        self.progressBar.setValue(value * 100)
     
    def analog_write(self):
        self.esp32.pinMode(self.LED, sc.OUTPUT)
        self.esp32.analogWrite(self.LED, self.dial.value()/100)
        
    def digital_write(self):
        self.esp32.pinMode(self.LED, sc.OUTPUT)
        if(self.encendido):
            self.esp32.digitalWrite(self.LED, False)
            self.encendido = False
            self.pushButton.setText("Prender")
        else:
            self.esp32.digitalWrite(self.LED, True)
            self.encendido = True
            self.pushButton.setText("Apagar")
       
    def closeEvent(self, event):
        self.lecturaHilo.stop()
        self.esp32.close()
        return super().closeEvent(event) 
        
    
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
