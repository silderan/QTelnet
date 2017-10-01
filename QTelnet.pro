#-------------------------------------------------
#
# Project created by QtCreator 2017-10-01T20:47:40
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTelnet
TEMPLATE = app


SOURCES += main.cpp\
        QTelnetTester.cpp \
    QTelnet.cpp \
    QCmdWidget.cpp

HEADERS  += QTelnetTester.h \
    QTelnet.h \
    QCmdWidget.h

FORMS    += QTelnetTester.ui

RESOURCES += \
    resources.qrc
