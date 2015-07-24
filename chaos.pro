#-------------------------------------------------
#
# Project created by QtCreator 2015-07-14T16:16:10
#
#-------------------------------------------------

QT       += core gui

QT += widgets multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chaos
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    videowidget.cpp

HEADERS  += widget.h \
    videowidget.h

RESOURCES += \
    res.qrc
