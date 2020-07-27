#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject> //siempre que halla un slots
#include "boss.h"


class MyRect:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    MyRect(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
    void spawn2();
    void spawnboss();
    void spawnbullet2();






};

#endif // MYRECT_H
