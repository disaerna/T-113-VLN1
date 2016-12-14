QT += core sql
QT += gui
QT += widgets

CONFIG += c++11

TARGET = Verklegt
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    persons.cpp \
    domain.cpp \
    computers.cpp \
    dbmanager.cpp \
    mainmenu.cpp \
    addscientist.cpp \
    editperson.cpp \
    addcomputer.cpp \
    editcomputer.cpp

HEADERS += \
    persons.h \
    presentation.h \
    domain.h \
    computers.h \
    dbmanager.h \
    mainmenu.h \
    addscientist.h \
    editperson.h \
    addcomputer.h \
    editcomputer.h

FORMS += \
    mainmenu.ui \
    addscientist.ui \
    editperson.ui \
    addcomputer.ui \
    editcomputer.ui

