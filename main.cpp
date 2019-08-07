#include "MainProjectLoger.hpp"
#include "mainwindow.h"
#include <QApplication>
#include <QFontDatabase>
#include <QTimer>
#include "StringProtocolConnector.hpp"
#include "startup.hpp"

Loger globalLog("GLOBAL");

int main(int argc, char *argv[]) {
    //globalLog.SetAddr("./");
    globalLog.addLog(Loger::L_TRACE, "Start application");
    QApplication ui(argc, argv);
    if(QFontDatabase::addApplicationFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf") < 0 ) {
        globalLog.addLog(Loger::L_ERROR, "Applicartion font can not be loaded");
    }
    MainWindow w;
    StartUp start(&w);
    start.show();
    StringProtocolConnector protocol;
    QObject::connect(&start, SIGNAL(tryInit(const Credentials&)), &protocol, SLOT(init(const Credentials&)));
    QObject::connect(&start, SIGNAL(tryRegister(const Credentials&)), &protocol, SLOT(registered(const Credentials&)));

    // IF disconected
    QObject::connect(&protocol, SIGNAL(initFail()), &start, SLOT(disableMainWindow()));
    QObject::connect(&protocol, SIGNAL(registerFail()), &start, SLOT(disableMainWindow()));
    QObject::connect(&protocol, SIGNAL(disconnectedRemoteSignal()), &start, SLOT(disableMainWindow()));

    // If connection fine
    QObject::connect(&protocol, SIGNAL(initOk()), &start, SLOT(enableMainWindow()));
    QObject::connect(&protocol, SIGNAL(registerOk()), &start, SLOT(enableMainWindow()));

    // Connect
    QObject::connect(&w, SIGNAL(tryConnect(const Credentials&)), &protocol, SLOT(connect(const Credentials&)));
    QObject::connect(&protocol, SIGNAL(connectOk()), &w, SLOT(connectionFine()));

    //Read write
    QObject::connect(&w, SIGNAL(sendText(QString)), &protocol, SLOT(write(const QString&)));
    QObject::connect(&protocol, SIGNAL(received(QString)), &w, SLOT(receiveText(const QString&)));

    // Disconnect
    QObject::connect(&w, SIGNAL(pressedDisconnect()), &protocol, SLOT(close()));
    QObject::connect(&protocol, SIGNAL(disconnectedRemoteSignal()), &w, SLOT(disconnect()));

    ui.exec();
    Loger::snapShotLong();
    return 0;
}
