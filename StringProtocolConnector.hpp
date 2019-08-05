#ifndef PROTOCOLBASE_HPP
#define PROTOCOLBASE_HPP

#include <QObject>
#include "MainProjectLoger.hpp"
#include "credentials.hpp"
#include "ConnectionFactory.hpp"
#include <atomic>
#include <QTimer>

class StringProtocolConnector : public QObject {
    Q_OBJECT
private slots:
    void receiveFrom(QByteArray message) { emit received(QString(message)); }
    void initAck(const QByteArray& b);
    void connectAck(const QByteArray& b);
private:
    static const QString registerMessage;
    static const QString initMessage;
    static const QString initOkMessage;
    static const QString connectMessage;
    static const QString connectOkMessage;
    static const QString pingCMD;

    QTimer ping;
    QMetaObject::Connection pingConnection;
    void enablePing();
    void disablePing();

    QMetaObject::Connection startHandlerConnection;
    Credentials cr;
    std::atomic<bool> startSession;
    std::shared_ptr<middlewareInterface> con;
public:
    explicit StringProtocolConnector(QObject *parent = nullptr);
    ~StringProtocolConnector() {globalLog.addLog(Loger::L_TRACE, "Destroy StringProtocolConnector");}
signals:
    void initOk();
    void initFail();
    void registerOk();
    void registerFail();

    void disconnectedRemoteSignal();
    void connectOk();
    void received(QString m);
public slots:
    void init(const Credentials& cr);
    void registered(const Credentials& cr);
    void connect(const Credentials& cr);
    void sendTo(const QString& message);
    void close();
};

#endif // PROTOCOLBASE_HPP
