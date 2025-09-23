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
        MainWindow.resize(220, 250)
        MainWindow.setMinimumSize(QSize(220, 250))
        MainWindow.setMaximumSize(QSize(220, 250))
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.pantalla = QLabel(self.centralwidget)
        self.pantalla.setObjectName(u"pantalla")
        self.pantalla.setGeometry(QRect(10, 10, 201, 51))
        font = QFont()
        font.setFamilies([u"Comic Sans MS"])
        font.setPointSize(30)
        font.setBold(False)
        font.setItalic(False)
        self.pantalla.setFont(font)
        self.pantalla.setAutoFillBackground(False)
        self.pantalla.setStyleSheet(u"background-color: rgb(0, 158, 240);")
        self.pantalla.setFrameShape(QFrame.Shape.Box)
        self.pantalla.setFrameShadow(QFrame.Shadow.Plain)
        self.pantalla.setLineWidth(2)
        self.pantalla.setAlignment(Qt.AlignmentFlag.AlignRight|Qt.AlignmentFlag.AlignTrailing|Qt.AlignmentFlag.AlignVCenter)
        self.btn7 = QPushButton(self.centralwidget)
        self.btn7.setObjectName(u"btn7")
        self.btn7.setGeometry(QRect(10, 70, 51, 51))
        self.btn8 = QPushButton(self.centralwidget)
        self.btn8.setObjectName(u"btn8")
        self.btn8.setGeometry(QRect(60, 70, 51, 51))
        self.btn9 = QPushButton(self.centralwidget)
        self.btn9.setObjectName(u"btn9")
        self.btn9.setGeometry(QRect(110, 70, 51, 51))
        self.btnDiv = QPushButton(self.centralwidget)
        self.btnDiv.setObjectName(u"btnDiv")
        self.btnDiv.setGeometry(QRect(160, 70, 51, 51))
        self.btn4 = QPushButton(self.centralwidget)
        self.btn4.setObjectName(u"btn4")
        self.btn4.setGeometry(QRect(10, 110, 51, 51))
        self.btn6 = QPushButton(self.centralwidget)
        self.btn6.setObjectName(u"btn6")
        self.btn6.setGeometry(QRect(110, 110, 51, 51))
        self.btn5 = QPushButton(self.centralwidget)
        self.btn5.setObjectName(u"btn5")
        self.btn5.setGeometry(QRect(60, 110, 51, 51))
        self.btnMult = QPushButton(self.centralwidget)
        self.btnMult.setObjectName(u"btnMult")
        self.btnMult.setGeometry(QRect(160, 110, 51, 51))
        self.btn1 = QPushButton(self.centralwidget)
        self.btn1.setObjectName(u"btn1")
        self.btn1.setGeometry(QRect(10, 150, 51, 51))
        self.btn3 = QPushButton(self.centralwidget)
        self.btn3.setObjectName(u"btn3")
        self.btn3.setGeometry(QRect(110, 150, 51, 51))
        self.btn2 = QPushButton(self.centralwidget)
        self.btn2.setObjectName(u"btn2")
        self.btn2.setGeometry(QRect(60, 150, 51, 51))
        self.btnSuma = QPushButton(self.centralwidget)
        self.btnSuma.setObjectName(u"btnSuma")
        self.btnSuma.setGeometry(QRect(160, 150, 51, 51))
        self.btn0 = QPushButton(self.centralwidget)
        self.btn0.setObjectName(u"btn0")
        self.btn0.setGeometry(QRect(10, 190, 51, 51))
        self.btnIgual = QPushButton(self.centralwidget)
        self.btnIgual.setObjectName(u"btnIgual")
        self.btnIgual.setGeometry(QRect(110, 190, 51, 51))
        self.btnPunto = QPushButton(self.centralwidget)
        self.btnPunto.setObjectName(u"btnPunto")
        self.btnPunto.setGeometry(QRect(60, 190, 51, 51))
        self.btnMenos = QPushButton(self.centralwidget)
        self.btnMenos.setObjectName(u"btnMenos")
        self.btnMenos.setGeometry(QRect(160, 190, 51, 51))
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Maizoro", None))
        self.pantalla.setText(QCoreApplication.translate("MainWindow", u"0", None))
        self.btn7.setText(QCoreApplication.translate("MainWindow", u"7", None))
        self.btn8.setText(QCoreApplication.translate("MainWindow", u"8", None))
        self.btn9.setText(QCoreApplication.translate("MainWindow", u"9", None))
        self.btnDiv.setText(QCoreApplication.translate("MainWindow", u"/", None))
        self.btn4.setText(QCoreApplication.translate("MainWindow", u"4", None))
        self.btn6.setText(QCoreApplication.translate("MainWindow", u"6", None))
        self.btn5.setText(QCoreApplication.translate("MainWindow", u"5", None))
        self.btnMult.setText(QCoreApplication.translate("MainWindow", u"X", None))
        self.btn1.setText(QCoreApplication.translate("MainWindow", u"1", None))
        self.btn3.setText(QCoreApplication.translate("MainWindow", u"3", None))
        self.btn2.setText(QCoreApplication.translate("MainWindow", u"2", None))
        self.btnSuma.setText(QCoreApplication.translate("MainWindow", u"+", None))
        self.btn0.setText(QCoreApplication.translate("MainWindow", u"0", None))
        self.btnIgual.setText(QCoreApplication.translate("MainWindow", u"=", None))
        self.btnPunto.setText(QCoreApplication.translate("MainWindow", u".", None))
        self.btnMenos.setText(QCoreApplication.translate("MainWindow", u"-", None))
    # retranslateUi

