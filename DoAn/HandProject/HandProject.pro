#-------------------------------------------------
#
# Project created by QtCreator 2018-06-18T10:36:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HandProject
TEMPLATE = app

INCLUDEPATH += C:/opencv-3.0.0-rc1/install/include

LIBS += C:/opencv-3.0.0-rc1/install/x86/mingw/bin/libopencv_core300.dll \
        C:/opencv-3.0.0-rc1/install/x86/mingw/bin/libopencv_imgcodecs300.dll \
        C:/opencv-3.0.0-rc1/install/x86/mingw/bin/libopencv_highgui300.dll \
        C:/opencv-3.0.0-rc1/install/x86/mingw/bin/libopencv_imgproc300.dll \
        C:/opencv-3.0.0-rc1/install/x86/mingw/bin/libopencv_videoio300.dll


SOURCES += main.cpp\
        mainwindow.cpp \
    handgesture.cpp \
    myImage.cpp \
    roi.cpp \
    shape.cpp \
    player.cpp

HEADERS  += \
    handGesture.hpp \
    myImage.hpp \
    mainwindow.hpp \
    roi.hpp \
    shape.hpp \
    player.hpp

FORMS    += mainwindow.ui

DEFINES += QT_DEPRECATED_WARNINGS
