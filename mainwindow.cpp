#include "mainwindow.h"
#include "MainProjectLoger.hpp"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QKeyEvent>
#include <QGraphicsSimpleTextItem>

bool MainWindow::checkBaseCredential(){
    if(ui->IP->text().isNull() || ui->IP->text().isEmpty()) { ui->IP->setStyleSheet("border: 1px solid red"); return false; }
    if(ui->Port->text().isNull() || ui->Port->text().isEmpty()) { ui->Port->setStyleSheet("border: 1px solid red"); return false; }
    if(ui->Id->text().isNull() || ui->Id->text().isEmpty()) { ui->Id->setStyleSheet("border: 1px solid red"); return false; }
    ui->Id->setStyleSheet("border : solid black");
    ui->Port->setStyleSheet("border : solid black");
    ui->IP->setStyleSheet("border : solid black");
    return true;
}

//Обработчик по нажатию кнопок
void MainWindow::keyPressEvent(QKeyEvent *event){
    auto key = event->key();
    globalLog.addLog(Loger::L_INFO, "Button ", std::to_string(key), " is pressed");
    if(key == Qt::Key::Key_Enter || key == Qt::Key::Key_Return) {
        if(isConnected.load()) {
            auto text = ui->transmitMsg->text();
            showText(text, true);
            emit sendTextMessages(text);
        } else {
            if(ui->Identifier->text().isNull() || ui->Identifier->text().isEmpty() ||
                    ui->password->text().isNull() || ui->password->text().isEmpty()) {
                initButtonPressed();
            } else {
                connectButtonPressed();
            }
        }
    }
}

// Check all input value and emmit signal
void MainWindow::initButtonPressed(){
    if(checkBaseCredential()) {
        cr.id = ui->Id->text();
        cr.password = ui->password->text();
        cr.serverAddr = ui->IP->text();
        cr.serverPort = ui->Port->text();
        ui->Identifier->clear();
        emit TryInit(cr);
    }
}

void MainWindow::connectButtonPressed() {
    if(checkBaseCredential()) {
        cr.id = ui->Id->text();
        cr.password = ui->password->text();
        cr.serverAddr = ui->IP->text();
        cr.serverPort = ui->Port->text();
        cr.identifierTo = ui->Identifier->text();
        emit TryConnect(cr);
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

void MainWindow::newTextMessageReceived(const QString& message) {
    showText(message, false);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QObject::connect(ui->Init, SIGNAL(pressed()), this, SLOT(initButtonPressed()));
    QObject::connect(ui->Connect, SIGNAL(pressed()), this, SLOT(connectButtonPressed()));
    QObject::connect(ui->Disconnect, SIGNAL(pressed()), this, SLOT(disconnect()));
    QObject::connect(ui->Disconnect, &QPushButton::pressed, [this](){emit pressedDisconnect();});
    disconnect();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::disconnect() {
    ui->IP->setReadOnly(false);
    ui->Port->setReadOnly(false);
    ui->Id->setReadOnly(false);
    ui->password->setReadOnly(false);
    ui->Identifier->setReadOnly(false);

    ui->transmitMsg->setReadOnly(true);

    ui->Connect->setEnabled(true);
    ui->Init->setEnabled(true);
    ui->Disconnect->setEnabled(false);
    isConnected.store(false);
}

void MainWindow::connectionFine() {
    ui->IP->setReadOnly(true);
    ui->Port->setReadOnly(true);
    ui->Id->setReadOnly(true);
    ui->password->setReadOnly(true);
    ui->Identifier->setReadOnly(true);
    ui->transmitMsg->setReadOnly(false);
    ui->Connect->setEnabled(false);
    ui->Init->setEnabled(false);
    ui->Disconnect->setEnabled(true);
    isConnected.store(true);
    globalLog.addLog(Loger::L_INFO, "Connection fine!!!!");
}

void MainWindow::initFine() {
    ui->IP->setReadOnly(true);
    ui->Port->setReadOnly(true);
    ui->Id->setReadOnly(true);
    ui->Init->setEnabled(false);
    ui->Disconnect->setEnabled(true);
}
