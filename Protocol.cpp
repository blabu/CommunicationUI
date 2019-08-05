#include "Protocol.h"
#include "ConnectionFactory.hpp"
#include <botan/base64.h>
#include <botan/system_rng.h>
#include <botan/sha2_32.h>

const QString Protocol::registerMessage("$V1;%1;0;3;%2###%3"); // local name, message size, BASE64((SHA256(name + password))
const QString Protocol::registerOkMessage("$V1;0;%1;3;");      // local name
const QString Protocol::initMessage("$V1;%1;0;5;%2###%3"); // local name, message size, (salt + ; + BASE64(SHA256(name + salt + BASE64(SHA256(name + password)))
const QString Protocol::initOkMessage("$V1;0;%1;5;8###INIT OK;"); // local name
const QString Protocol::connectMessage("$V1;%1;%2;7;0###"); //local name, to name
const QString Protocol::connectOkMessage("$V1;%1;%2;7;B###CONNECT OK;"); // to name, local name
const QString Protocol::pingCMD("$V1;%1;0;2;0###"); // local name
const QString Protocol::dataCMD("$V1;%1;%2;8;%3###"); //local name, to, message size

const std::string Protocol::passwordHash(QString pass) const {
    return Botan::base64_encode(Botan::SHA_256().process(name.toStdString() + pass.toStdString()));
}

void Protocol::initHandler(const QByteArray b) {
    QByteArray ok((initOkMessage.arg(name)).toUtf8());
    if(b.contains(ok)) {
        isOnline.store(true);
        isConnected.store(false);
        emit initOK();
    } else {
        globalLog.addLog(Loger::L_ERROR, "Incorrect message in init handler ",b.toStdString());
    }
}

void Protocol::registerHandler(const QByteArray b) {
    QByteArray ok((registerOkMessage.arg(name)).toUtf8());
    if(b.contains(ok)) {
        isOnline.store(true);
        isConnected.store(false);
        emit regOK();
    } else {
        globalLog.addLog(Loger::L_ERROR, "Incorrect message in registerHandler handler ",b.toStdString());
    }
}

void Protocol::connectHandler(const QByteArray b) {
    QByteArray ok(registerOkMessage.arg(name).toUtf8());
    if(b.contains(ok)) {
        isConnected.store(true);
        con->read(readHandler);
        con->registerDisconnectEvent(disconnectHandler);
        emit connectToOK();
    }

}

Protocol::Protocol(const QString &name, const QString &ip, const QString &port, QObject *parent) : QObject(parent), ip(ip), port(port), name(name) {
    isOnline.store(false);
    isConnected.store(false);
}

void Protocol::init(const QString &pass) {
    password = pass;
    globalLog.addLog(Loger::L_TRACE, "Try open connection for init in Protocol");
    con = std::shared_ptr<middlewareInterface>(ConnectionFactory::makeTCP(ip, port, 1000)); // Создаем соединение с серером
    if(con != nullptr && con.get() != nullptr) {
        con->registerDisconnectEvent(disconnectHandler);
        const std::string salt(Botan::base64_encode(Botan::system_rng().random_vec(10)));
        const std::string signature(Botan::base64_encode(Botan::SHA_256().process(name.toStdString() + salt + passwordHash(pass))));
        const QString initArg(QString::fromStdString(salt + ";" + signature));
        QByteArray res((initMessage.arg(name).arg(initArg.size()).arg(initArg)).toUtf8());
        con->read(std::bind(&Protocol::initHandler, this, std::placeholders::_1));
        con->write(res);
    } else {
        globalLog.addLog(Loger::L_ERROR, "Error, can not open connection for init in server ", ip.toStdString());
        if(disconnectHandler != nullptr) disconnectHandler();
    }
}

void Protocol::reg(const QString &pass) {
    password = pass;
    globalLog.addLog(Loger::L_TRACE, "Try open connection for registered in Protocol");
    con = std::shared_ptr<middlewareInterface>(ConnectionFactory::makeTCP(ip, port, 1000)); // Создаем соединение с серером
    if(con != nullptr && con.get() != nullptr) {
        con->registerDisconnectEvent(disconnectHandler);
        const QString registerArg = QString::fromStdString(passwordHash(pass));
        QByteArray res((registerMessage.arg(name).arg(registerArg.size()).arg(registerArg)).toUtf8());
        con->read(std::bind(&Protocol::registerHandler, this, std::placeholders::_1));
        con->write(res);
    } else {
        globalLog.addLog(Loger::L_ERROR, "Error, can not open connection for register in server ", ip.toStdString());
        if(disconnectHandler != nullptr) disconnectHandler();
    }
}

void Protocol::connectTo(const QString &who) {
    globalLog.addLog(Loger::L_TRACE, "Protocol::connectTo ", who.toStdString());
    if(isOnline.load() && con != nullptr && con.get() != nullptr) {
        to = who;
        QByteArray req(connectMessage.arg(name).arg(to).toUtf8());
        con->read(std::bind(&Protocol::connectHandler, this, std::placeholders::_1));
        con->write(req);
    } else {
        globalLog.addLog(Loger::L_ERROR, "Not connected error init at first ");
        if(disconnectHandler != nullptr) disconnectHandler();
    }
}

void Protocol::disconnect(){
    globalLog.addLog(Loger::L_TRACE, "Protocol::disconnect");
    to.clear();
    isOnline.store(false);
    isConnected.store(false);
}

void Protocol::write(const QByteArray& message) {
    globalLog.addLog(Loger::L_TRACE, "Set read callback in Protocol");
    if(con != nullptr && con.get() != nullptr) { // Если соединение существует
        if(isConnected.load() && con != nullptr && con.get() != nullptr){
            QByteArray res(dataCMD.arg(name).arg(to).arg(message.size(),64,16).toUtf8());
            res.append(message);
            con->write(res);
        }else if(isOnline.load()) {
            if(!to.isEmpty()) {
                connectTo(to);
            }
        } else {
            globalLog.addLog(Loger::L_WARNING, "Disconnected from remote host");
        }
    } else {
        globalLog.addLog(Loger::L_ERROR, "Connection is null in Protocol::write");
    }
}

void Protocol::read(std::function<void (const QByteArray)> handler) {
    globalLog.addLog(Loger::L_TRACE, "Set read callback in Protocol");
    readHandler = [this, handler](const QByteArray buff) {
        auto headerEndPos = buff.indexOf("###");
        if(headerEndPos > 0) {
            QString header(buff.mid(0,headerEndPos));
            auto args = header.split(";");
            QString from = args.at(1);
            QString to = args.at(2);
            QString cmd = args.at(3);
            QString size = args.at(4);
            if(from != this->to) {
                globalLog.addLog(Loger::L_ERROR, " Saved to and received from not equal ", this->to.toStdString(), from.toStdString());
            }
            size.toULong(Q_NULLPTR,16);
            cmd.toULong(Q_NULLPTR,16);
            if( cmd != 8) {
                globalLog.addLog(Loger::L_ERROR, " Command incorrect 8 != ", cmd.toStdString());
            }
            if(handler != nullptr) handler(buff.mid(headerEndPos+3));
        } else {
            globalLog.addLog(Loger::L_ERROR, "Incorrect data");
        }

    };
    if(con != nullptr && con.get() != nullptr)  con->read(readHandler);
}

void Protocol::registerDisconnectEvent(std::function<void ()> handler) {
    this->disconnectHandler = [this, handler]() {
        this->isOnline.store(false);
        this->isConnected.store(false);
        if(handler != nullptr) handler();
    };
    if(con != nullptr && con.get() != nullptr) con->registerDisconnectEvent(this->disconnectHandler);
}
