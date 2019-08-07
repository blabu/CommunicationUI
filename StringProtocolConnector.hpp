#ifndef PROTOCOLBASE_HPP
#define PROTOCOLBASE_HPP

#include <QObject>
#include "MainProjectLoger.hpp"
#include "credentials.hpp"
#include "Protocol.h"
#include <atomic>

class StringProtocolConnector : public QObject {
    Q_OBJECT
private:
    std::shared_ptr<Protocol> proto;
    std::shared_ptr<middlewareInterface> con;
    Credentials cr;
    QMetaObject::Connection initCallBackConnection;
    QMetaObject::Connection regCallBackConnection;
    QMetaObject::Connection connectCallBackConnection;
    void readHandler(const QByteArray b);
public:
    explicit StringProtocolConnector(QObject *parent = nullptr);
    ~StringProtocolConnector() {globalLog.addLog(Loger::L_TRACE, "Destroy StringProtocolConnector");}
signals:
    void initOk();
    void registerOk();
    void connectOk();
    void registerFail();
    void initFail();
    void disconnectedRemoteSignal();
    void received(QString m);
public slots:
    void init(const Credentials& cr);
    void registered(const Credentials& cr);
    void connect(const Credentials& cr);
    void write(const QString& message);
    void close();
};

#endif // PROTOCOLBASE_HPP
