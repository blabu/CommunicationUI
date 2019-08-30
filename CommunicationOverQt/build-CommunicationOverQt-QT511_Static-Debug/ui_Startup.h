/********************************************************************************
** Form generated from reading UI file 'Startup.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUP_H
#define UI_STARTUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartUp
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *baseLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *IP;
    QLabel *label_3;
    QLineEdit *Port;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *login;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *pass;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *loginBtn;
    QPushButton *registerBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *StartUp)
    {
        if (StartUp->objectName().isEmpty())
            StartUp->setObjectName(QStringLiteral("StartUp"));
        StartUp->resize(346, 182);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StartUp->sizePolicy().hasHeightForWidth());
        StartUp->setSizePolicy(sizePolicy);
        StartUp->setFocusPolicy(Qt::TabFocus);
        verticalLayout_2 = new QVBoxLayout(StartUp);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        baseLayout = new QVBoxLayout();
        baseLayout->setObjectName(QStringLiteral("baseLayout"));
        baseLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        IP = new QLineEdit(StartUp);
        IP->setObjectName(QStringLiteral("IP"));

        horizontalLayout_4->addWidget(IP);

        label_3 = new QLabel(StartUp);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        Port = new QLineEdit(StartUp);
        Port->setObjectName(QStringLiteral("Port"));
        Port->setMaxLength(6);

        horizontalLayout_4->addWidget(Port);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        baseLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        login = new QLineEdit(StartUp);
        login->setObjectName(QStringLiteral("login"));

        horizontalLayout_3->addWidget(login);

        label_2 = new QLabel(StartUp);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        baseLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        pass = new QLineEdit(StartUp);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(pass);

        label = new QLabel(StartUp);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        baseLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        loginBtn = new QPushButton(StartUp);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));

        horizontalLayout->addWidget(loginBtn);

        registerBtn = new QPushButton(StartUp);
        registerBtn->setObjectName(QStringLiteral("registerBtn"));

        horizontalLayout->addWidget(registerBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        baseLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(baseLayout);


        retranslateUi(StartUp);

        QMetaObject::connectSlotsByName(StartUp);
    } // setupUi

    void retranslateUi(QWidget *StartUp)
    {
        StartUp->setWindowTitle(QApplication::translate("StartUp", "Init", nullptr));
        IP->setText(QApplication::translate("StartUp", "127.0.0.1", nullptr));
        IP->setPlaceholderText(QApplication::translate("StartUp", "IP address", nullptr));
        label_3->setText(QApplication::translate("StartUp", ":", nullptr));
        Port->setText(QApplication::translate("StartUp", "3555", nullptr));
        Port->setPlaceholderText(QApplication::translate("StartUp", "internet port", nullptr));
        login->setPlaceholderText(QApplication::translate("StartUp", "Login", nullptr));
        label_2->setText(QApplication::translate("StartUp", "Login", nullptr));
        pass->setPlaceholderText(QApplication::translate("StartUp", "Password", nullptr));
        label->setText(QApplication::translate("StartUp", "Password", nullptr));
        loginBtn->setText(QApplication::translate("StartUp", "Login", nullptr));
        registerBtn->setText(QApplication::translate("StartUp", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartUp: public Ui_StartUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUP_H
