#-------------------------------------------------
#
# Project created by QtCreator 2015-12-24T23:35:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport

TARGET = nastawnik-krokowca
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialdriver.cpp

HEADERS  += mainwindow.h \
    serialdriver.h

FORMS    += mainwindow.ui

CONFIG += c++11

