QT += core
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
    Data/data.cpp \
    Domain/domain.cpp \
    Persons/persons.cpp \
    Presentation/presentation.cpp \
    MyClass.cpp

HEADERS += \
    persons.h \
    presentation.h \
    domain.h \
    data.h \
    Data/data.h \
    Domain/domain.h \
    Persons/persons.h \
    Presentation/presentation.h \
    MyClass.h
