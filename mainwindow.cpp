#include "mainwindow.h"
#include "MainProjectLoger.hpp"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QKeyEvent>
#include <QGraphicsSimpleTextItem>

//Обработчик по нажатию кнопок
void MainWindow::keyPressEvent(QKeyEvent *event){
    auto key = event->key();
    globalLog.addLog(Loger::L_INFO, "Button ", std::to_string(key), " is pressed");
    if(key == Qt::Key::Key_Enter || key == Qt::Key::Key_Return) {
        if(isConnected.load()) {
            auto text = ui->transmitMsg->text();
            showText(text, true);
            emit sendText(text);
        } else {
            connectButtonPressed();
        }
    }
}

void MainWindow::connectButtonPressed() {
    cr.password = ui->password->text();
    cr.identifierTo = ui->Identifier->text();
    if(!cr.password.isEmpty() && !cr.identifierTo.isEmpty()) emit tryConnect(cr);
}

void MainWindow::showText(const QString &m, bool isSendedByMe){
    uiMtx.lock();
    ui->receivedMsg->append(m);
    if(isSendedByMe) {
        ui->receivedMsg->setAlignment(Qt::AlignRight);
        ui->transmitMsg->clear();
    }
    else ui->receivedMsg->setAlignment(Qt::AlignRight);
    uiMtx.unlock();
}

void MainWindow::receiveText(const QString& message) {
    showText(message, false);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QObject::connect(ui->Connect, SIGNAL(pressed()), this, SLOT(connectButtonPressed()));
    QObject::connect(ui->Disconnect, SIGNAL(pressed()), this, SLOT(disconnect()));
    QObject::connect(ui->Disconnect, &QPushButton::pressed, [this](){emit pressedDisconnect();});
    disconnect();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::disconnect() {
    ui->password->setReadOnly(false);
    ui->Identifier->setReadOnly(false);
    ui->transmitMsg->setReadOnly(true);
    ui->Connect->setEnabled(true);
    ui->Disconnect->setEnabled(false);
    isConnected.store(false);
    globalLog.addLog(Loger::L_INFO, "Ui Disconnect slot");
}

void MainWindow::connectionFine() {
    ui->password->setReadOnly(true);
    ui->Identifier->setReadOnly(true);
    ui->transmitMsg->setReadOnly(false);
    ui->Connect->setEnabled(false);
    ui->Disconnect->setEnabled(true);
    isConnected.store(true);
    globalLog.addLog(Loger::L_INFO, "Connection fine!!!!");
}
