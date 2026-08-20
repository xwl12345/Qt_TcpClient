/********************************************************************************
** Form generated from reading UI file 'ServerSoftware.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERSOFTWARE_H
#define UI_SERVERSOFTWARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerSoftwareClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_3;
    QFormLayout *formLayout_2;
    QLabel *label_ip;
    QLineEdit *lineEdit_ip;
    QLabel *label_port;
    QLabel *label_send;
    QLineEdit *lineEdit_send;
    QLineEdit *lineEdit_port;
    QWidget *widget_4;
    QFormLayout *formLayout_3;
    QLabel *label_connectState;
    QLabel *label_state;
    QLabel *label_failedState;
    QLabel *label_failed;
    QLabel *label_rec;
    QTextBrowser *textBrowser_recInformation;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_send;
    QPushButton *pushButton_discount;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ServerSoftwareClass)
    {
        if (ServerSoftwareClass->objectName().isEmpty())
            ServerSoftwareClass->setObjectName(QString::fromUtf8("ServerSoftwareClass"));
        ServerSoftwareClass->resize(475, 362);
        centralWidget = new QWidget(ServerSoftwareClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 20));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        formLayout_2 = new QFormLayout(widget_3);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout_2->setContentsMargins(-1, -1, -1, 9);
        label_ip = new QLabel(widget_3);
        label_ip->setObjectName(QString::fromUtf8("label_ip"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_ip);

        lineEdit_ip = new QLineEdit(widget_3);
        lineEdit_ip->setObjectName(QString::fromUtf8("lineEdit_ip"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit_ip);

        label_port = new QLabel(widget_3);
        label_port->setObjectName(QString::fromUtf8("label_port"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_port);

        label_send = new QLabel(widget_3);
        label_send->setObjectName(QString::fromUtf8("label_send"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_send);

        lineEdit_send = new QLineEdit(widget_3);
        lineEdit_send->setObjectName(QString::fromUtf8("lineEdit_send"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lineEdit_send);

        lineEdit_port = new QLineEdit(widget_3);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEdit_port);


        horizontalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        formLayout_3 = new QFormLayout(widget_4);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label_connectState = new QLabel(widget_4);
        label_connectState->setObjectName(QString::fromUtf8("label_connectState"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_connectState);

        label_state = new QLabel(widget_4);
        label_state->setObjectName(QString::fromUtf8("label_state"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, label_state);

        label_failedState = new QLabel(widget_4);
        label_failedState->setObjectName(QString::fromUtf8("label_failedState"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_failedState);

        label_failed = new QLabel(widget_4);
        label_failed->setObjectName(QString::fromUtf8("label_failed"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, label_failed);

        label_rec = new QLabel(widget_4);
        label_rec->setObjectName(QString::fromUtf8("label_rec"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_rec);

        textBrowser_recInformation = new QTextBrowser(widget_4);
        textBrowser_recInformation->setObjectName(QString::fromUtf8("textBrowser_recInformation"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textBrowser_recInformation->sizePolicy().hasHeightForWidth());
        textBrowser_recInformation->setSizePolicy(sizePolicy2);
        textBrowser_recInformation->setMaximumSize(QSize(200, 100));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, textBrowser_recInformation);


        horizontalLayout_2->addWidget(widget_4);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_connect = new QPushButton(widget_2);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));

        horizontalLayout_3->addWidget(pushButton_connect);

        pushButton_send = new QPushButton(widget_2);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));

        horizontalLayout_3->addWidget(pushButton_send);

        pushButton_discount = new QPushButton(widget_2);
        pushButton_discount->setObjectName(QString::fromUtf8("pushButton_discount"));

        horizontalLayout_3->addWidget(pushButton_discount);


        verticalLayout->addWidget(widget_2);


        horizontalLayout->addWidget(groupBox);

        ServerSoftwareClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ServerSoftwareClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 475, 22));
        ServerSoftwareClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ServerSoftwareClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ServerSoftwareClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ServerSoftwareClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ServerSoftwareClass->setStatusBar(statusBar);

        retranslateUi(ServerSoftwareClass);

        QMetaObject::connectSlotsByName(ServerSoftwareClass);
    } // setupUi

    void retranslateUi(QMainWindow *ServerSoftwareClass)
    {
        ServerSoftwareClass->setWindowTitle(QCoreApplication::translate("ServerSoftwareClass", "ServerSoftware", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ServerSoftwareClass", "client", nullptr));
        label_ip->setText(QCoreApplication::translate("ServerSoftwareClass", "IP\345\234\260\345\235\200", nullptr));
        label_port->setText(QCoreApplication::translate("ServerSoftwareClass", "\347\253\257\345\217\243\345\217\267", nullptr));
        label_send->setText(QCoreApplication::translate("ServerSoftwareClass", "\345\217\221\351\200\201\344\277\241\346\201\257", nullptr));
        label_connectState->setText(QCoreApplication::translate("ServerSoftwareClass", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        label_state->setText(QCoreApplication::translate("ServerSoftwareClass", "\346\234\252\350\277\236\346\216\245", nullptr));
        label_failedState->setText(QCoreApplication::translate("ServerSoftwareClass", "\345\244\261\350\264\245\345\216\237\345\233\240\357\274\232", nullptr));
        label_failed->setText(QString());
        label_rec->setText(QCoreApplication::translate("ServerSoftwareClass", "\346\216\245\346\224\266\344\277\241\346\201\257\357\274\232", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("ServerSoftwareClass", "\350\277\236\346\216\245", nullptr));
        pushButton_send->setText(QCoreApplication::translate("ServerSoftwareClass", "\345\217\221\351\200\201", nullptr));
        pushButton_discount->setText(QCoreApplication::translate("ServerSoftwareClass", "\346\226\255\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerSoftwareClass: public Ui_ServerSoftwareClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERSOFTWARE_H
