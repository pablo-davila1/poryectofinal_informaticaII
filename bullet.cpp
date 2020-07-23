#include "enemy.h"
#include "bullet.h"

#include <QTimer>
#include <QGraphicsScene> // create a scene
#include <QGraphicsItem>

Bullet::Bullet()
{
    //draw a bullet
    setRect(40,40,10,50);

    //conection
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()) );
    timer->start(50);
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems(); // lista que almacena las colisiones
    for(int i = 0, n = colliding_items.size(); i<n ; i++){
        if (typeid (*(colliding_items[i])) == typeid (Enemy)){
            //remove the both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete both
            delete colliding_items[i];
            delete this;
        }

    }
    // move bullet up
    setPos(x(),y()-20);
    if (pos().y() < -rect().height()){
        scene()->removeItem(this);
        delete this;
    }
}
