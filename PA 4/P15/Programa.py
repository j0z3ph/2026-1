from PySide6.QtWidgets import QMainWindow 
from PySide6 import QtWidgets
from PySide6.QtCore import QThread, Signal
from Puertos_ui import *
import sys
import socket

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
                try:
                    if message:
                        if message.startswith("<analog_read>"):
                            valor = int(message.removeprefix("<analog_read>"))
                            self.analog_read.emit(valor)
                    else:
                        break
                except ValueError:
                    pass
                
        except ...:
            self.signal_message.emit("<!!error!!>")
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
        
        self.encendido = False
        self.lecturaHilo = ThreadSocket("3.149.222.108", 80)
        self.lecturaHilo.analog_read.connect(self.analog_read)
        #self.lecturaHilo.boton.connect(self.digital_read)
        self.lecturaHilo.start()
        
        self.pushButton.clicked.connect(self.digital_write)
        self.dial.valueChanged.connect(self.analog_write)
       
    def digital_read(self, value:bool):
        if value:
            self.label.setText("Pushado")
        else:
            self.label.setText("Despushado")
    
    def analog_read(self, value):
        self.progressBar.setValue(value * (100/4096))
     
    def analog_write(self):
        valor = self.dial.value()
        server.send(bytes('<analog_write>' + str(valor)+'\n', 'utf-8'))
        
    def digital_write(self):
        if(self.encendido):
            server.send(bytes('<digital_write>off\n', 'utf-8'))
            self.encendido = False
            self.pushButton.setText("Prender")
        else:
            server.send(bytes('<digital_write>on\n', 'utf-8'))
            self.encendido = True
            self.pushButton.setText("Apagar")
       
    def closeEvent(self, event):
        self.lecturaHilo.stop()
        return super().closeEvent(event) 
        
    
if __name__ == "__main__":
    BUFFER_SIZE = 1024  # Usamos un número pequeño para tener una respuesta rápida
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    connected = False
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
