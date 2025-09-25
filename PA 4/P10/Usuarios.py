from PySide6.QtWidgets import QMainWindow, QDialog
from PySide6 import QtWidgets
from Principal_ui import *
from Registro_ui import *
import sys

class Usuario:
    def __init__(self, nombre, correo, tipo):
        self.nombre = nombre
        self.correo = correo
        self.tipo = tipo

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        
        self.lista = []
        
        self.actionSalir.triggered.connect(self.salir)
        self.actionRegistrar.triggered.connect(self.registra_usuario)
    
    def registra_usuario(self):
        ventanita = RegistroUsuario(self)
        ret = ventanita.exec()
        if ret == 1:
            n = ventanita.txtNombre.text()
            c = ventanita.txtCorreo.text()
            t = ventanita.comboTipo.currentText()
            usuario = Usuario(n,c,t)
            self.lista.append(usuario)
            self.mostrar_lista()
            
    def mostrar_lista(self):
        self.tableWidget.setColumnCount(3)
        self.tableWidget.setRowCount(len(self.lista))
        self.tableWidget.setHorizontalHeaderLabels(["Nombre", "Correo", "Tipo de Usuario"])
        fila = 0
        for usuario in self.lista:
            self.tableWidget.setItem(fila, 0, QTableWidgetItem(str(usuario.nombre)))
            self.tableWidget.setItem(fila, 1, QTableWidgetItem(str(usuario.correo)))
            self.tableWidget.setItem(fila, 2, QTableWidgetItem(str(usuario.tipo)))
            fila = fila + 1
    
    def salir(self):
        self.close()

class RegistroUsuario(QDialog, Ui_Dialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setupUi(self)    

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
