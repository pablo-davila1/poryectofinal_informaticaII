#include "myrect.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene> // create a scene
#include <QGraphicsRectItem>
#include <QDebug>
#include "enemy.h"

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
            setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet(); // crear bala nueva
        bullet->setPos(x(),y()); // para crarla justo donde esta el cuerpo
        scene()->addItem(bullet);
    }
}

void MyRect::spawn()
{
    //create a enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}