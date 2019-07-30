#include "ConnectionFactory.hpp"
#include "MainProjectLoger.hpp"
#include <QString>
#include <QEventLoop>
#include <QTimer>

ReadWriteTcp* ConnectionFactory::makeTCP(const Credentials &cr, int msTimeout) {
    QString serverAddr = cr.serverAddr;
    std::uint16_t serverPort = static_cast<unsigned short>(cr.serverPort.toInt());
    auto socket = std::shared_ptr<QTcpSocket>(new QTcpSocket());
    socket->connectToHost(serverAddr, serverPort);
    QTimer timer;
    timer.setSingleShot(true);
    QEventLoop loop;
    QObject::connect(socket.get(), &QTcpSocket::connected, &loop, &QEventLoop::quit);
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit );
    timer.start(msTimeout);
    loop.exec();
    if(timer.isActive()) {
        globalLog.addLog(Loger::L_TRACE, "Connection establish");
        return new ReadWriteTcp(socket);
    }
    return nullptr;
}
