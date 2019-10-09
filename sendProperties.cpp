#include "sendProperties.hpp"
#include "ui_sendproperties.h"
#include "MainProjectLoger.hpp"

sendProperties::sendProperties(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::sendProperties) {
    ui->setupUi(this);
    QObject::connect(ui->cancel, &QPushButton::pressed, [this](){
        ui->newServer->clear();
        ui->modemTimeout->clear();
        ui->rs232Timeout->clear();
        ui->baudrate->clear();
        emit this->cancelPressed();
    });
    QObject::connect(ui->sendProp, SIGNAL(pressed()), this, SLOT(send()));
}

sendProperties::~sendProperties() {
    delete ui;
}

void sendProperties::send() {
    globalLog.addLog(Loger::L_TRACE, "Send properties is pressed");
    ModemProperties modem;
    modem.baudrate = ui->baudrate->text();
    modem.modemTimeout = ui->modemTimeout->text();
    modem.rs232Timeout = ui->rs232Timeout->text();
    modem.serverIP = ui->newServer->text();
    ui->newServer->clear();
    ui->modemTimeout->clear();
    ui->rs232Timeout->clear();
    ui->baudrate->clear();
    emit(sendPressed(modem));
}


