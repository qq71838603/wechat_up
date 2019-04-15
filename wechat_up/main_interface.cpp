#include "main_interface.h"
#include "ui_main_interface.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QTime>


TimeThread::TimeThread(QObject *parent):QThread(parent)
{
    isRun = true;
}
TimeThread::~TimeThread(){}


Main_interface::Main_interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Main_interface)
{
    ui->setupUi(this);

    //广州天气
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(GetWebJsonData(QNetworkReply *)));
    manager->get(QNetworkRequest(QUrl("http://www.weather.com.cn/data/sk/101280101.html")));

    mtimethread = new TimeThread();
    connect(mtimethread,SIGNAL(send_time(QDate,QTime)),this, SLOT(update_date_time(QDate,QTime)));
     //connect(mtimethread,TimeThread::send_time,this, Work1ThreadTime::update_date_time);
     //启动线程
    mtimethread->start();


    //创建QTcpServer对象
    mserver = new QTcpServer();
    mserver_msg = new QTcpServer();
    //调用对象方法listen监听
    mserver->listen(QHostAddress::Any,9999);
    mserver_msg->listen(QHostAddress::Any,8888);
    /*当有客户端连接的时候QTcpServer
    会发送一个newConnection信号（创建一个槽函数）*/
    connect(mserver,SIGNAL(newConnection()),this,SLOT(new_client())); 
    connect(mserver_msg,SIGNAL(newConnection()),this,SLOT(new_client_msg()));


    mprocess = new QProcess();

    //当进程有数据可读的时候就会发生readyRead信号
    connect(mprocess,SIGNAL(readyRead()),this, SLOT(read_data()));

    //读取视频线程
    mprocess_m = new QProcess();

}

Main_interface::~Main_interface()
{
    delete ui;
}

//定时器
void TimeThread::run()
{
    while(isRun)
    {
        emit send_time(QDate::currentDate(), QTime::currentTime());
        sleep(1);
    }
}

//显示界面
void Main_interface::receivelogin()
{
    this->show();
}

//线程获取时间
void Main_interface::update_date_time(QDate date, QTime time)
{
    ui->datelabel->setText(date.toString("yyyy-MM-dd"));
    ui->timelabel->setText(time.toString("hh:mm:ss"));

}

//读城市天气
void Main_interface::GetWebJsonData(QNetworkReply *reply)
{
   weather=reply->readAll();
   //qDebug()<<weather;
   analyseJson();
}

//获取天气
void Main_interface::analyseJson()
{
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(weather,&err);
    QJsonObject obj= doc.object().value("weatherinfo").toObject();//object()获得json最外面一层

    ui->cityEdit->setText(doc.object().value("weatherinfo").toObject().take("city").toString());
    ui->tempEdit->setText(doc.object().value("weatherinfo").toObject().take("temp").toString()+"℃");
    ui->windEdit->setText(doc.object().value("weatherinfo").toObject().take("WD").toString()+doc.object().value("weatherinfo").toObject().take("WS").toString());
    QVariantMap QVM= obj.toVariantMap();
    /*QVariantMap::iterator it = QVM.begin();
    while(it!=QVM.end())
    {
        ui->textEdit->append(it.key()+"              "+it.value().toString());
        it++;
        qDebug()<<it.key();
    }*/
}

/*****************************************************************************/

void Main_interface::new_client_msg()
{
    //qDebug()<<"新客户端连接";
    msocket_msg = mserver_msg->nextPendingConnection();

    //向客户端发送数据
    msocket_msg->write("***************************************");


    //当客户有数据到达的是QTcpSocket对象会发送readyReay信号
    connect(msocket_msg, SIGNAL(readyRead()),this, SLOT(read_data_msg()));
}

void Main_interface::read_data_msg()
{
    ui->textBrowser->clear();
    QString msg = msocket_msg->readAll();
    //qDebug()<<msg;   <span style=" color:#ff0000;">msg</span>
    //信息字体颜色
    QString start=QString("<span style=\" color:#000000;\"> %1:<br>").arg(QTime::currentTime().toString("hh:mm:ss"));
    QString end("<\/span>");
    ui->textBrowser->append(start+msg+end+"\n");

    //pc端控制播放视频
    QStringList strlist=msg.split(" ");
    if(strlist.at(0) == "mplayer")
    {
        if(mprocess_m->state() == QProcess::Running)
        {
            //杀死进程
            mprocess_m->kill();
            mprocess_m->waitForFinished();
        }
        mprocess_m->start(msg);
    }

}


void Main_interface::new_client()
{
    //qDebug()<<"新客户端连接";
    msocket = mserver->nextPendingConnection();

    //向客户端发送数据
    msocket->write("***************************************");


    //当客户有数据到达的是QTcpSocket对象会发送readyReay信号
    connect(msocket, SIGNAL(readyRead()),this, SLOT(read_data()));

    //初始化
    filesize = 0;
    recvsize = 0;
}
void Main_interface::read_data()
{

    if(filesize == 0)
    {
        //接收文件信息
        QString filename;
        QDataStream stream(msocket);//把套接字绑定在stream
        stream>>filesize>>filename;

        file.setFileName(filename);
        if(file.exists())
        {
            int i=1;
            while(1)
            {
                QString tempfilename = filename;
                QString sp = QString("_%1").arg(i);
                tempfilename.insert(filename.indexOf("."), sp);
                i++;
                if(QFile(tempfilename).exists())
                {
                    continue;
                }
                file.setFileName(tempfilename);
                break;
            }
        }
        file.open(QIODevice::WriteOnly);
    }else
    {
        //接收文件内容
        QByteArray array = msocket->readAll();
        file.write(array);
        recvsize += array.size();//累计接收数据

        if(filesize == recvsize)
        {
            file.close();
        }
    }
}

void Main_interface::on_pushButton_clicked()
{
    //获取多个文件路径
    QStringList temps = QFileDialog::getOpenFileNames(this,"opt","/");
    names.append(temps);

    foreach(QString name, temps)
    {
        QFileInfo info(name);
        ui->listWidget->addItem(info.fileName());
    }
}


//单击播放列表中的视频
void Main_interface::on_listWidget_clicked(const QModelIndex &index)
{
    //判断进程是否在运行

    if(mprocess_m->state() == QProcess::Running)
    {
        //杀死进程
        mprocess_m->kill();
        mprocess_m->waitForFinished();
    }

    QString filename = names.at(index.row());

    //打开文件--读文件---关闭文件
    QFile file(filename);//--创建文件对象
    file.open(QIODevice::ReadOnly); //打开文件


    QStringList list;
    list<<"-slave"<<"-quiet"<<"-geometry"<<"50:50"<<"-zoom"<<"-x"<<"400"<<"-y"<<"350"<<QString::number(ui->label->winId());
    //list<<"mplayer "<<"-slave "<<"-quiet"<<"-geometry"<<"50:50"<<"-zoom"<<"-x 400 -y 350";
    list<<names.at(index.row());
    //mprocess->start("mplayer -slave -quiet -geometry 50:50 -zoom -x 400 -y 350 kjwei.avi");
    mprocess_m->start("/bin/mplayer",list);



    /*
    QStringList list;
    //list<<"-slave"<<"-quiet"<<"-wid"<<QString::number(ui->label->winId());
    list<<"mplayer "<<"-slave "<<"-quiet "<<"-geometry "<<"50:50 "<<"-zoom "<<"-x 400 -y 350 ";
    list<<names.at(index.row());
    //mprocess->start("mplayer -slave -quiet -geometry 50:50 -zoom -x 400 -y 350 kjwei.avi");
    mprocess_m->start("/bin/mplayer",list);



    QString cmd("mplayer -slave -quiet -geometry 50:50 -zoom -x 400 -y 350");
    cmd.append(filename);
    mprocess_m->start(cmd);


    QString cmd("mplayer -slave -quiet -geometry ");
    cmd.append(QString("%1:%2").arg(QString::number(ui->label->x())).arg(QString::number(ui->label->y())));
    cmd.append(QString(" -zoom -x %1 -y %2 ").arg(QString::number(ui->label->width()))
               .arg(QString::number(ui->label->height())));
    cmd.append("");
    mprocess_m->start(cmd);*/
}
