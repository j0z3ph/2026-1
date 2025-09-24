from PySide6.QtWidgets import QMainWindow
from PySide6 import QtWidgets
from PySide6.QtGui import QKeyEvent
from Maizoro_ui import *
import sys

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        
        self.btn0.clicked.connect(self.boton)
        self.btn1.clicked.connect(self.boton)
        self.btn2.clicked.connect(self.boton)
        self.btn3.clicked.connect(self.boton)
        self.btn4.clicked.connect(self.boton)
        self.btn5.clicked.connect(self.boton)
        self.btn6.clicked.connect(self.boton)
        self.btn7.clicked.connect(self.boton)
        self.btn8.clicked.connect(self.boton)
        self.btn9.clicked.connect(self.boton)

    def keyPressEvent(self, event: QKeyEvent):
        #print(event.key())
        if event.key() >= 48 and event.key() <= 57:
            self.imprime_pantalla(event.key()-48)
        return super().keyPressEvent(event)


    def imprime_pantalla(self, numero):
        valor = int(self.pantalla.text() + str(numero))
        self.pantalla.setText(str(valor))

    def boton(self):
        self.imprime_pantalla(self.sender().text())


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
