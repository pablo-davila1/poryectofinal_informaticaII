#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene> // create a scene
#include <QDebug>
#include <QList>
#include <stdlib.h>


Enemy::Enemy()
{
    //set random posicion
    int random_number = rand() % 700;
    setPos(random_number,0);

    //draw a eenmy
    setRect(0,0,100,100);

    //conection
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()) );
    timer->start(50);
}

void Enemy::move()
{
    // move enemy up
    setPos(x(),y()+5);
    if (pos().y() < -rect().height()){
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullent is deleted";
    }
}
