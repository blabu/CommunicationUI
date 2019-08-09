#include "StringProtocolConnector.hpp"
#include "cryptMessages.hpp"
#include <binders.h>

void StringProtocolConnector::readHandler(const QByteArray b) {
    if(con != nullptr) { // уже настроена сессия
        globalLog.addLog(Loger::L_TRACE, "Receive new data ", b.toStdString());
        emit received(QString(b));
    } else { // TODO Нужно предусмотреть передачу сессионного ключа сюда
        // первое сообщение будет потеряно
        globalLog.addLog(Loger::L_TRACE, "Start session by remote user with session key ", cr.sessionKey.toStdString());
        emit connectBy(proto->getTo());
        con = std::shared_ptr<middlewareInterface>(new cryptMessages(this->cr.sessionKey.toStdString(), proto));
        con->read(std::bind(&StringProtocolConnector::readHandler, this, std::placeholders::_1));
    }
}

StringProtocolConnector::StringProtocolConnector(QObject *parent) : QObject(parent){
}

void StringProtocolConnector::setSessionKey(const QString &key) {
    globalLog.addLog(Loger::L_TRACE, "Session key was changed to ", key.toStdString());
    cr.sessionKey = key;
}

void StringProtocolConnector::init(const Credentials &cr) {
    this->cr = cr;
    globalLog.addLog(Loger::L_TRACE, "StringProtocolConnector::init");
    proto = std::shared_ptr<Protocol>(new Protocol(cr.id,cr.serverAddr,cr.serverPort));
    if(proto == nullptr || proto.get() == nullptr) {
        emit initFail();
        return;
    }
    initCallBackConnection = QObject::connect(proto.get(), &Protocol::initOK, [this](){
        QObject::disconnect(this->initCallBackConnection);
        this->proto->read(std::bind(&StringProtocolConnector::readHandler, this, std::placeholders::_1));
        emit this->initOk();
    });
    proto->registerDisconnectEvent([this](){ QObject::disconnect(this->initCallBackConnection); emit this->initFail(); });
    proto->init(cr.password);
}

void StringProtocolConnector::registered(const Credentials &cr) {
    this->cr = cr;
    globalLog.addLog(Loger::L_TRACE, "StringProtocolConnector::registered");
    proto = std::shared_ptr<Protocol>(new Protocol(cr.id,cr.serverAddr,cr.serverPort));
    if(proto == nullptr || proto.get() == nullptr) {
        emit registerFail();
        return;
    }
    regCallBackConnection = QObject::connect(proto.get(), &Protocol::regOK, [this]() {
        QObject::disconnect(this->regCallBackConnection);
        this->proto->read(std::bind(&StringProtocolConnector::readHandler, this, std::placeholders::_1));
        emit this->registerOk();
    });
    proto->registerDisconnectEvent([this](){ QObject::disconnect(this->regCallBackConnection); emit this->registerFail(); });
    proto->reg(cr.password);
}

void StringProtocolConnector::connect(const Credentials &cr) {
    if(this->cr.id != cr.id) {
        globalLog.addLog(Loger::L_WARNING, "Incorrect id ", cr.id.toStdString(), " but wait " + this->cr.id.toStdString());
    }
    this->cr.sessionKey = cr.sessionKey;
    this->cr.identifierTo = cr.identifierTo;
    if(proto == nullptr || proto.get() == nullptr) {
        globalLog.addLog(Loger::L_ERROR, "Protocol is null");
        emit disconnectedRemoteSignal();
        return;
    }
    globalLog.addLog(Loger::L_TRACE, "Try connect from " + cr.id.toStdString(), " to " + cr.identifierTo.toStdString());
    connectCallBackConnection = QObject::connect(proto.get(), &Protocol::connectToOK, [this]() {
        QObject::disconnect(this->connectCallBackConnection);
        globalLog.addLog(Loger::L_TRACE, "Connection ok handler");
        con = std::shared_ptr<middlewareInterface>(new cryptMessages(this->cr.sessionKey.toStdString(), proto));
        con->read(std::bind(&StringProtocolConnector::readHandler, this, std::placeholders::_1));
        emit this->connectOk();
    });
    proto->registerDisconnectEvent([this](){ QObject::disconnect(this->connectCallBackConnection); this->init(this->cr); });
    proto->connectTo(cr.identifierTo);
}

void StringProtocolConnector::write(const QString &message) {
    if(con == nullptr || con.get() == nullptr) {
        globalLog.addLog(Loger::L_ERROR, "Can not send message ", message.toStdString(), " connection is null");
        return;
    }
    con->write(message.toUtf8());
}

void StringProtocolConnector::close() {
    globalLog.addLog(Loger::L_TRACE, "StringProtocolConnector::close");
    QObject::disconnect(this->initCallBackConnection);
    QObject::disconnect(this->regCallBackConnection);
    QObject::disconnect(this->connectCallBackConnection);
    con = nullptr;
    if(proto != nullptr) {
        proto->disconnect();
    }
    this->init(cr);
}
