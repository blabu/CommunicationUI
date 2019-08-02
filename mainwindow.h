#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QEvent>
#include <QMutex>
#include <atomic>
#include "credentials.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void connectButtonPressed();
    void showText(const QString& m, bool isSendedByMe);
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setUserID(const QString& id) { this->setWindowTitle("Welcome " + id); cr.id = id; }
    void setServer(const QString& ip, const QString& port) {cr.serverAddr=ip; cr.serverPort=port;}
signals:
    void tryConnect(const Credentials& ctx);
    void pressedDisconnect();
    void sendText(QString msg);
public slots:
    void receiveText(const QString& message);
    void disconnect();
    void connectionFine();
private:
    Ui::MainWindow *ui;
    QMutex uiMtx;
    Credentials cr;
    std::atomic<bool> isConnected;
protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
