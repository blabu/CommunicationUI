#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QObject>
#include "middlewareInterface.hpp"
#include <atomic>
#include <memory>

#include <QTimer>
class ping : public QObject {
    Q_OBJECT
private:
    const QString pingCMD;
    QTimer p;
    std::shared_ptr<middlewareInterface> con;
public:
    ping(QString pingCommand, std::shared_ptr<middlewareInterface> con) : pingCMD(pingCommand), con(con) {
        QObject::connect(&p, &QTimer::timeout, [this](){this->con->write(this->pingCMD.toUtf8());});
        con->read([this](const QByteArray data) {
            if(data.at(0) == '$') return;
            emit this->remoteConnect();
        });
        p.start(600000);
    }
    ~ping() {
        p.stop();
    }
signals:
    void remoteConnect();
};

class Protocol : public QObject, public middlewareInterface
{
    Q_OBJECT
private:
    static const QString registerMessage;
    static const QString initMessage;
    static const QString initOkMessage;
    static const QString connectMessage;
    static const QString connectOkMessage;
    static const QString pingCMD;
    static const QString dataCMD;
    std::shared_ptr<middlewareInterface> con;
    const QString name;
    QString to;
    std::atomic<bool> isConnected;

    std::function<void(void)> diconnectHandler;
    std::function<void(const QByteArray)> readHandler;
public:
    explicit Protocol(const QString& name, const QString& ip, const QString& port, QObject *parent = nullptr);
    virtual ~Protocol()=default;
    void init(const QString& pass);
    void reg(const QString& pass);
    void connectTo(const QString& who);
signals:
    void regOK();
    void initOK();
    void connectToOK();
public slots:
    virtual void write(const QByteArray&message);
    virtual void read(std::function<void(const QByteArray)> handler);
    virtual void registerDisconnectEvent(std::function<void(void)> handler);
};

#endif // PROTOCOL_H
