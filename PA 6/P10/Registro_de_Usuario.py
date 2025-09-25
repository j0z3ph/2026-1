from PySide6.QtWidgets import QMainWindow 
from PySide6 import QtWidgets
from Ventana_Principal_ui import *
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
        self.actionRegistrar_usuario.triggered.connect(self.registra_usuario)
        
    def registra_usuario(self):
        ventana = RegistroUsuario(self)
        var = ventana.exec()
        if var == 1:
            n = ventana.txtNombre.text()
            c = ventana.txtCorreo.text()
            t = ventana.comboBox.currentText()
            
            usuario = Usuario(n, c, t)
            self.lista.append(usuario)
            self.mostrar_usuarios()
            
    def mostrar_usuarios(self):
        self.tablaUsuarios.setColumnCount(3)
        self.tablaUsuarios.setRowCount(len(self.lista))
        
        self.tablaUsuarios.setHorizontalHeaderLabels(["Nombre del Usuario", "Correo", "Tipo de Usuario"])
        
        cont = 0
        for usuario in self.lista:
            self.tablaUsuarios.setItem(cont, 0, QTableWidgetItem(usuario.nombre))
            self.tablaUsuarios.setItem(cont, 1, QTableWidgetItem(usuario.correo))
            self.tablaUsuarios.setItem(cont, 2, QTableWidgetItem(usuario.tipo))
            cont = cont + 1
        
    def salir(self):
        self.close()
        
class RegistroUsuario(QDialog, Ui_Dialog):
    def __init__(self, parent):
        super().__init__(parent)
        self.setupUi(self)
    
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
