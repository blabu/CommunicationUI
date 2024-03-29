#include "StringProtocolConnector.hpp"
#include "cryptMessages.hpp"
#include "base64Messages.hpp"
#include <binders.h>

void StringProtocolConnector::readHandler(const QByteArray b) {
    if(con != nullptr) { // уже настроена сессия
        globalLog.addLog(Loger::L_TRACE, "Receive new data ", b.toStdString());
        emit received(QString(b));
    } else { // TODO Нужно предусмотреть передачу сессионного ключа сюда
        // первое сообщение будет потеряно
        globalLog.addLog(Loger::L_TRACE, "Start session by remote user with session key ", cr.sessionKey.toStdString());
        emit connectBy(proto->getTo());
        if(!cr.sessionKey.isEmpty()) {
            con = std::shared_ptr<middlewareInterface>(new cryptMessages(this->cr.sessionKey.toStdString(), proto));
        } else {
            if(cr.isBase64) {
                globalLog.addLog(Loger::L_TRACE, "Base64 mode initialize in readHandler()");
                con = std::shared_ptr<middlewareInterface>(new base64Messages(proto));
            }
            else {
                globalLog.addLog(Loger::L_TRACE, "Transparent mode initialize in readHandler()");
                con = proto;
            }
        }
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
    this->cr.isBase64 = cr.isBase64;
    if(proto == nullptr || proto.get() == nullptr) {
        globalLog.addLog(Loger::L_ERROR, "Protocol is null");
        emit disconnectedRemoteSignal();
        return;
    }
    globalLog.addLog(Loger::L_TRACE, "Try connect from " + cr.id.toStdString(), " to " + cr.identifierTo.toStdString());
    connectCallBackConnection = QObject::connect(proto.get(), &Protocol::connectToOK, [this]() {
        QObject::disconnect(this->connectCallBackConnection);
        globalLog.addLog(Loger::L_TRACE, "Connection ok handler");
        if(!this->cr.sessionKey.isEmpty()) con = std::shared_ptr<middlewareInterface>(new cryptMessages(this->cr.sessionKey.toStdString(), proto));
        else if(this->cr.isBase64) {
            globalLog.addLog(Loger::L_TRACE, "Base64 mode initialize in connect");
            con = std::shared_ptr<middlewareInterface>(new base64Messages(proto));
        } else {
            globalLog.addLog(Loger::L_TRACE, "Transparent mode initialize in connect");
            con = proto;
        }
        con->read(std::bind(&StringProtocolConnector::readHandler, this, std::placeholders::_1));
        //con->write(QString("Test connection message").toUtf8());
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

void StringProtocolConnector::destroyConnection() {
    globalLog.addLog(Loger::L_TRACE, "StringProtocolConnector::destroyConnection");
    if(proto != nullptr) {
        proto->destroyConnection();
    }
}

void StringProtocolConnector::sendProp(ModemProperties m) {
    globalLog.addLog(Loger::L_TRACE, "StringProtocolConnector::sendProp");
    bool ok = false;
    m.baudrate.toUInt(&ok,10);
    if(m.baudrate.size() > 0 && !ok) {
       globalLog.addLog(Loger::L_ERROR, "Baudrate not correct", m.baudrate.toStdString());
       return;
    }
    m.modemTimeout.toUInt(&ok,10);
    if(m.modemTimeout.size() > 0 && !ok) {
       globalLog.addLog(Loger::L_ERROR, "Modem timeout not correct", m.modemTimeout.toStdString());
       return;
    }
    m.rs232Timeout.toUInt(&ok,10);
    if(m.rs232Timeout.size() > 0 && !ok) {
        globalLog.addLog(Loger::L_ERROR, "RS232 timeout not correct", m.rs232Timeout.toStdString());
        return;
    }
    if(proto != nullptr) {
        globalLog.addLog(Loger::L_TRACE, "Try send properties ", m.baudrate.toStdString(), m.serverIP.toStdString());
        proto->sendProperties(m);
    } else {
        globalLog.addLog(Loger::L_ERROR, "Protocol instance is null");
    }
}

void StringProtocolConnector::close() {
    globalLog.addLog(Loger::L_TRACE, "StringProtocolConnector::close");
    QObject::disconnect(this->initCallBackConnection);
    QObject::disconnect(this->regCallBackConnection);
    QObject::disconnect(this->connectCallBackConnection);
    con = nullptr;
    this->init(cr);
}
