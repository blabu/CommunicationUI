#include "ReadWriteTcp.hpp"
#include "MainProjectLoger.hpp"

ReadWriteTcp::ReadWriteTcp(std::shared_ptr<QTcpSocket> sock): socket(sock), isConnected(true) {
    QObject::connect(socket.get(), SIGNAL(readyRead()),this, SLOT(readHandler()));
}

ReadWriteTcp::~ReadWriteTcp() {
    globalLog.addLog(Loger::L_INFO, "Close socket");
    QObject::disconnect(disconectHandler);
    closeConnectionHandler();
    if(socket->isOpen()) socket->close();
}

void ReadWriteTcp::read(std::function<void(const QByteArray)>handler) {
    globalLog.addLog(Loger::L_TRACE, "Register read call back ");
    readFuncMtx.lock();
    readCallBack = handler;
    readFuncMtx.unlock();
}

void ReadWriteTcp::readHandler() {
    auto result = socket->readAll();
    readFuncMtx.lock();
    auto func = this->readCallBack;
    readFuncMtx.unlock();
    try {
        if(func != nullptr) {
            func(result);
        } else {
            globalLog.addLog(Loger::L_INFO, "Read function does not excist");
        }
    }catch (std::bad_function_call) {
        globalLog.addLog(Loger::L_ERROR, "Read function is invalid it must be void(const QByteArray) signature");
    }
}

void ReadWriteTcp::registerDisconnectEvent(std::function<void ()> handler) {
    disconectHandler = QObject::connect(socket.get(), &QTcpSocket::disconnected, [handler](){
        try {
            if(handler != nullptr) {
                globalLog.addLog(Loger::L_TRACE, "Disconect handler called");
                handler();
            } else {
                globalLog.addLog(Loger::L_INFO, "Disconnect function does not excist");
            }
        }catch (std::bad_function_call) {
            globalLog.addLog(Loger::L_ERROR, "Disconnect function is invalid it must be void(void) signature");
        }
    });
    QObject::connect(socket.get(), SIGNAL(disconnected()), this, SLOT(closeConnectionHandler()));
    globalLog.addLog(Loger::L_TRACE, "Register disconect call back ");
}

void ReadWriteTcp::write(const QByteArray &m) {
    if(isConnected.load() && socket->isOpen()) socket->write(m);
}

void ReadWriteTcp::closeConnectionHandler() {
    QObject::disconnect(socket.get(), SIGNAL(readyRead()),this, SLOT(readHandler()));
    QObject::disconnect(socket.get(), SIGNAL(disconnected()), this, SLOT(closeConnectionHandler()));
    isConnected.store(false);
    globalLog.addLog(Loger::L_TRACE, "closeConnectionHandler executes");
}
