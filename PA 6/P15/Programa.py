import socket
from PySide6.QtWidgets import QMainWindow 
from PySide6 import QtWidgets
from PySide6.QtCore import QThread, Signal
from Puertos_ui import *
import sys
import time

class ThreadSocket(QThread):
    global connected
    analog_read = Signal(int)
    def __init__(self, host, port):
        global connected
        super().__init__()
        server.connect((host, port))
        connected = True
        
    def run(self):
        global connected
        try:
            while connected:
                message = server.recv(BUFFER_SIZE).decode("utf-8")
                if message:
                    try:
                        if message.startswith('<analog_read>'):
                            valor = int(message.removeprefix('<analog_read>'))
                            self.analog_read.emit(valor)
                    except ValueError:
                        pass
        except ...:
            pass
        finally:
            server.close()
            connected = False
        
    def stop(self):
        global connected
        connected = False
        self.wait()


class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        self.prendido = False
        
        
        self.hilo = ThreadSocket('3.149.222.108', 80)
        self.hilo.analog_read.connect(self.analog_read)
        #self.hilo.digital_value.connect(self.digital_read)
        
        self.hilo.start()
        
        
        self.pushButton.clicked.connect(self.digital_write)
        
        self.dial.valueChanged.connect(self.analog_write)
    
    def digital_read(self, value):
        if value:
            self.label.setText("Pushado")
        else:
            self.label.setText("Des Pushado")
    
    def analog_read(self, value):
        self.progressBar.setValue(value * (100/4095))
        
    def analog_write(self):
        valor = self.dial.value()
        server.send(bytes('<analog_write>' + str(valor), 'utf-8'))
        
    def digital_write(self):
        if(self.prendido):
            server.send(bytes('<digital_write>off', 'utf-8'))    
            self.prendido = False
            self.pushButton.setText("Encender")
        else:
            server.send(bytes('<digital_write>on', 'utf-8'))    
            self.prendido = True
            self.pushButton.setText("Apagar")
            
    def closeEvent(self, event):
        self.hilo.stop()
        return super().closeEvent(event)
    
if __name__ == "__main__":
    BUFFER_SIZE = 1024  # Usamos un número pequeño para tener una respuesta rápida
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    connected = False
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
