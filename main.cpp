#include "MainProjectLoger.hpp"
#include "mainwindow.h"
#include <QApplication>
#include <QFontDatabase>
#include <QTimer>
#include "StringProtocolConnector.hpp"

Loger globalLog("GLOBAL");

int main(int argc, char *argv[]) {
    //globalLog.SetAddr("./");
    globalLog.addLog(Loger::L_TRACE, "Start application");
    QApplication ui(argc, argv);
    if(QFontDatabase::addApplicationFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf") < 0 ) {
        globalLog.addLog(Loger::L_ERROR, "Applicartion font can not be loaded");
    }
    MainWindow w;
    StringProtocolConnector* protocol = new StringProtocolConnector(&w);
    QObject::connect(&w, SIGNAL(TryConnect(const Credentials&)), protocol, SLOT(connect(const Credentials&)));
    QObject::connect(&w, SIGNAL(TryInit(const Credentials&)), protocol, SLOT(init(const Credentials&)));
    QObject::connect(protocol, SIGNAL(initOk()), &w, SLOT(initFine()));
    QObject::connect(protocol, SIGNAL(connectOk()), &w, SLOT(connectionFine()));
    QObject::connect(&w, SIGNAL(sendTextMessages(QString)), protocol, SLOT(sendTo(const QString&)));
    QObject::connect(protocol, SIGNAL(received(QString)), &w, SLOT(newTextMessageReceived(const QString&)));
    QObject::connect(&w, SIGNAL(pressedDisconnect()), protocol, SLOT(close()));
    QObject::connect(protocol, SIGNAL(disconnectedRemoteSignal()), &w, SLOT(disconnect()));
    w.show();
    ui.exec();
    Loger::snapShotLong();
    return 0;
}
