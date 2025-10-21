# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'principal.ui'
##
## Created by: Qt User Interface Compiler version 6.9.0
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
from PySide6.QtWidgets import (QApplication, QFrame, QGridLayout, QLineEdit,
    QMainWindow, QMenu, QMenuBar, QPlainTextEdit,
    QPushButton, QSizePolicy, QWidget)

class Ui_Messenger(object):
    def setupUi(self, Messenger):
        if not Messenger.objectName():
            Messenger.setObjectName(u"Messenger")
        Messenger.resize(493, 414)
        self.actionConectar = QAction(Messenger)
        self.actionConectar.setObjectName(u"actionConectar")
        self.actionSalir = QAction(Messenger)
        self.actionSalir.setObjectName(u"actionSalir")
        self.centralwidget = QWidget(Messenger)
        self.centralwidget.setObjectName(u"centralwidget")
        self.gridLayout = QGridLayout(self.centralwidget)
        self.gridLayout.setObjectName(u"gridLayout")
        self.txtMsgs = QPlainTextEdit(self.centralwidget)
        self.txtMsgs.setObjectName(u"txtMsgs")
        self.txtMsgs.setEnabled(True)
        self.txtMsgs.setFrameShape(QFrame.Box)
        self.txtMsgs.setFrameShadow(QFrame.Raised)
        self.txtMsgs.setReadOnly(True)

        self.gridLayout.addWidget(self.txtMsgs, 0, 0, 1, 2)

        self.txtSend = QLineEdit(self.centralwidget)
        self.txtSend.setObjectName(u"txtSend")
        self.txtSend.setMaxLength(1023)

        self.gridLayout.addWidget(self.txtSend, 1, 0, 1, 1)

        self.btnSend = QPushButton(self.centralwidget)
        self.btnSend.setObjectName(u"btnSend")

        self.gridLayout.addWidget(self.btnSend, 1, 1, 1, 1)

        Messenger.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(Messenger)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 493, 21))
        self.menuArchivo = QMenu(self.menubar)
        self.menuArchivo.setObjectName(u"menuArchivo")
        Messenger.setMenuBar(self.menubar)

        self.menubar.addAction(self.menuArchivo.menuAction())
        self.menuArchivo.addAction(self.actionConectar)
        self.menuArchivo.addSeparator()
        self.menuArchivo.addAction(self.actionSalir)

        self.retranslateUi(Messenger)

        QMetaObject.connectSlotsByName(Messenger)
    # setupUi

    def retranslateUi(self, Messenger):
        Messenger.setWindowTitle(QCoreApplication.translate("Messenger", u"Messenger", None))
        self.actionConectar.setText(QCoreApplication.translate("Messenger", u"Co&nectar", None))
#if QT_CONFIG(shortcut)
        self.actionConectar.setShortcut(QCoreApplication.translate("Messenger", u"Ctrl+C", None))
#endif // QT_CONFIG(shortcut)
        self.actionSalir.setText(QCoreApplication.translate("Messenger", u"&Salir", None))
#if QT_CONFIG(shortcut)
        self.actionSalir.setShortcut(QCoreApplication.translate("Messenger", u"Ctrl+X", None))
#endif // QT_CONFIG(shortcut)
        self.btnSend.setText(QCoreApplication.translate("Messenger", u"Enviar", None))
        self.menuArchivo.setTitle(QCoreApplication.translate("Messenger", u"&Archivo", None))
    # retranslateUi

