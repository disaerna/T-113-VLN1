QT += core sql
QT -= gui

CONFIG += c++11

TARGET = Verklegt
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    persons.cpp \
    presentation.cpp \
    domain.cpp \
    data.cpp \
    computers.cpp

HEADERS += \
    persons.h \
    presentation.h \
    domain.h \
    data.h \
    computers.h
