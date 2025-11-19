# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'Camara.ui'
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
        MainWindow.resize(490, 507)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.video = QLabel(self.centralwidget)
        self.video.setObjectName(u"video")
        self.video.setGeometry(QRect(20, 20, 451, 271))
        self.video.setFrameShape(QFrame.Shape.Box)
        self.video.setScaledContents(True)
        self.brillo = QSlider(self.centralwidget)
        self.brillo.setObjectName(u"brillo")
        self.brillo.setGeometry(QRect(20, 320, 451, 25))
        self.brillo.setMinimum(-255)
        self.brillo.setMaximum(255)
        self.brillo.setTracking(True)
        self.brillo.setOrientation(Qt.Orientation.Horizontal)
        self.brillo.setTickPosition(QSlider.TickPosition.TicksBelow)
        self.label = QLabel(self.centralwidget)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(20, 300, 58, 16))
        self.label_2 = QLabel(self.centralwidget)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(20, 350, 58, 16))
        self.label_3 = QLabel(self.centralwidget)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setGeometry(QRect(260, 350, 58, 16))
        self.hmin = QSlider(self.centralwidget)
        self.hmin.setObjectName(u"hmin")
        self.hmin.setGeometry(QRect(20, 370, 211, 25))
        self.hmin.setMinimum(0)
        self.hmin.setMaximum(255)
        self.hmin.setTracking(True)
        self.hmin.setOrientation(Qt.Orientation.Horizontal)
        self.hmin.setTickPosition(QSlider.TickPosition.TicksBelow)
        self.hmax = QSlider(self.centralwidget)
        self.hmax.setObjectName(u"hmax")
        self.hmax.setGeometry(QRect(250, 370, 221, 25))
        self.hmax.setMinimum(0)
        self.hmax.setMaximum(255)
        self.hmax.setValue(255)
        self.hmax.setTracking(True)
        self.hmax.setOrientation(Qt.Orientation.Horizontal)
        self.hmax.setTickPosition(QSlider.TickPosition.TicksBelow)
        self.label_4 = QLabel(self.centralwidget)
        self.label_4.setObjectName(u"label_4")
        self.label_4.setGeometry(QRect(20, 400, 58, 16))
        self.smin = QSlider(self.centralwidget)
        self.smin.setObjectName(u"smin")
        self.smin.setGeometry(QRect(20, 420, 211, 25))
        self.smin.setMinimum(0)
        self.smin.setMaximum(255)
        self.smin.setTracking(True)
        self.smin.setOrientation(Qt.Orientation.Horizontal)
        self.smin.setTickPosition(QSlider.TickPosition.TicksBelow)
        self.label_5 = QLabel(self.centralwidget)
        self.label_5.setObjectName(u"label_5")
        self.label_5.setGeometry(QRect(260, 400, 58, 16))
        self.smax = QSlider(self.centralwidget)
        self.smax.setObjectName(u"smax")
        self.smax.setGeometry(QRect(250, 420, 221, 25))
        self.smax.setMinimum(0)
        self.smax.setMaximum(255)
        self.smax.setValue(255)
        self.smax.setTracking(True)
        self.smax.setOrientation(Qt.Orientation.Horizontal)
        self.smax.setTickPosition(QSlider.TickPosition.TicksBelow)
        self.label_6 = QLabel(self.centralwidget)
        self.label_6.setObjectName(u"label_6")
        self.label_6.setGeometry(QRect(20, 450, 58, 16))
        self.vmin = QSlider(self.centralwidget)
        self.vmin.setObjectName(u"vmin")
        self.vmin.setGeometry(QRect(20, 470, 211, 25))
        self.vmin.setMinimum(0)
        self.vmin.setMaximum(255)
        self.vmin.setTracking(True)
        self.vmin.setOrientation(Qt.Orientation.Horizontal)
        self.vmin.setTickPosition(QSlider.TickPosition.TicksBelow)
        self.label_7 = QLabel(self.centralwidget)
        self.label_7.setObjectName(u"label_7")
        self.label_7.setGeometry(QRect(260, 450, 58, 16))
        self.vmax = QSlider(self.centralwidget)
        self.vmax.setObjectName(u"vmax")
        self.vmax.setGeometry(QRect(250, 470, 221, 25))
        self.vmax.setMinimum(0)
        self.vmax.setMaximum(255)
        self.vmax.setValue(255)
        self.vmax.setTracking(True)
        self.vmax.setOrientation(Qt.Orientation.Horizontal)
        self.vmax.setTickPosition(QSlider.TickPosition.TicksBelow)
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Camara", None))
        self.video.setText("")
        self.label.setText(QCoreApplication.translate("MainWindow", u"Brillo", None))
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"H Min.", None))
        self.label_3.setText(QCoreApplication.translate("MainWindow", u"H Max.", None))
        self.label_4.setText(QCoreApplication.translate("MainWindow", u"S Min.", None))
        self.label_5.setText(QCoreApplication.translate("MainWindow", u"S Max.", None))
        self.label_6.setText(QCoreApplication.translate("MainWindow", u"V Min.", None))
        self.label_7.setText(QCoreApplication.translate("MainWindow", u"V Max.", None))
    # retranslateUi

