# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'Ventana_Principal.ui'
##
## Created by: Qt User Interface Compiler version 6.9.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QAction, QBrush, QColor, QConicalGradient,
    QCursor, QFont, QFontDatabase, QGradient,
    QIcon, QImage, QKeySequence, QLinearGradient,
    QPainter, QPalette, QPixmap, QRadialGradient,
    QTransform)
from PySide6.QtWidgets import (QApplication, QGroupBox, QHeaderView, QMainWindow,
    QMenu, QMenuBar, QSizePolicy, QTableWidget,
    QTableWidgetItem, QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(418, 239)
        self.actionRegistrar_usuario = QAction(MainWindow)
        self.actionRegistrar_usuario.setObjectName(u"actionRegistrar_usuario")
        self.actionSalir = QAction(MainWindow)
        self.actionSalir.setObjectName(u"actionSalir")
        self.actionOnline = QAction(MainWindow)
        self.actionOnline.setObjectName(u"actionOnline")
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.groupBox = QGroupBox(self.centralwidget)
        self.groupBox.setObjectName(u"groupBox")
        self.groupBox.setGeometry(QRect(10, 10, 381, 161))
        self.tablaUsuarios = QTableWidget(self.groupBox)
        self.tablaUsuarios.setObjectName(u"tablaUsuarios")
        self.tablaUsuarios.setGeometry(QRect(10, 30, 361, 111))
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 418, 33))
        self.menuArchivo = QMenu(self.menubar)
        self.menuArchivo.setObjectName(u"menuArchivo")
        self.menuAyuda = QMenu(self.menubar)
        self.menuAyuda.setObjectName(u"menuAyuda")
        self.menuMas = QMenu(self.menuAyuda)
        self.menuMas.setObjectName(u"menuMas")
        MainWindow.setMenuBar(self.menubar)

        self.menubar.addAction(self.menuArchivo.menuAction())
        self.menubar.addAction(self.menuAyuda.menuAction())
        self.menuArchivo.addAction(self.actionRegistrar_usuario)
        self.menuArchivo.addSeparator()
        self.menuArchivo.addAction(self.actionSalir)
        self.menuAyuda.addAction(self.menuMas.menuAction())
        self.menuMas.addAction(self.actionOnline)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Usuarios", None))
        self.actionRegistrar_usuario.setText(QCoreApplication.translate("MainWindow", u"&Registrar usuario", None))
#if QT_CONFIG(shortcut)
        self.actionRegistrar_usuario.setShortcut(QCoreApplication.translate("MainWindow", u"Ctrl+R", None))
#endif // QT_CONFIG(shortcut)
        self.actionSalir.setText(QCoreApplication.translate("MainWindow", u"&Salir", None))
#if QT_CONFIG(shortcut)
        self.actionSalir.setShortcut(QCoreApplication.translate("MainWindow", u"Ctrl+S", None))
#endif // QT_CONFIG(shortcut)
        self.actionOnline.setText(QCoreApplication.translate("MainWindow", u"Online", None))
        self.groupBox.setTitle(QCoreApplication.translate("MainWindow", u"Usuarios Registrados", None))
        self.menuArchivo.setTitle(QCoreApplication.translate("MainWindow", u"&Archivo", None))
        self.menuAyuda.setTitle(QCoreApplication.translate("MainWindow", u"A&yuda", None))
        self.menuMas.setTitle(QCoreApplication.translate("MainWindow", u"Mas", None))
    # retranslateUi

