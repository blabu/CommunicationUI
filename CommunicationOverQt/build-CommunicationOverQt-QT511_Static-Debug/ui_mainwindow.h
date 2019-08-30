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
    QLineEdit *sessionKey;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *Identifier;
    QPushButton *Connect;
    QPushButton *Disconnect;
    QSpacerItem *horizontalSpacer_5;
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
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
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
        sessionKey->setPlaceholderText(QApplication::translate("MainWindow", "session password", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Credentials", nullptr));
        Identifier->setPlaceholderText(QApplication::translate("MainWindow", "Connect to identifier", nullptr));
        Connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        Disconnect->setText(QApplication::translate("MainWindow", "Disconnect", nullptr));
        transmitMsg->setPlaceholderText(QApplication::translate("MainWindow", "Compose message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
