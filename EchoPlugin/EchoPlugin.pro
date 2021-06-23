TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../MainWindow
TARGET          = $$qtLibraryTarget(echoplugin)
DESTDIR         = ../plugins

HEADERS += \
    echoplugin.h \

SOURCES += \
    echoplugin.cpp

CONFIG += console
