# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'Registro.ui'
##
## Created by: Qt User Interface Compiler version 6.9.2
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
from PySide6.QtWidgets import (QAbstractButton, QApplication, QComboBox, QDialog,
    QDialogButtonBox, QLabel, QLineEdit, QSizePolicy,
    QWidget)

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        if not Dialog.objectName():
            Dialog.setObjectName(u"Dialog")
        Dialog.resize(400, 300)
        self.buttonBox = QDialogButtonBox(Dialog)
        self.buttonBox.setObjectName(u"buttonBox")
        self.buttonBox.setGeometry(QRect(30, 240, 341, 32))
        self.buttonBox.setOrientation(Qt.Orientation.Horizontal)
        self.buttonBox.setStandardButtons(QDialogButtonBox.StandardButton.Cancel|QDialogButtonBox.StandardButton.Ok)
        self.label = QLabel(Dialog)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(40, 40, 211, 16))
        self.label_2 = QLabel(Dialog)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(40, 100, 49, 16))
        self.label_3 = QLabel(Dialog)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setGeometry(QRect(40, 160, 49, 16))
        self.txtNombre = QLineEdit(Dialog)
        self.txtNombre.setObjectName(u"txtNombre")
        self.txtNombre.setGeometry(QRect(40, 70, 311, 21))
        self.txtCorreo = QLineEdit(Dialog)
        self.txtCorreo.setObjectName(u"txtCorreo")
        self.txtCorreo.setGeometry(QRect(40, 130, 311, 21))
        self.comboTipo = QComboBox(Dialog)
        self.comboTipo.addItem("")
        self.comboTipo.addItem("")
        self.comboTipo.addItem("")
        self.comboTipo.setObjectName(u"comboTipo")
        self.comboTipo.setGeometry(QRect(40, 190, 311, 24))

        self.retranslateUi(Dialog)
        self.buttonBox.accepted.connect(Dialog.accept)
        self.buttonBox.rejected.connect(Dialog.reject)

        QMetaObject.connectSlotsByName(Dialog)
    # setupUi

    def retranslateUi(self, Dialog):
        Dialog.setWindowTitle(QCoreApplication.translate("Dialog", u"Registro", None))
        self.label.setText(QCoreApplication.translate("Dialog", u"Nombre:", None))
        self.label_2.setText(QCoreApplication.translate("Dialog", u"Correo:", None))
        self.label_3.setText(QCoreApplication.translate("Dialog", u"Tipo:", None))
        self.comboTipo.setItemText(0, QCoreApplication.translate("Dialog", u"Administrador", None))
        self.comboTipo.setItemText(1, QCoreApplication.translate("Dialog", u"Usuario", None))
        self.comboTipo.setItemText(2, QCoreApplication.translate("Dialog", u"Empleado", None))

    # retranslateUi

