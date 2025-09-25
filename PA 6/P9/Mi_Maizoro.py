from PySide6.QtWidgets import QMainWindow 
from PySide6 import QtWidgets
from PySide6.QtGui import QKeyEvent
from Maizoro_ui import *
import sys

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        
        self.btn0.clicked.connect(self.boton_numerico)
        self.btn1.clicked.connect(self.boton_numerico)
        self.btn2.clicked.connect(self.boton_numerico)
        self.btn3.clicked.connect(self.boton_numerico)
        self.btn4.clicked.connect(self.boton_numerico)
        self.btn5.clicked.connect(self.boton_numerico)
        self.btn6.clicked.connect(self.boton_numerico)
        self.btn7.clicked.connect(self.boton_numerico)
        self.btn8.clicked.connect(self.boton_numerico)
        self.btn9.clicked.connect(self.boton_numerico)
        
        
    def keyPressEvent(self, event: QKeyEvent):
        #print(event.key())
        if event.key() >= 48 and event.key() <= 57:
             self.imprime_numero(event.key() - 48)
        return super().keyPressEvent(event)
    
    def imprime_numero(self, numero):
        valor = self.pantalla.text()
        valor = int(valor + str(numero))
        self.pantalla.setText(str(valor))
    
    def boton_numerico(self):
        self.imprime_numero(self.sender().text())
        
    
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
