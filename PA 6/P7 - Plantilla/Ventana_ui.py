# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'Ventana.ui'
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
from PySide6.QtWidgets import (QApplication, QLabel, QLineEdit, QMainWindow,
    QPushButton, QSizePolicy, QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(404, 291)
        MainWindow.setMinimumSize(QSize(404, 291))
        MainWindow.setMaximumSize(QSize(404, 291))
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.imagen = QLabel(self.centralwidget)
        self.imagen.setObjectName(u"imagen")
        self.imagen.setGeometry(QRect(30, 20, 181, 251))
        self.imagen.setPixmap(QPixmap(u"images.jpeg"))
        self.imagen.setScaledContents(True)
        self.txtEntrada = QLineEdit(self.centralwidget)
        self.txtEntrada.setObjectName(u"txtEntrada")
        self.txtEntrada.setGeometry(QRect(230, 90, 161, 21))
        self.txtEntrada.setMaxLength(10)
        self.txtEntrada.setEchoMode(QLineEdit.EchoMode.Normal)
        self.label = QLabel(self.centralwidget)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(230, 70, 121, 16))
        self.btnAceptar = QPushButton(self.centralwidget)
        self.btnAceptar.setObjectName(u"btnAceptar")
        self.btnAceptar.setGeometry(QRect(230, 150, 161, 41))
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Ventana", None))
        self.imagen.setText("")
        self.txtEntrada.setPlaceholderText(QCoreApplication.translate("MainWindow", u"Aqui debes escribir", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"Escribe algo:", None))
        self.btnAceptar.setText(QCoreApplication.translate("MainWindow", u"Aceptar", None))
    # retranslateUi

