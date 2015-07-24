#include "widget.h"
#include <QApplication>
#include <qfile.h>
#include <qdebug.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QFile qssFile(":/qss/default");//载入样式文件

    qssFile.open(QFile::ReadOnly);

    if(qssFile.isOpen())
    {

       QString qss = QLatin1String(qssFile.readAll());
       qApp->setStyleSheet(qss);
       qssFile.close();

    }

    //主窗口关闭程序结束
    a.setQuitOnLastWindowClosed(true);


    Widget w;
    w.show();

    return a.exec();
}
