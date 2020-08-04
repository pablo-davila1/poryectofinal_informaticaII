#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject> //siempre que halla un slots
#include "boss.h"
#include <QList>



class MyRect:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    MyRect(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);

    MyRect * player2, *player1;

    //QList < MyRect *> rects;

public slots:
    void spawn();
    void spawn2();
    void spawnboss();
    void spawnbullet2();
    void spawnbullet3();







};

#endif // MYRECT_H
