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
        MainWindow.resize(399, 308)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.label = QLabel(self.centralwidget)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(10, 30, 181, 251))
        self.label.setPixmap(QPixmap(u"trump.png"))
        self.label.setScaledContents(True)
        self.txtEntrada = QLineEdit(self.centralwidget)
        self.txtEntrada.setObjectName(u"txtEntrada")
        self.txtEntrada.setGeometry(QRect(210, 110, 171, 21))
        self.txtEntrada.setMaxLength(10)
        self.txtEntrada.setEchoMode(QLineEdit.EchoMode.Normal)
        self.label_2 = QLabel(self.centralwidget)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(210, 90, 161, 16))
        self.btnAceptar = QPushButton(self.centralwidget)
        self.btnAceptar.setObjectName(u"btnAceptar")
        self.btnAceptar.setGeometry(QRect(210, 150, 171, 81))
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Trumpas", None))
        self.label.setText("")
        self.txtEntrada.setPlaceholderText(QCoreApplication.translate("MainWindow", u"Escribe algo aqui", None))
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"Escribe algo:", None))
        self.btnAceptar.setText(QCoreApplication.translate("MainWindow", u"Aceptar", None))
    # retranslateUi

