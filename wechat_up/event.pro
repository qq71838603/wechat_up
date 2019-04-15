#-------------------------------------------------
#
# Project created by QtCreator 2018-04-28T14:07:30
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SoftKey
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    button.cpp \
    mainwindow.cpp \
    main_interface.cpp

HEADERS  += widget.h \
    button.h \
    mainwindow.h \
    main_interface.h

FORMS    += widget.ui \
    mainwindow.ui \
    main_interface.ui
