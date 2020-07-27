#include "bullet2.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene> // create a scene
#include <QGraphicsItem>
#include <QList>


extern Game * game;

int a = 5;

bullet2::bullet2()
{
    //draw a bullet
    setRect(50,200,20,60);

    //conection
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move2()) );
    timer->start(50);

}

void bullet2::move2()
{

    // move bullet2 in scene
    setPos(x()+10,y()-a);
    a++;
//    if (pos().y() < -rect().height()){
//        scene()->removeItem(this);
//        delete this;
//    }

}
