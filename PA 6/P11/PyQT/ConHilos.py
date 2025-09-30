from PySide6.QtWidgets import QMainWindow
from Hilos_ui import *
from PySide6.QtCore import QThread, Signal
import sys
import time

class ThreadCounter(QThread):
    count_signal = Signal(int)

    def run(self):
        cont = 0
        for _ in range(100):
            self.count_signal.emit(cont)
            cont += 1
            time.sleep(0.1)

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        self.setWindowTitle("Con Hilos")
        self.pushButton.clicked.connect(self.cuentaHasta100)
        self.hilocontador = ThreadCounter()
        self.hilocontador.count_signal.connect(self.updateUI)
     
    def updateUI(self, cont):
        self.lcdNumber.display(cont)
        self.progressBar.setValue(cont)  
        
    def cuentaHasta100(self):
        self.hilocontador.start()    

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
