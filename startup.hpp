#ifndef STARTUP_HPP
#define STARTUP_HPP

#include <QWidget>
#include <mainwindow.h>
#include <QKeyEvent>

namespace Ui {
class StartUp;
}

class StartUp : public QWidget
{
    Q_OBJECT
public:
    explicit StartUp(MainWindow* w, QWidget *parent = nullptr);
    ~StartUp();
signals:
    void tryRegister(const Credentials& ctx);
    void tryInit(const Credentials& ctx);
public slots:
    void enableMainWindow();
    void disableMainWindow();
private:
    Credentials ctx;
    Ui::StartUp *ui;
    MainWindow* window;
    bool checkBaseCredential();
private slots:
    void init();
    void reg();
protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // STARTUP_HPP
