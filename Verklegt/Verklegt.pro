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
    presentation.cpp \
    domain.cpp \
    computers.cpp \
    dbmanager.cpp \
    mainmenu.cpp \
    personsmenu.cpp \
    computersmenu.cpp

HEADERS += \
    persons.h \
    presentation.h \
    domain.h \
    computers.h \
    dbmanager.h \
    mainmenu.h \
    personsmenu.h \
    computersmenu.h

FORMS += \
    mainmenu.ui \
    personsmenu.ui \
    computersmenu.ui
