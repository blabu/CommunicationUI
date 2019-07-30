#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <QString>
#include <QEvent>
#include <QMutex>
#include <atomic>
#include "credentials.hpp"

namespace Ui {
class MainWindow;
}

#include <QTimer>
class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void initButtonPressed();
    void connectButtonPressed();
    void showText(const QString& m, bool isSendedByMe);
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void TryConnect(const Credentials& ctx);
    void TryInit(const Credentials& ctx);
    void pressedDisconnect();
    void sendTextMessages(QString msg);
public slots:
    void newTextMessageReceived(const QString& message);
    void disconnect();
    void connectionFine();
    void initFine();
private:
    Ui::MainWindow *ui;
    QMutex uiMtx;
    Credentials cr;
    std::atomic<bool> isConnected;
    bool checkBaseCredential();
protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
