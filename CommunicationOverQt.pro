#-------------------------------------------------
#
# Project created by QtCreator 2019-07-22T17:34:03
#
#-------------------------------------------------

QT       += core gui widgets network

TARGET = CommunicationOverQt
TEMPLATE = app

CONFIG += c++11
CONFIG += thread
CONFIG += static

SOURCES += main.cpp\
    ConnectionFactory.cpp \
    ReadWriteTcp.cpp \
    StringProtocolConnector.cpp \
    cryptmessages.cpp \
    mainwindow.cpp \
    Logger/FileLoger.cpp \
    Logger/Loger.cpp

HEADERS  += mainwindow.h \
    ConnectionFactory.hpp \
    Logger/ILogerWriter.h \
    Logger/consoleLoger.h \
    Logger/FileLoger.hpp \
    Logger/Loger.hpp \
    Logger/StatusInterface.hpp \
    MainProjectLoger.hpp \ \
    ReadWriteTcp.hpp \
    StringProtocolConnector.hpp \
    credentials.hpp \
    cryptMessages.hpp \
    middlewareInterface.hpp

FORMS    += mainwindow.ui

DISTFILES +=

LIBS += -L$$PWD/../../../IDE/botan-2.10.0/ -lbotan-2

INCLUDEPATH += $$PWD/../../../IDE/botan-2.10.0/build/include
DEPENDPATH += $$PWD/../../../IDE/botan-2.10.0/build/include

PRE_TARGETDEPS += $$PWD/../../../IDE/botan-2.10.0/libbotan-2.a
