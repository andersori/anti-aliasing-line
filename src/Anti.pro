#-------------------------------------------------
#
# Project created by QtCreator 2018-05-20T20:59:42
#
#-------------------------------------------------

QT       += core gui opengl
LIBS     += -lOpengl32 -lglu32
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Anti
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    pixel.cpp \
    matriz.cpp \
    linha.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    pixel.h \
    matriz.h \
    linha.h

FORMS    += mainwindow.ui
