from PySide6.QtWidgets import QMainWindow, QMessageBox
from PySide6 import QtWidgets
from Ventana_ui import *
import sys

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        
        # Evento clic
        self.btnAceptar.clicked.connect(self.boton_cliqueado)
    
    def boton_cliqueado(self):
        QMessageBox.information(self, "Mensajito", self.txtEntrada.text())
        self.txtEntrada.setText("")
    
    
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
