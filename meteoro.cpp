#include "meteoro.h"
#include "boss.h"
#include "myrect.h"
#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene> // create a scene
#include <QDebug>
#include <QList>
#include <stdlib.h>


meteoro::meteoro()
{
    //set random posicion
    int random_number = rand() % 600 ;
    setPos(random_number,0);

    //draw a meteoro
    setRect(0,0,50,50);

    //

    //conection
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()) );
    timer->start(50);

}

float meteoro::get_Vida()
{
    return vida;
}

void meteoro::move()
{
    // move meteoro down
    setPos(x(),y()+10);
    if (pos().y() < -rect().height()){
        scene()->removeItem(this);
        delete this;
    }

    QList<QGraphicsItem *> colliding_items = collidingItems(); // lista que almacena las colisiones
    for(int i = 0, n = colliding_items.size(); i<n ; i++){
        if (typeid (*(colliding_items[i])) != typeid (Enemy) && typeid (*(colliding_items[i])) != typeid (Bullet) &&  typeid (*(colliding_items[i])) != typeid (boss)){
                //remove the both
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                //delete both
                delete colliding_items[i];
                delete this;

        }


}
}
