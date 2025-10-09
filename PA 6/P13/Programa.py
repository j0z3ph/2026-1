from PySide6.QtWidgets import QMainWindow 
from PySide6 import QtWidgets
from PySide6.QtCore import QThread, Signal
from Puertos_ui import *
import sys
import simplecontroller as sc
import time

class ReadThread(QThread):
    analog_value = Signal(float)
    digital_value = Signal(bool)
    
    def __init__(self, board:sc.Board, pin:int, pin_digital:int):
        super().__init__()
        self.running_flag = True
        self.esp32 = board
        self.pin = pin
        self.pin_digital = pin_digital
        self.esp32.pinMode(pin, sc.INPUT)
        self.esp32.pinMode(pin_digital, sc.INPUT)
        
    
    def run(self):
        while self.running_flag:
            value = self.esp32.analogRead(self.pin)
            btn = self.esp32.digitalRead(self.pin_digital)
            self.analog_value.emit(value)
            self.digital_value.emit(btn)
            time.sleep(0.1)
            
    def stop(self):
        self.running_flag = False
        self.wait()
            


class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        self.prendido = False
        self.LED = 2
        
        self.esp32 = sc.Board("COM4")
        
        self.hilo = ReadThread(self.esp32, 13, 15)
        self.hilo.analog_value.connect(self.analog_read)
        self.hilo.digital_value.connect(self.digital_read)
        
        self.hilo.start()
        
        
        self.pushButton.clicked.connect(self.digital_write)
        
        self.dial.valueChanged.connect(self.analog_write)
    
    def digital_read(self, value):
        if value:
            self.label.setText("Pushado")
        else:
            self.label.setText("Des Pushado")
    
    def analog_read(self, value):
        self.progressBar.setValue(value * 100)
        
    def analog_write(self):
        self.esp32.pinMode(self.LED, sc.OUTPUT)
        self.esp32.analogWrite(self.LED, self.dial.value() / 100)
        
    def digital_write(self):
        self.esp32.pinMode(self.LED, sc.OUTPUT)
        if(self.prendido):
            self.esp32.digitalWrite(self.LED, False)
            self.prendido = False
            self.pushButton.setText("Encender")
        else:
            self.esp32.digitalWrite(self.LED, True)
            self.prendido = True
            self.pushButton.setText("Apagar")
            
    def closeEvent(self, event):
        self.esp32.close()
        self.hilo.stop()
        return super().closeEvent(event)
    
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
