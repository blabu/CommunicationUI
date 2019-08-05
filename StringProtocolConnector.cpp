#include "StringProtocolConnector.hpp"
#include "cryptMessages.hpp"
#include <binders.h>

StringProtocolConnector::StringProtocolConnector(QObject *parent) : QObject(parent){
}

void StringProtocolConnector::init(const Credentials &cr) {
    this->cr = cr;
    con = std::shared_ptr<middlewareInterface>(ConnectionFactory::makeTCP(cr.serverAddr, cr.serverPort, 1000));
    if(con.get() != nullptr) {
        con->registerDisconnectEvent([this](){
            globalLog.addLog(Loger::L_TRACE,"Emit disconnect remote signal");
            emit disconnectedRemoteSignal();
        });
        con->read(std::bind(&StringProtocolConnector::initAck, this, std::placeholders::_1));
        con->write((initMessage + this->cr.id + ";\n").toUtf8());
    } else {
        globalLog.addLog(Loger::L_ERROR, "Can not connect to remote host ", cr.serverAddr.toStdString() + ":", cr.serverPort.toStdString());
    }
}

void StringProtocolConnector::registered(const Credentials &cr) {

}

void StringProtocolConnector::connect(const Credentials &cr) {
    this->cr = cr;
    con = nullptr;
    con = std::shared_ptr<middlewareInterface>(ConnectionFactory::makeTCP(cr.serverAddr, cr.serverPort, 1000));
    if(con.get() != nullptr) {
        con->registerDisconnectEvent([this](){
            globalLog.addLog(Loger::L_TRACE,"Emit disconnect remote signal");
            emit disconnectedRemoteSignal();
        });
        con->read(std::bind(&StringProtocolConnector::connectAck, this, std::placeholders::_1));
        con->write((connectMessage + this->cr.id + ";" + this->cr.identifierTo + ";\n").toUtf8());
    } else {
        globalLog.addLog(Loger::L_ERROR, "Can not connect to remote host ", cr.serverAddr.toStdString() + ":", cr.serverPort.toStdString());
    }
}

void StringProtocolConnector::close(){
    if(con != nullptr && con.get() != nullptr) {
        globalLog.addLog(Loger::L_TRACE, "Connection will close");
        disablePing();
        con = nullptr;
    }
}

void StringProtocolConnector::sendTo(const QString &message) {
    if(con != nullptr && con.get() != nullptr) {
        QByteArray res(message.toUtf8());
        res.append('\n');
        con->write(res);
    } else {
        emit disconnectedRemoteSignal();
    }
}

void StringProtocolConnector::initAck(const QByteArray &b) {
    if(con != nullptr && con.get() != nullptr) {
        con->read(nullptr);
        if(b == initOkMessage) {
            emit initOk();
            enablePing();
        }
        else globalLog.addLog(Loger::L_ERROR, "Receive message is not equal $V14=INIT OK; ", b.toStdString());
    }
}

void StringProtocolConnector::connectAck(const QByteArray &b) {
    if(con != nullptr && con.get() != nullptr) {
        con->read(nullptr);
        if(b == connectOkMessage) {
            disablePing();
            con = std::shared_ptr<middlewareInterface>(new cryptMessages(cr.password.toStdString(), std::move(con)));
            con->read(std::bind(&StringProtocolConnector::receiveFrom, this, std::placeholders::_1));
            emit connectOk();
        }
        else globalLog.addLog(Loger::L_ERROR, "Receive message is not equal $V13=CONNECT OK; ", b.toStdString());
    }
}

void StringProtocolConnector::enablePing() {
    pingConnection = QObject::connect(&ping, &QTimer::timeout, [this](){this->sendTo(pingCMD + this->cr.id + ";\n");});
    con->read([this](const QByteArray data) {
        if(data.at(0) == '$') return;
        con = std::shared_ptr<middlewareInterface>(new cryptMessages(cr.password.toStdString(), std::move(con)));
        con->read(std::bind(&StringProtocolConnector::receiveFrom, this, std::placeholders::_1));
        emit this->connectOk();
    });
    ping.start(600000);
}

void StringProtocolConnector::disablePing() {
    QObject::disconnect(pingConnection);
    ping.stop();
}

