TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../MainWindow
TARGET          = $$qtLibraryTarget(echoplugin)
DESTDIR         = ../plugins

HEADERS += \
    echoplugin.h \
    ../QtDbusDemo/Server/echointerface.h

SOURCES += \
    echoplugin.cpp

CONFIG += console
