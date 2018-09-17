#-------------------------------------------------
#
# Project created by QtCreator 2018-09-17T15:30:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestInfoservices
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    infoservices.cpp \
    module1.cpp \
    module2.cpp \
    module2mock.cpp

HEADERS  += mainwindow.h \
    infoservices.h \
    infoservicesmodule.h \
    module1.h \
    module2.h \
    module2mock.h

FORMS    += mainwindow.ui
