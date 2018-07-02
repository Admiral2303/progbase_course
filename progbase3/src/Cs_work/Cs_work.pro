#-------------------------------------------------
#
# Project created by QtCreator 2017-04-10T22:55:39
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network
CONFIG += c++11 (Qt5)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cs_work
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    maindoctor.cpp \
    doctor.cpp \
    patient.cpp \
    doctor_search.cpp \
    conection.cpp \
    information_patient.cpp \
    card.cpp \
    doctor_add.cpp \
    doctor_inf.cpp \
    patient_card.cpp \
    doctor_record.cpp \
    appointment.cpp \
    discharge_patients.cpp \
    smtp.cpp \
    report.cpp \
    query.cpp \
    help.cpp




HEADERS  += mainwindow.h \
    maindoctor.h \
    doctor.h \
    patient.h \
    doctor_search.h \
    conection.h \
    information_patient.h \
    card.h \
    doctor_add.h \
    doctor_inf.h \
    patient_card.h \
    doctor_record.h \
    appointment.h \
    discharge_patients.h \
    smtp.h \
    report.h \
    query.h \
    help.h

FORMS    += mainwindow.ui \
    maindoctor.ui \
    doctor.ui \
    patient.ui \
    doctor_search.ui \
    conection.ui \
    information_patient.ui \
    card.ui \
    doctor_add.ui \
    doctor_inf.ui \
    patient_card.ui \
    doctor_record.ui \
    appointment.ui \
    discharge_patients.ui \
    help.ui

RESOURCES += \
    data.qrc \
    search.qrc \
    clock.qrc \
    delete.qrc \
    firstwindow.qrc

DISTFILES += \
    0408911_PE570238_S5.jpg \
    search.png


unix:!macx: LIBS += -L$$PWD/../../../../../../usr/lib/x86_64-linux-gnu/ -lssl

INCLUDEPATH += $$PWD/../../../../../../usr/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../../../usr/lib/x86_64-linux-gnu

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../../usr/lib/x86_64-linux-gnu/libssl.a
