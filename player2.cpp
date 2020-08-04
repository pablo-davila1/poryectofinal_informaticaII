#include "player2.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene> // create a scene
#include <QGraphicsRectItem>
#include <QDebug>




player2::player2(QGraphicsItem *parent2)
{

}

void player2::keyPressEvent(QKeyEvent *event2)
{
    if (event2->key() == Qt::Key_A){
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if(event2->key() == Qt::Key_B){
        if (pos().x() + 100 < 800)
            setPos(x()+10,y());
    }
    else if (event2->key() == Qt::Key_W){
//        Bullet * bullet = new Bullet(); // crear bala nueva
//        bullet->setPos(x(),y()); // para crearla justo donde esta el cuerpo
//        scene()->addItem(bullet);


    }
}
