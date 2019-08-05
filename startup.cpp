#include "startup.hpp"
#include "ui_Startup.h"
#include "MainProjectLoger.hpp"

StartUp::StartUp(MainWindow *w, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartUp)
{
    ui->setupUi(this);
    this->setWindowTitle("Init");
    window = w;
    window->hide();
    QObject::connect(ui->pass, &QLineEdit::textEdited, [this](){this->ui->pass->setStyleSheet("border: solid black");});
    QObject::connect(ui->loginBtn, SIGNAL(pressed()), this, SLOT(init()));
    QObject::connect(ui->registerBtn, SIGNAL(pressed()), this, SLOT(reg()));
}

StartUp::~StartUp() {
    delete ui;
}

void StartUp::enableMainWindow() {
    this->hide();
    window->setUserID(ctx.id, ctx.password);
    window->setServer(ctx.serverAddr, ctx.serverPort);
    window->show();
    return;
}
void StartUp::disableMainWindow() {
    window->hide();
    window->disconnect();
    window->setUserID(QString(), QString());
    window->setServer(QString(),QString());
    ui->loginBtn->setEnabled(true);
    ui->registerBtn->setEnabled(true);
    ui->pass->clear();
    ui->pass->setStyleSheet("border: 1px solid red");
    this->show();
}

bool StartUp::checkBaseCredential() {
    if(ui->IP->text().isNull()    || ui->IP->text().isEmpty())   { ui->IP->setStyleSheet("border: 1px solid red");    return false;}
    if(ui->Port->text().isNull()  || ui->Port->text().isEmpty()) { ui->Port->setStyleSheet("border: 1px solid red");  return false;}
    if(ui->login->text().isNull() || ui->login->text().isEmpty()){ ui->login->setStyleSheet("border: 1px solid red"); return false;}
    if(ui->pass->text().isNull()  || ui->pass->text().isEmpty()) { ui->pass->setStyleSheet("border: 1px solid red");  return false;}
    ui->login->setStyleSheet("border : solid black");
    ui->pass->setStyleSheet("border : solid black");
    ui->Port->setStyleSheet("border : solid black");
    ui->IP->setStyleSheet("border : solid black");
    return true;
}

void StartUp::init() {
    if(checkBaseCredential()) {
        globalLog.addLog(Loger::L_TRACE, "startUp Try init");
        ctx.id = ui->login->text();
        ctx.password = ui->pass->text();
        ctx.serverAddr = ui->IP->text();
        ctx.serverPort = ui->Port->text();
        ui->loginBtn->setEnabled(false);
        ui->registerBtn->setEnabled(false);
        emit tryInit(ctx);
    }
}

void StartUp::reg() {
    if(checkBaseCredential()) {
        globalLog.addLog(Loger::L_TRACE, "startUp Try register");
        ctx.id = ui->login->text();
        ctx.password = ui->pass->text();
        ctx.serverAddr = ui->IP->text();
        ctx.serverPort = ui->Port->text();
        ui->loginBtn->setEnabled(false);
        ui->registerBtn->setEnabled(false);
        emit tryRegister(ctx);
    }
}
