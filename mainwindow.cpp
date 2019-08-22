#include "mainwindow.h"
#include "MainProjectLoger.hpp"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QKeyEvent>
#include <QGraphicsSimpleTextItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QObject::connect(ui->Connect, SIGNAL(pressed()), this, SLOT(connectButtonPressed()));
    QObject::connect(ui->Disconnect, SIGNAL(pressed()), this, SLOT(disconnect()));
    QObject::connect(ui->Disconnect, &QPushButton::pressed, [this](){emit pressedDisconnect();});
    QObject::connect(ui->sessionKey, &QLineEdit::textChanged, [this](const QString& str) {emit sessionKeyChanged(str); } );
    QObject::connect(ui->sendEverybody, &QPushButton::pressed, [this]() {emit sendEverybody(); this->sendLastText(); } );
    disconnect();
}

void MainWindow::sendLastText() {
    auto text = ui->transmitMsg->text();
    showText(text, true);
    emit sendText(text);
}

//Обработчик по нажатию кнопок
void MainWindow::keyPressEvent(QKeyEvent *event){
    auto key = event->key();
    globalLog.addLog(Loger::L_INFO, "Button ", std::to_string(key), " is pressed");
    if(key == Qt::Key::Key_Enter || key == Qt::Key::Key_Return) {
        if(isConnected.load()) {
            sendLastText();
        } else {
            connectButtonPressed();
        }
    }
}

void MainWindow::connectButtonPressed() {
    cr.sessionKey = ui->sessionKey->text();
    cr.identifierTo = ui->Identifier->text();
    if(!cr.identifierTo.isEmpty()) {
        globalLog.addLog(Loger::L_TRACE, "Try connect to the client ", cr.identifierTo.toStdString());
        emit tryConnect(cr);
    }
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


MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::disconnect() {
    ui->sessionKey->setReadOnly(false);
    ui->Identifier->setReadOnly(false);
    ui->transmitMsg->setReadOnly(true);
    ui->Connect->setEnabled(true);
    ui->Disconnect->setEnabled(false);
    isConnected.store(false);
    globalLog.addLog(Loger::L_INFO, "Ui Disconnect slot");
    ui->indicator->setText("Ofline");
    ui->indicator->setDown(false);
}

void MainWindow::connectionFine() {
    ui->sessionKey->setReadOnly(true);
    ui->Identifier->setReadOnly(true);
    ui->transmitMsg->setReadOnly(false);
    ui->Connect->setEnabled(false);
    ui->Disconnect->setEnabled(true);
    isConnected.store(true);
    ui->indicator->setText("Online by " + ui->Identifier->text());
    ui->indicator->setDown(true);
    globalLog.addLog(Loger::L_INFO, "Connection fine!!!!");
}

void MainWindow::connectBy(const QString& userName) {
    ui->Identifier->setText(userName);
    connectionFine();
}
