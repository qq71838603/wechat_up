/********************************************************************************
** Form generated from reading UI file 'main_interface.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_INTERFACE_H
#define UI_MAIN_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_interface
{
public:
    QLabel *datelabel;
    QLabel *timelabel;
    QLabel *time;
    QLabel *cityEdit;
    QLabel *tempEdit;
    QLabel *windEdit;
    QLabel *textEdit;
    QLabel *weather;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Main_interface)
    {
        if (Main_interface->objectName().isEmpty())
            Main_interface->setObjectName(QStringLiteral("Main_interface"));
        Main_interface->resize(800, 480);
        datelabel = new QLabel(Main_interface);
        datelabel->setObjectName(QStringLiteral("datelabel"));
        datelabel->setGeometry(QRect(490, 280, 251, 101));
        QFont font;
        font.setPointSize(25);
        datelabel->setFont(font);
        timelabel = new QLabel(Main_interface);
        timelabel->setObjectName(QStringLiteral("timelabel"));
        timelabel->setGeometry(QRect(490, 350, 251, 111));
        timelabel->setFont(font);
        time = new QLabel(Main_interface);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(490, 240, 221, 51));
        time->setFont(font);
        cityEdit = new QLabel(Main_interface);
        cityEdit->setObjectName(QStringLiteral("cityEdit"));
        cityEdit->setGeometry(QRect(490, 70, 201, 41));
        cityEdit->setFont(font);
        tempEdit = new QLabel(Main_interface);
        tempEdit->setObjectName(QStringLiteral("tempEdit"));
        tempEdit->setGeometry(QRect(490, 120, 191, 41));
        tempEdit->setFont(font);
        windEdit = new QLabel(Main_interface);
        windEdit->setObjectName(QStringLiteral("windEdit"));
        windEdit->setGeometry(QRect(490, 160, 211, 61));
        windEdit->setFont(font);
        textEdit = new QLabel(Main_interface);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(490, 230, 211, 20));
        textEdit->setFont(font);
        weather = new QLabel(Main_interface);
        weather->setObjectName(QStringLiteral("weather"));
        weather->setGeometry(QRect(490, 20, 201, 41));
        weather->setFont(font);
        textBrowser = new QTextBrowser(Main_interface);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 400, 451, 81));
        QFont font1;
        font1.setPointSize(15);
        textBrowser->setFont(font1);
        pushButton = new QPushButton(Main_interface);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 51, 51));
        listWidget = new QListWidget(Main_interface);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 50, 51, 351));
        label = new QLabel(Main_interface);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 50, 401, 351));
        label->setStyleSheet(QLatin1String("\n"
"background-color: rgb(85, 255, 255);"));
        label_2 = new QLabel(Main_interface);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 0, 401, 51));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        retranslateUi(Main_interface);

        QMetaObject::connectSlotsByName(Main_interface);
    } // setupUi

    void retranslateUi(QWidget *Main_interface)
    {
        Main_interface->setWindowTitle(QApplication::translate("Main_interface", "Form", 0));
        datelabel->setText(QString());
        timelabel->setText(QString());
        time->setText(QApplication::translate("Main_interface", "\347\216\260\345\234\250\346\227\266\351\227\264", 0));
        cityEdit->setText(QString());
        tempEdit->setText(QString());
        windEdit->setText(QString());
        textEdit->setText(QString());
        weather->setText(QApplication::translate("Main_interface", "\347\216\260\345\234\250\345\244\251\346\260\224", 0));
        pushButton->setText(QApplication::translate("Main_interface", "\350\247\206\351\242\221", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("Main_interface", "       mp system", 0));
    } // retranslateUi

};

namespace Ui {
    class Main_interface: public Ui_Main_interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_INTERFACE_H
