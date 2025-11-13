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
        MainWindow.resize(462, 318)
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
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Cachirula XD", None))
        self.imagen.setText("")
    # retranslateUi

