#-------------------------------------------------
#
# Project created by QtCreator 2019-06-05T07:28:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Paint3D
TEMPLATE = app


SOURCES += main.cpp\
    colordisplay.cpp \
    dialog.cpp \
    figurageometrica.cpp \
        mainwindow.cpp \
    cutbox.cpp \
    cutellipsoid.cpp \
    cutsphere.cpp \
    cutvoxel.cpp \
    plotter.cpp \
    putbox.cpp \
    putellipsoid.cpp \
    putsphere.cpp \
    putvoxel.cpp \
    sculptor.cpp

HEADERS  += mainwindow.h \
    colordisplay.h \
    cutbox.h \
    cutellipsoid.h \
    cutsphere.h \
    cutvoxel.h \
    dialog.h \
    figurageometrica.h \
    plotter.h \
    putbox.h \
    putellipsoid.h \
    putsphere.h \
    putvoxel.h \
    sculptor.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    resource.qrc
