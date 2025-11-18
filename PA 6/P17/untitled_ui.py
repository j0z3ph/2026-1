# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'untitled.ui'
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
    QSizePolicy, QSlider, QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(730, 308)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.imagen = QLabel(self.centralwidget)
        self.imagen.setObjectName(u"imagen")
        self.imagen.setGeometry(QRect(20, 10, 421, 251))
        self.imagen.setFrameShape(QFrame.Shape.Box)
        self.imagen.setScaledContents(True)
        self.brisho = QSlider(self.centralwidget)
        self.brisho.setObjectName(u"brisho")
        self.brisho.setGeometry(QRect(20, 264, 421, 41))
        self.brisho.setMinimum(-255)
        self.brisho.setMaximum(255)
        self.brisho.setOrientation(Qt.Orientation.Horizontal)
        self.brisho.setTickPosition(QSlider.TickPosition.TicksAbove)
        self.brisho.setTickInterval(15)
        self.HMin = QSlider(self.centralwidget)
        self.HMin.setObjectName(u"HMin")
        self.HMin.setGeometry(QRect(470, 30, 111, 25))
        self.HMin.setMaximum(255)
        self.HMin.setOrientation(Qt.Orientation.Horizontal)
        self.HMin.setTickPosition(QSlider.TickPosition.TicksAbove)
        self.HMin.setTickInterval(20)
        self.HMax = QSlider(self.centralwidget)
        self.HMax.setObjectName(u"HMax")
        self.HMax.setGeometry(QRect(600, 30, 111, 25))
        self.HMax.setMaximum(255)
        self.HMax.setValue(255)
        self.HMax.setOrientation(Qt.Orientation.Horizontal)
        self.HMax.setTickPosition(QSlider.TickPosition.TicksAbove)
        self.HMax.setTickInterval(20)
        self.label = QLabel(self.centralwidget)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(480, 10, 58, 16))
        self.label_2 = QLabel(self.centralwidget)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(610, 10, 58, 16))
        self.label_3 = QLabel(self.centralwidget)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setGeometry(QRect(480, 60, 58, 16))
        self.SMin = QSlider(self.centralwidget)
        self.SMin.setObjectName(u"SMin")
        self.SMin.setGeometry(QRect(470, 80, 111, 25))
        self.SMin.setMaximum(255)
        self.SMin.setOrientation(Qt.Orientation.Horizontal)
        self.SMin.setTickPosition(QSlider.TickPosition.TicksAbove)
        self.SMin.setTickInterval(20)
        self.SMax = QSlider(self.centralwidget)
        self.SMax.setObjectName(u"SMax")
        self.SMax.setGeometry(QRect(600, 80, 111, 25))
        self.SMax.setMaximum(255)
        self.SMax.setValue(255)
        self.SMax.setOrientation(Qt.Orientation.Horizontal)
        self.SMax.setTickPosition(QSlider.TickPosition.TicksAbove)
        self.SMax.setTickInterval(20)
        self.label_4 = QLabel(self.centralwidget)
        self.label_4.setObjectName(u"label_4")
        self.label_4.setGeometry(QRect(610, 60, 58, 16))
        self.label_5 = QLabel(self.centralwidget)
        self.label_5.setObjectName(u"label_5")
        self.label_5.setGeometry(QRect(480, 110, 58, 16))
        self.VMin = QSlider(self.centralwidget)
        self.VMin.setObjectName(u"VMin")
        self.VMin.setGeometry(QRect(470, 130, 111, 25))
        self.VMin.setMaximum(255)
        self.VMin.setOrientation(Qt.Orientation.Horizontal)
        self.VMin.setTickPosition(QSlider.TickPosition.TicksAbove)
        self.VMin.setTickInterval(20)
        self.VMax = QSlider(self.centralwidget)
        self.VMax.setObjectName(u"VMax")
        self.VMax.setGeometry(QRect(600, 130, 111, 25))
        self.VMax.setMaximum(255)
        self.VMax.setValue(255)
        self.VMax.setOrientation(Qt.Orientation.Horizontal)
        self.VMax.setTickPosition(QSlider.TickPosition.TicksAbove)
        self.VMax.setTickInterval(20)
        self.label_6 = QLabel(self.centralwidget)
        self.label_6.setObjectName(u"label_6")
        self.label_6.setGeometry(QRect(610, 110, 58, 16))
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Segmentacion de Colores", None))
        self.imagen.setText("")
        self.label.setText(QCoreApplication.translate("MainWindow", u"H Min.", None))
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"H Max.", None))
        self.label_3.setText(QCoreApplication.translate("MainWindow", u"S Min.", None))
        self.label_4.setText(QCoreApplication.translate("MainWindow", u"S Max.", None))
        self.label_5.setText(QCoreApplication.translate("MainWindow", u"V Min.", None))
        self.label_6.setText(QCoreApplication.translate("MainWindow", u"V Max.", None))
    # retranslateUi

