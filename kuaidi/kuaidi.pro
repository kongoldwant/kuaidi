#-------------------------------------------------
#
# Project created by QtCreator 2014-02-10T19:24:43
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
TARGET = kuaidi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    jsondata.cpp \
    getinfo.cpp

HEADERS  += mainwindow.h \
    jsondata.h \
    getinfo.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

OTHER_FILES += \
    res.rc
RC_FILE = \
    res.rc
