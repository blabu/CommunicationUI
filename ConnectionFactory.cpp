#include "ConnectionFactory.hpp"
#include "MainProjectLoger.hpp"
#include <QString>
#include <QEventLoop>
#include <QTimer>

ReadWriteTcp* ConnectionFactory::makeTCP(const QString ip, const QString port, int msTimeout) {
    QString serverAddr = ip;
    std::uint16_t serverPort = static_cast<unsigned short>(port.toInt());
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
