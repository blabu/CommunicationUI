/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *indicator;
    QSpacerItem *horizontalSpacer;
    QPushButton *sendEverybody;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *base;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *base64;
    QLineEdit *sessionKey;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *Identifier;
    QPushButton *Connect;
    QPushButton *Disconnect;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label;
    QLineEdit *baudrate;
    QLabel *label_3;
    QLineEdit *rs232Timeout;
    QLabel *label_4;
    QLineEdit *modemTimeout;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_5;
    QLineEdit *newServer;
    QPushButton *sendProp;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_2;
    QTextBrowser *receivedMsg;
    QSpacerItem *verticalSpacer;
    QLineEdit *transmitMsg;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(659, 517);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        indicator = new QRadioButton(centralWidget);
        indicator->setObjectName(QStringLiteral("indicator"));
        indicator->setEnabled(false);

        horizontalLayout->addWidget(indicator);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sendEverybody = new QPushButton(centralWidget);
        sendEverybody->setObjectName(QStringLiteral("sendEverybody"));

        horizontalLayout->addWidget(sendEverybody);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        base = new QVBoxLayout();
        base->setSpacing(6);
        base->setObjectName(QStringLiteral("base"));
        base->setSizeConstraint(QLayout::SetMaximumSize);
        base->setContentsMargins(0, -1, -1, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        base->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        base64 = new QCheckBox(centralWidget);
        base64->setObjectName(QStringLiteral("base64"));

        horizontalLayout_3->addWidget(base64);

        sessionKey = new QLineEdit(centralWidget);
        sessionKey->setObjectName(QStringLiteral("sessionKey"));
        sessionKey->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(sessionKey);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);


        base->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        Identifier = new QLineEdit(centralWidget);
        Identifier->setObjectName(QStringLiteral("Identifier"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Identifier->sizePolicy().hasHeightForWidth());
        Identifier->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(Identifier);

        Connect = new QPushButton(centralWidget);
        Connect->setObjectName(QStringLiteral("Connect"));

        horizontalLayout_4->addWidget(Connect);

        Disconnect = new QPushButton(centralWidget);
        Disconnect->setObjectName(QStringLiteral("Disconnect"));

        horizontalLayout_4->addWidget(Disconnect);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        base->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        baudrate = new QLineEdit(centralWidget);
        baudrate->setObjectName(QStringLiteral("baudrate"));

        horizontalLayout_5->addWidget(baudrate);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        rs232Timeout = new QLineEdit(centralWidget);
        rs232Timeout->setObjectName(QStringLiteral("rs232Timeout"));

        horizontalLayout_5->addWidget(rs232Timeout);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        modemTimeout = new QLineEdit(centralWidget);
        modemTimeout->setObjectName(QStringLiteral("modemTimeout"));

        horizontalLayout_5->addWidget(modemTimeout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        base->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        newServer = new QLineEdit(centralWidget);
        newServer->setObjectName(QStringLiteral("newServer"));

        horizontalLayout_6->addWidget(newServer);

        sendProp = new QPushButton(centralWidget);
        sendProp->setObjectName(QStringLiteral("sendProp"));

        horizontalLayout_6->addWidget(sendProp);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        base->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        base->addItem(verticalSpacer_2);

        receivedMsg = new QTextBrowser(centralWidget);
        receivedMsg->setObjectName(QStringLiteral("receivedMsg"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(receivedMsg->sizePolicy().hasHeightForWidth());
        receivedMsg->setSizePolicy(sizePolicy1);

        base->addWidget(receivedMsg);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        base->addItem(verticalSpacer);

        transmitMsg = new QLineEdit(centralWidget);
        transmitMsg->setObjectName(QStringLiteral("transmitMsg"));
        transmitMsg->setInputMask(QStringLiteral(""));

        base->addWidget(transmitMsg);


        gridLayout->addLayout(base, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 659, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        indicator->setText(QApplication::translate("MainWindow", "Offline", nullptr));
        sendEverybody->setText(QApplication::translate("MainWindow", "Publish for all", nullptr));
        base64->setText(QApplication::translate("MainWindow", "Base64", nullptr));
        sessionKey->setPlaceholderText(QApplication::translate("MainWindow", "session password", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Credentials", nullptr));
        Identifier->setPlaceholderText(QApplication::translate("MainWindow", "Connect to identifier", nullptr));
        Connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        Disconnect->setText(QApplication::translate("MainWindow", "Disconnect", nullptr));
        label->setText(QApplication::translate("MainWindow", "RS232 speed", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "RS232 timeout", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Modem timout", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Server IP", nullptr));
        sendProp->setText(QApplication::translate("MainWindow", "SendProperties", nullptr));
        transmitMsg->setPlaceholderText(QApplication::translate("MainWindow", "Compose message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
