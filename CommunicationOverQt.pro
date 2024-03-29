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
    Protocol.cpp \
    ReadWriteTcp.cpp \
    StringProtocolConnector.cpp \
    base64Messages.cpp \
    cryptmessages.cpp \
    mainwindow.cpp \
    Logger/FileLoger.cpp \
    Logger/Loger.cpp \
    sendProperties.cpp \
    startup.cpp

HEADERS  += mainwindow.h \
    ConnectionFactory.hpp \
    Logger/ILogerWriter.h \
    Logger/consoleLoger.h \
    Logger/FileLoger.hpp \
    Logger/Loger.hpp \
    Logger/StatusInterface.hpp \
    MainProjectLoger.hpp \ \
    Protocol.h \
    ReadWriteTcp.hpp \
    StringProtocolConnector.hpp \
    base64Messages.hpp \
    credentials.hpp \
    cryptMessages.hpp \
    middlewareInterface.hpp \
    sendProperties.hpp \
    startup.hpp

FORMS    += mainwindow.ui \
            Startup.ui \
            sendproperties.ui

DISTFILES +=

LIBS += -L$$PWD/vendor/lib/ -lbotan-2

INCLUDEPATH += $$PWD/vendor/inc
DEPENDPATH += $$PWD/vendor/inc

PRE_TARGETDEPS += $$PWD/vendor/lib/libbotan-2.a
