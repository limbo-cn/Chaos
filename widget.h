#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <qprogressbar.h>
#include <videowidget.h>
#include "qsystemtrayicon.h"
#include "qmenu.h"
#include "qlistview.h"
#include "qstringlistmodel.h"

class Widget : public QWidget
{
    Q_OBJECT
private:
    void initUI();
    QProgressBar *bar1;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    videowidget *vdo;
    QListView *list1;


    //整体拖动
    void mouseMoveEvent(QMouseEvent*event);
    void mousePressEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent*event);
    QPoint dragPosition;

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void playVideo();
    void closeWindow();
    void showWindow(QSystemTrayIcon::ActivationReason reason);
    void hideWindow();
};

#endif // WIDGET_H
