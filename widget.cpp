#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
     this->initUI();

}

Widget::~Widget()
{

}


void Widget::initUI()
{
    this->setFixedSize(900, 600);//设定尺寸
    this->setWindowTitle(tr("Chaos"));//设定标题
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_QuitOnClose,true);
    this->setWindowIcon(QIcon(":/mainico"));

    //创建托盘
    QSystemTrayIcon *system_tray = new QSystemTrayIcon();
    system_tray ->setIcon(QIcon(":/mainico"));
    system_tray->setToolTip("chaos");

    //创建托盘菜单
    QMenu *contexmenu=new QMenu(this);           //注意右键菜单的父对象，在窗口销毁后要把菜单也销毁掉
    QAction *shut=new QAction("quit",this);
    shut->setIcon(QIcon(":/close.ico"));
    //菜单中动作
    contexmenu->addAction(shut);
    system_tray->setContextMenu(contexmenu);
    //显示托盘
    system_tray->show();
    connect(shut,SIGNAL(triggered()),this,SLOT(closeWindow()));//右击退出程序
    connect(system_tray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(showWindow(QSystemTrayIcon::ActivationReason)));


    //背景图片
    QPixmap pixmap = QPixmap(":/bc.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);

    //播放按钮
    btn1=new QPushButton(this);
    btn1->setText("playvideo");
    btn1->move(700,50);
    btn1->setObjectName("mainbtn");
    connect(btn1, SIGNAL(clicked()),
               this, SLOT(playVideo()));//建造一个button 并初始化click事件

    //关闭按钮
    btn2=new QPushButton(this);
    btn2->setText("close");
    btn2->move(btn1->x(),btn1->y()+50);
    btn2->setObjectName("mainbtn");
    connect(btn2, SIGNAL(clicked()),
               this, SLOT(closeWindow()));//建造一个button 并初始化click事件
    //最小化到托盘
    btn3=new QPushButton(this);
    btn3->setText("minimize");
    btn3->move(btn2->x(),btn2->y()+50);
    btn3->setObjectName("mainbtn");
    connect(btn3, SIGNAL(clicked()),
               this, SLOT(hideWindow()));//建造一个button 并初始化click事件


    bar1=new QProgressBar(this);
    bar1->setObjectName("mybar");
    bar1->move(this->x()+100,this->height()-100);
    bar1->setValue(50);


    list1=new QListView(this);
    list1->move(50,100);
    list1->setObjectName("mylist");
    QStringList user;
    user += "first";
    user +="second";
    QStringListModel *model = new QStringListModel(user);
    list1->setModel(model);        //useList是个QListView
    user += "third";
    model->setStringList(user);


    vdo=new videowidget();//实例化弹出窗口
}

//播放视频
void Widget::playVideo()
{
    vdo->show();
    vdo->move(250,300);
    vdo->m_player->play();//点击的时候播放，从性能角度优化

}

void Widget::closeWindow()
{
    this->close();
}

void Widget::hideWindow()
{
    if(this->isVisible()==true)
    {
        this->hide();
    }
}

void Widget::showWindow(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
        {
        //点击托盘显示窗口
        case QSystemTrayIcon::Trigger:
         {
              if(this->isVisible()!=true)
             {
                  this->show();
                  break;
             }
         }
        //双击托盘显示窗口
        case QSystemTrayIcon::DoubleClick:
        {
             if(this->isVisible()!=true)
              {
                   this->show();
                   break;
              }
        }
        default:
         break;
        }
}


/*----整体拖动----*/
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = QPoint(-1, -1);
        event->accept();
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() &Qt::LeftButton)
    {
        if (dragPosition != QPoint(-1, -1))
            move(event->globalPos() - dragPosition);
        event->accept();
    }
}
/*----------------*/

