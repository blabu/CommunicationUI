#ifndef READWRITETCP_HPP
#define READWRITETCP_HPP

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <memory>
#include <atomic>
#include <mutex>

#include "MainProjectLoger.hpp"
#include "middlewareInterface.hpp"

class ReadWriteTcp: public QObject, public middlewareInterface {
    Q_OBJECT
private:
    QMetaObject::Connection disconectHandler;
    std::shared_ptr<QTcpSocket> socket;
    std::mutex readFuncMtx;
    std::function<void(const QByteArray)> readCallBack;
private slots:
    void readHandler();
    void closeConnectionHandler();
public:
    ReadWriteTcp(std::shared_ptr<QTcpSocket> sock);
    virtual ~ReadWriteTcp();
public slots:
    void write(const QByteArray& m);
    void read(std::function<void( QByteArray)> handler);
    void registerDisconnectEvent(std::function<void(void)> handler);
};

#endif // READWRITETCP_HPP
