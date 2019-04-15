#ifndef MAIN_INTERFACE_H
#define MAIN_INTERFACE_H

#include <QWidget>
#include <QThread>
#include <QDate>
#include <QTime>
#include <QDateTime>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>

#include <QProcess>
#include <iostream>
#include <QHostAddress>



class TimeThread:public QThread
{
    Q_OBJECT
  public:
    explicit TimeThread(QObject *parent = Q_NULLPTR);
    ~TimeThread();
    void run();
  signals:
    void send_time(QDate date, QTime time);
  private:
    bool isRun;
};


namespace Ui {
class Main_interface;
}

class Main_interface : public QWidget
{
    Q_OBJECT

public:
    explicit Main_interface(QWidget *parent = 0);
    ~Main_interface();

signals:



private slots:
    //时间 天气  界面跳转
    void update_date_time(QDate date, QTime time);
    void receivelogin();
    void GetWebJsonData(QNetworkReply *);
    void analyseJson();
    //tcp
    void new_client();
    void new_client_msg();
    void read_data();
    void read_data_msg();
    //播放视频
    void on_pushButton_clicked();
    void on_listWidget_clicked(const QModelIndex &index);

private:
    Ui::Main_interface *ui;

    //tcp信息发送
    QTcpServer *mserver;
    QTcpServer *mserver_msg;
    QTcpSocket *msocket;
    QTcpSocket *msocket_msg;
    //tcp文件发送
    QFile file;
    quint64 filesize;
    quint64 recvsize;
    //时间 线程 json
    QByteArray weather;
    TimeThread *mtimethread;
    QNetworkAccessManager *manager;
    //视频
    QStringList names;
    QProcess *mprocess;
    QProcess *mprocess_m;


};

#endif // MAIN_INTERFACE_H
