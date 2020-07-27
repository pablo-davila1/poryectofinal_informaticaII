#include "myrect.h"
#include "enemy.h"
#include "game.h"
#include "score.h"
#include "boss.h"
#include "helath.h"
#include "bullet.h"
#include "meteoro.h"
#include "bulletboss.h"
#include <QTimer>
#include "enemy.h"
#include "bullet.h"
#include "game.h"
#include <QGraphicsScene> // create a scene
#include <QDebug>
#include <QList>
#include <stdlib.h>

extern Game * game;
bulletboss::bulletboss()
{
    //set a posicion
    setPos(80,90);
    //draw a bullet boss
    setRect(50,50,20,60);

    //conection
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(movebull()) );
    timer->start(50);

}

void bulletboss::movebull()
{
    QList<QGraphicsItem *> colliding_items = collidingItems(); // lista que almacena las colisiones
    for(int i = 0, n = colliding_items.size(); i<n ; i++){
        if (typeid (*(colliding_items[i])) == typeid (Enemy)){
            //increase the score
            game->Score->increase();
            //remove the both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete both
            delete colliding_items[i];
            delete this;
        }

    }

    setPos(x()+10,y()-20);
    if (pos().y() < -rect().height() ){
        scene()->removeItem(this);
        delete this;
    }
}
