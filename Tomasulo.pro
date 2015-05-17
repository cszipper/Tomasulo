#-------------------------------------------------
#
# Project created by QtCreator 2015-05-08T20:43:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tomasulo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    instructionstate.cpp \
    loadunit.cpp \
    reservedstack.cpp \
    register.cpp \
    def.cpp

HEADERS  += mainwindow.h \
    instructionstate.h \
    loadunit.h \
    reservedstack.h \
    register.h \
    def.h

FORMS    += mainwindow.ui \
    instructionstate.ui \
    loadunit.ui \
    reservedstack.ui \
    register.ui

RESOURCES +=
