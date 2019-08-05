#include "StringProtocolConnector.hpp"
#include "cryptMessages.hpp"
#include <binders.h>

void StringProtocolConnector::readHandler(const QByteArray b) {
    if(con != nullptr) { // уже настроена сессия
        emit received(QString(b));
    } else { // TODO Нужно предусмотреть передачу сессионного ключа сюда
        // первое сообщение будет потеряно
        globalLog.addLog(Loger::L_TRACE, "Start session by remote user");
        con = std::shared_ptr<middlewareInterface>(new cryptMessages(this->cr.sessionKey.toStdString(), proto));
        con->read(std::bind(&StringProtocolConnector::readHandler, this, std::placeholders::_1));
    }
}

StringProtocolConnector::StringProtocolConnector(QObject *parent) : QObject(parent){
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

}

void StringProtocolConnector::write(const QString &message) {

}

void StringProtocolConnector::close() {
    globalLog.addLog(Loger::L_TRACE, "StringProtocolConnector::close");
    con = nullptr;
    if(proto != nullptr) proto->disconnect();
    QObject::disconnect(this->initCallBackConnection);
    QObject::disconnect(this->regCallBackConnection);
}
