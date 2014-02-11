#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/res/app.ico"));

    //设置样式表
    QFile data(":/res/style.qss");
    QString qssFile;
    if(data.open(QFile::ReadOnly))
    {
        QTextStream styleIn(&data);
        qssFile = styleIn.readAll();
        data.close();
        qApp->setStyleSheet(qssFile);
    }
    data.close();


    MainWindow w;
    w.show();

    return a.exec();
}
