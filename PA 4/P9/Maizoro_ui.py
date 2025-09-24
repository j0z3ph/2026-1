# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'Maizoro.ui'
##
## Created by: Qt User Interface Compiler version 6.9.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QFrame, QLabel, QMainWindow,
    QPushButton, QSizePolicy, QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(180, 260)
        MainWindow.setMinimumSize(QSize(180, 260))
        MainWindow.setMaximumSize(QSize(180, 260))
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.pantalla = QLabel(self.centralwidget)
        self.pantalla.setObjectName(u"pantalla")
        self.pantalla.setGeometry(QRect(10, 10, 161, 61))
        font = QFont()
        font.setFamilies([u"Comic Sans MS"])
        font.setPointSize(40)
        self.pantalla.setFont(font)
        self.pantalla.setAutoFillBackground(False)
        self.pantalla.setStyleSheet(u"background-color: rgb(16, 113, 12);")
        self.pantalla.setFrameShape(QFrame.Shape.Box)
        self.pantalla.setAlignment(Qt.AlignmentFlag.AlignRight|Qt.AlignmentFlag.AlignTrailing|Qt.AlignmentFlag.AlignVCenter)
        self.btn7 = QPushButton(self.centralwidget)
        self.btn7.setObjectName(u"btn7")
        self.btn7.setGeometry(QRect(10, 80, 41, 51))
        self.btn8 = QPushButton(self.centralwidget)
        self.btn8.setObjectName(u"btn8")
        self.btn8.setGeometry(QRect(50, 80, 41, 51))
        self.btn9 = QPushButton(self.centralwidget)
        self.btn9.setObjectName(u"btn9")
        self.btn9.setGeometry(QRect(90, 80, 41, 51))
        self.btnMas = QPushButton(self.centralwidget)
        self.btnMas.setObjectName(u"btnMas")
        self.btnMas.setGeometry(QRect(130, 80, 41, 51))
        self.btnMenos = QPushButton(self.centralwidget)
        self.btnMenos.setObjectName(u"btnMenos")
        self.btnMenos.setGeometry(QRect(130, 120, 41, 51))
        self.btn5 = QPushButton(self.centralwidget)
        self.btn5.setObjectName(u"btn5")
        self.btn5.setGeometry(QRect(50, 120, 41, 51))
        self.btn6 = QPushButton(self.centralwidget)
        self.btn6.setObjectName(u"btn6")
        self.btn6.setGeometry(QRect(90, 120, 41, 51))
        self.btn4 = QPushButton(self.centralwidget)
        self.btn4.setObjectName(u"btn4")
        self.btn4.setGeometry(QRect(10, 120, 41, 51))
        self.btnPor = QPushButton(self.centralwidget)
        self.btnPor.setObjectName(u"btnPor")
        self.btnPor.setGeometry(QRect(130, 160, 41, 51))
        self.btn2 = QPushButton(self.centralwidget)
        self.btn2.setObjectName(u"btn2")
        self.btn2.setGeometry(QRect(50, 160, 41, 51))
        self.btn3 = QPushButton(self.centralwidget)
        self.btn3.setObjectName(u"btn3")
        self.btn3.setGeometry(QRect(90, 160, 41, 51))
        self.btn1 = QPushButton(self.centralwidget)
        self.btn1.setObjectName(u"btn1")
        self.btn1.setGeometry(QRect(10, 160, 41, 51))
        self.btnEntre = QPushButton(self.centralwidget)
        self.btnEntre.setObjectName(u"btnEntre")
        self.btnEntre.setGeometry(QRect(130, 200, 41, 51))
        self.btnPunto = QPushButton(self.centralwidget)
        self.btnPunto.setObjectName(u"btnPunto")
        self.btnPunto.setGeometry(QRect(50, 200, 41, 51))
        self.btnIgual = QPushButton(self.centralwidget)
        self.btnIgual.setObjectName(u"btnIgual")
        self.btnIgual.setGeometry(QRect(90, 200, 41, 51))
        self.btn0 = QPushButton(self.centralwidget)
        self.btn0.setObjectName(u"btn0")
        self.btn0.setGeometry(QRect(10, 200, 41, 51))
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"La Maizoro", None))
        self.pantalla.setText(QCoreApplication.translate("MainWindow", u"0", None))
        self.btn7.setText(QCoreApplication.translate("MainWindow", u"7", None))
        self.btn8.setText(QCoreApplication.translate("MainWindow", u"8", None))
        self.btn9.setText(QCoreApplication.translate("MainWindow", u"9", None))
        self.btnMas.setText(QCoreApplication.translate("MainWindow", u"+", None))
        self.btnMenos.setText(QCoreApplication.translate("MainWindow", u"-", None))
        self.btn5.setText(QCoreApplication.translate("MainWindow", u"5", None))
        self.btn6.setText(QCoreApplication.translate("MainWindow", u"6", None))
        self.btn4.setText(QCoreApplication.translate("MainWindow", u"4", None))
        self.btnPor.setText(QCoreApplication.translate("MainWindow", u"x", None))
        self.btn2.setText(QCoreApplication.translate("MainWindow", u"2", None))
        self.btn3.setText(QCoreApplication.translate("MainWindow", u"3", None))
        self.btn1.setText(QCoreApplication.translate("MainWindow", u"1", None))
        self.btnEntre.setText(QCoreApplication.translate("MainWindow", u"/", None))
        self.btnPunto.setText(QCoreApplication.translate("MainWindow", u".", None))
        self.btnIgual.setText(QCoreApplication.translate("MainWindow", u"=", None))
        self.btn0.setText(QCoreApplication.translate("MainWindow", u"0", None))
    # retranslateUi

