#include "widget.h"
#include <QApplication>
#include <mainwindow.h>
#include <QLineEdit>
#include "main_interface.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Main_interface v;
    QObject::connect(&w,SIGNAL(showmain()),&v,SLOT(receivelogin()));



    return a.exec();
}
