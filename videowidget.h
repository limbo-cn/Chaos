#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QVideoWidget>
#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDir>
#include <QPushButton>
#include <QMouseEvent>
#include <QPoint>

class videowidget : public QWidget
{
    Q_OBJECT
private:
    QPushButton     *m_close;

    //整体拖动
    void mouseMoveEvent(QMouseEvent*event);
    void mousePressEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent*event);
    QPoint dragPosition;


private slots:
    void closeWidget();
public:
    explicit videowidget(QWidget *parent = 0);
    ~videowidget();
    QMediaPlayer    *m_player;
signals:

public slots:

};

#endif // VIDEOWIDGET_H
