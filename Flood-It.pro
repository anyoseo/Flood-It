QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = Floot-It.pro
TEMPLATE = app
#DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += console c++17
CONFIG -= app_bundle

QMAKE_CXXFLAGS += -pedantic-errors
SOURCES += \
        board.cpp \
        clickablelabel.cpp \
        fileReader.cpp \
        game.cpp \
        gamewindow.cpp \
        main.cpp \
        mainwindow.cpp \
        square.cpp

HEADERS += \
    Observable.h \
    Observer.h \
    board.h \
    clickablelabel.h \
    fileReader.h \
    game.h \
    gamewindow.h \
    mainwindow.h \
    square.h \
    squareColor.h

FORMS += \
    gamewindow.ui \
    mainwindow.ui

RESOURCES +=

DISTFILES += \
    scores.txt
