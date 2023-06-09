#-------------------------------------------------
#
# Project created by QtCreator 2023-03-26T20:52:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VideoPlayer-ffmpeg
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    videoslider.cpp \
    videoplayer.cpp \
    videoplayer_audio.cpp \
    videoplayer_video.cpp \
    condmutex.cpp \
    aplayer.cpp

HEADERS += \
        mainwindow.h \
    videoslider.h \
    videoplayer.h \
    condmutex.h \
    aplayer.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32 {
INCLUDEPATH += ..\ffmpeg\include
INCLUDEPATH +=  ..\SDL2-2.26.4\x86_64-w64-mingw32\include

#LIBS += -L ../SDL2-2.26.4/x86_64-w64-mingw32/lib -lSDL2
LIBS += -L ../ffmpeg/lib \
        -lavcodec \
        -lavdevice \
        -lavfilter \
        -lavformat \
        -lavutil \
        -lpostproc \
        -lswresample \
        -lSDL2 \
        -lswscale
}

