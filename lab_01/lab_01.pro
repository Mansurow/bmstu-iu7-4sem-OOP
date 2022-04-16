# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = lab_01

QT = core gui widgets

HEADERS = \
   $$PWD/actions/action_data.h \
   $$PWD/actions/actions.h \
   $$PWD/draw/draw_figure.h \
   $$PWD/errors/errors.h \
   $$PWD/geometry/edges.h \
   $$PWD/geometry/figure.h \
   $$PWD/geometry/point.h \
   $$PWD/geometry/points.h \
   $$PWD/mainwindow.h

SOURCES = \
   $$PWD/actions/actions.cpp \
   $$PWD/draw/draw_figure.cpp \
   $$PWD/errors/errors.cpp \
   $$PWD/geometry/edges.cpp \
   $$PWD/geometry/figure.cpp \
   $$PWD/geometry/point.cpp \
   $$PWD/geometry/points.cpp \
   $$PWD/main.cpp \
   $$PWD/mainwindow.cpp

INCLUDEPATH = \
    $$PWD/. \
    $$PWD/actions \
    $$PWD/draw \
    $$PWD/errors \
    $$PWD/geometry

#DEFINES = 

