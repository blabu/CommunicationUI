/********************************************************************************
** Form generated from reading UI file 'sendproperties.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDPROPERTIES_H
#define UI_SENDPROPERTIES_H

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

class Ui_sendProperties
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *newServer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *baudrate;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLineEdit *modemTimeout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLineEdit *rs232Timeout;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *sendProp;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *sendProperties)
    {
        if (sendProperties->objectName().isEmpty())
            sendProperties->setObjectName(QStringLiteral("sendProperties"));
        sendProperties->resize(319, 284);
        verticalLayoutWidget = new QWidget(sendProperties);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 301, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        newServer = new QLineEdit(verticalLayoutWidget);
        newServer->setObjectName(QStringLiteral("newServer"));

        horizontalLayout_4->addWidget(newServer);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        baudrate = new QLineEdit(verticalLayoutWidget);
        baudrate->setObjectName(QStringLiteral("baudrate"));

        horizontalLayout->addWidget(baudrate);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        modemTimeout = new QLineEdit(verticalLayoutWidget);
        modemTimeout->setObjectName(QStringLiteral("modemTimeout"));

        horizontalLayout_3->addWidget(modemTimeout);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        rs232Timeout = new QLineEdit(verticalLayoutWidget);
        rs232Timeout->setObjectName(QStringLiteral("rs232Timeout"));

        horizontalLayout_2->addWidget(rs232Timeout);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayoutWidget_5 = new QWidget(sendProperties);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 230, 299, 35));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        sendProp = new QPushButton(horizontalLayoutWidget_5);
        sendProp->setObjectName(QStringLiteral("sendProp"));

        horizontalLayout_7->addWidget(sendProp);

        cancel = new QPushButton(horizontalLayoutWidget_5);
        cancel->setObjectName(QStringLiteral("cancel"));

        horizontalLayout_7->addWidget(cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        retranslateUi(sendProperties);

        QMetaObject::connectSlotsByName(sendProperties);
    } // setupUi

    void retranslateUi(QWidget *sendProperties)
    {
        sendProperties->setWindowTitle(QApplication::translate("sendProperties", "Form", nullptr));
        label_8->setText(QApplication::translate("sendProperties", "Server IP", nullptr));
        label_2->setText(QApplication::translate("sendProperties", "RS232 speed", nullptr));
        label_7->setText(QApplication::translate("sendProperties", "Modem timout", nullptr));
        label_6->setText(QApplication::translate("sendProperties", "RS232 timeout", nullptr));
        sendProp->setText(QApplication::translate("sendProperties", "SendProperties", nullptr));
        cancel->setText(QApplication::translate("sendProperties", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sendProperties: public Ui_sendProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDPROPERTIES_H
