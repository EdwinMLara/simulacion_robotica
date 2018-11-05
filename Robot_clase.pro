#-------------------------------------------------
#
# Project created by QtCreator 2014-10-12T18:01:19
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Robot_clase
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

win32: LIBS += -lglut32 -lopengl32
else:unix: LIBS += -lGL -lglut

SOURCES += main.cpp \
    mapa.cpp \
    robot.cpp

HEADERS += \
    mapa.h \
    robot.h

