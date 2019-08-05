#include "Protocol.h"
#include "ConnectionFactory.hpp"

const QString Protocol::registerMessage("$V1;%1;0;3;%2###%3"); // local name, message size, BASE64((SHA256(name + password))
const QString Protocol::initMessage("$V1;%1;0;5;%2###%3"); // local name, message size, (salt + ; + BASE64(SHA256(name + salt + BASE64(SHA256(name + password)))
const QString Protocol::initOkMessage("$V1;0;%1;5;8###INIT OK;"); // local name
const QString Protocol::connectMessage("$V1;%1;%2;7;0###"); //local name, to name
const QString Protocol::connectOkMessage("$V1;%1;%2;7;B###CONNECT OK;"); // to name, local name
const QString Protocol::pingCMD("$V1;%1;0;2;0###"); // local name
const QString Protocol::dataCMD("$V1;%1;%2;8;%3###"); //local name, to, message size

Protocol::Protocol(const QString &name, const QString &ip, const QString &port, QObject *parent) : QObject(parent), name(name)
{
    con = std::shared_ptr<middlewareInterface>(ConnectionFactory::makeTCP(ip, port, 1000));
}

void Protocol::init(const QString &pass) {

}

void Protocol::write(const QByteArray& message) {
    if(con != nullptr && con.get() != nullptr) {
        if(isConnected.load()){
            QByteArray res(dataCMD.arg(name).arg(to).arg(message.size(),64,16).toUtf8());
            res.append(message);
            con->write(res);
        }
    }
}
