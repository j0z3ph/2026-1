from PySide6.QtWidgets import QMainWindow 
from PySide6 import QtWidgets
from PySide6.QtGui import QKeyEvent
from Maizoro_ui import *
import sys

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        
        self.btn1.clicked.connect(self.boton_numerico)
        
    def keyPressEvent(self, event: QKeyEvent):
        print(event.key())
        if event.key() >= 48 and event.key() <= 57:
             self.imprime_numero(event.key() - 48)
        return super().keyPressEvent(event)
    
    def imprime_numero(self, numero):
        valor = self.pantalla.text()
        valor = int(valor + str(numero))
        self.pantalla.setText(str(valor))
    
    def boton_numerico(self):
        valor = self.pantalla.text()
        valor = int(valor + "1")
        self.pantalla.setText(str(valor))
        
    
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
