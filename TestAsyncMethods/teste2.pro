#-------------------------------------------------
#
# Project created by QtCreator 2018-08-03T16:41:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = teste2
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    foo.cpp \
    foomodel.cpp

HEADERS  += mainwindow.h \
    foo.h \
    foomodel.h

FORMS    += mainwindow.ui
