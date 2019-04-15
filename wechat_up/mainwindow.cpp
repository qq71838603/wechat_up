#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main_interface.h"
#include <QDebug>
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widget->hide();
    //注册控件
    ui->lineEdit->installEventFilter(this);
    ui->lineEdit_2->installEventFilter(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString input1 = ui->lineEdit->text();
    if(input1 == "root")
    {
        QString input2 = ui->lineEdit_2->text();
        if(input2 == "123456" )
        {
            //if(ui->pushButton() == Qt::LeftButton)
            //{
                this->hide();
                emit showmain();

           // }
        }
    }
    else
    {
        QString input3 = "输入错误,请重新输入";
        ui->label_3->setText(input3);
    }
}



void MainWindow::focusInEvent(QFocusEvent *e)
{
     ui->widget->hide();

}

void MainWindow::focusOutEvent(QFocusEvent *e)
{
    ui->widget->show();
}

//过滤事件
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    //判断是否事件
    //qDebug()<<watched;
    //找焦点获取和释放事件
    if(event->type() == QEvent::FocusIn)
    {
        ui->widget->show();
    }
    if(event->type() == QEvent::FocusOut)
    {
        ui->widget->hide();
    }
    return QMainWindow::eventFilter(watched, event);
}

