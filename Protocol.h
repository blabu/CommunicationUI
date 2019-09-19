#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QObject>
#include "middlewareInterface.hpp"
#include <atomic>
#include <memory>
#include <MainProjectLoger.hpp>

#include <QTimer>
class ping : public QObject {
    Q_OBJECT
private:
    const int pingTime;
    const QString pingCMD;
    const QString pingAnswer;
    QTimer p;
    std::shared_ptr<middlewareInterface> con;
public:
    ping(QString pingCommand, QString pingAnswer, std::shared_ptr<middlewareInterface> con) :
        pingTime(60000),
        pingCMD(pingCommand),
        pingAnswer(pingAnswer),
        con(con) {
        QObject::connect(&p, &QTimer::timeout, [this](){this->con->write(this->pingCMD.toUtf8());});
        con->read([this](const QByteArray data) {
            if(!QString(data).contains(this->pingAnswer)) emit this->remoteConnect();
        });
        p.start(pingTime);
    }
    ~ping() {
        p.stop();
        globalLog.addLog(Loger::L_TRACE, "Delete ping task");
    }
signals:
    void remoteConnect();
};

class Protocol : public QObject, public middlewareInterface
{
    Q_OBJECT
private:
    static const QString registerMessage;
    static const QString registerOkMessage;
    static const QString initMessage;
    static const QString initOkMessage;
    static const QString connectMessage;
    static const QString connectOkMessage;
    static const QString pingCMD;
    static const QString dataCMD;
    static const QString disconnectCMD;
    static const QString propertiesCMD;
    const QString ip;
    const QString port;
    const QString name;
    QString password;
    QString to;
    std::shared_ptr<middlewareInterface> con;
    std::shared_ptr<ping> pingTask;
    std::atomic<bool> isOnline;
    std::atomic<bool> isConnected;

    const std::string passwordHash(QString pass)const ;
    std::function<void(void)> disconnectHandler;
    std::function<void(const QByteArray)> readHandler;
    //Обработчики служебных сообщений
    void initHandler(const QByteArray b);
    void connectHandler(const QByteArray b);
    void registerHandler(const QByteArray b);
public:
    explicit Protocol(const QString& name, const QString& ip, const QString& port, QObject *parent = nullptr);
    virtual ~Protocol()=default;
    void init(const QString& pass);
    void reg(const QString& pass);
    void connectTo(const QString& who);
    void destroyConnection();
    void sendProperties(const ModemProperties& prop);
    QString getTo() {return to;}
    void setTo(const QString& to) {this->to = to;}
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
