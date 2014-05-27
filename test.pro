#-------------------------------------------------
#
# Project created by QtCreator 2013-12-12T22:04:53
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    samplinggraphicsview.cpp \
    samplinggraphicsitem.cpp \
    buoygraphicsitem.cpp \
    respondergraphicsitem.cpp \
    shipgraphicsitem.cpp \
    mygridgraphicsscene.cpp

HEADERS  += mainwindow.h \
    samplinggraphicsview.h \
    samplinggraphicsitem.h \
    global_define.h \
    buoygraphicsitem.h \
    respondergraphicsitem.h \
    shipgraphicsitem.h \
    mygridgraphicsscene.h

FORMS    += mainwindow.ui

RESOURCES += \
    qrc.qrc
