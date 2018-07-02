#-------------------------------------------------
#
# Project created by QtCreator 2017-04-26T12:22:52
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11 (Qt5)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab7
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcp_client.cpp \
    jsonconvert.cpp \
    pokemon.cpp

HEADERS  += mainwindow.h \
    tcp_client.h \
    jsonconvert.h \
    pokemon.h

FORMS    += mainwindow.ui

unix:!macx: LIBS += -L$$PWD/../../../../../../../usr/local/lib/ -lprogbase-cpp

INCLUDEPATH += $$PWD/../../../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../../../usr/local/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../../../usr/local/lib/libprogbase-cpp.a

unix:!macx: LIBS += -L$$PWD/../../../../../../../usr/local/lib/ -lprogbase

INCLUDEPATH += $$PWD/../../../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../../../usr/local/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../../../usr/local/lib/libprogbase.a

unix:!macx: LIBS += -lssl
