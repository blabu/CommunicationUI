#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QEvent>
#include <QMutex>
#include <atomic>
#include "credentials.hpp"
#include "sendProperties.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void connectButtonPressed();
    void showText(const QString& m, bool isSendedByMe);
    void sendPropSlot(ModemProperties modem);
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setUserID(const QString& id, const QString& pass) { this->setWindowTitle("Welcome " + id); cr.id = id; cr.password = pass;}
    void setServer(const QString& ip, const QString& port) {cr.serverAddr=ip; cr.serverPort=port;}
signals:
    void tryConnect(const Credentials& ctx);
    void pressedDisconnect();
    void sendText(QString msg);
    void sessionKeyChanged(const QString&);
    void sendEverybody();
    void sendPropSignal(ModemProperties m);
public slots:
    void receiveText(const QString& message);
    void disconnect();
    void connectionFine();
    void connectBy(const QString &userName);
private:
    Ui::MainWindow *ui;
    sendProperties *properties;
    QMutex uiMtx;
    Credentials cr;
    std::atomic<bool> isConnected;
    void sendLastText();
protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
