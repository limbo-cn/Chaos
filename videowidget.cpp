#include "videowidget.h"
#include "qdebug.h"

videowidget::videowidget(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(600, 400);

    //子窗口设置为false , 主窗口关闭程序结束
    this->setAttribute(Qt::WA_QuitOnClose,false);


    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    QMediaPlaylist *playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl::fromLocalFile(QDir::currentPath() + "/video/360SafeVideo.wmv"));

    qDebug() << QDir::currentPath() ;//  qdebug demo

    //加载视频
    m_player = new QMediaPlayer;
    m_player->setPlaylist(playlist);

    //设置视频播放层
    QVideoWidget *vw = new QVideoWidget(this);
    vw->setGeometry(rect());
    m_player->setVideoOutput(vw);

    vw->show();


    //显示关闭按钮
    m_close = new QPushButton(this);
    m_close->setObjectName("v_close");
    m_close->setText("×");
    m_close->move(width()-m_close->width()+85 , 0);
    //点击关闭按钮，连接窗口关闭信号槽
    connect(m_close, SIGNAL(clicked()), this, SLOT(closeWidget()));


   // 播放
    m_player->setPosition(0);
}

videowidget::~videowidget()
{

}

void videowidget::closeWidget()
{
   m_player->stop();
   this->close();
}







/*----整体拖动----*/
void videowidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = QPoint(-1, -1);
        event->accept();
    }
}

void videowidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void videowidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() &Qt::LeftButton)
    {
        if (dragPosition != QPoint(-1, -1))
            move(event->globalPos() - dragPosition);
        event->accept();
    }
}
/*----------------*/
