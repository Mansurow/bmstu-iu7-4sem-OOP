# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = lab_04

QT = core gui widgets

HEADERS = \
   $$PWD/gui/mainwindow.h \
   $$PWD/src/button/Button.hpp \
   $$PWD/src/cabin/Cabin.hpp \
   $$PWD/src/controller/Controller.hpp \
   $$PWD/src/doors/Doors.hpp \
   $$PWD/src/lift/Lift.hpp \
   $$PWD/src/defines.hpp

SOURCES = \
   $$PWD/gui/mainwindow.cpp \
   $$PWD/src/button/Button.cpp \
   $$PWD/src/cabin/Cabin.cpp \
   $$PWD/src/controller/Controller.cpp \
   $$PWD/src/doors/Doors.cpp \
   $$PWD/src/lift/Lift.cpp \
   $$PWD/main.cpp

INCLUDEPATH = \
    $$PWD/gui

FORMS = \
   gui\ui\mainwindow.ui

#DEFINES = 

