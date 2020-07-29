#include "myrect.h"
#include "enemy.h"
#include "bullet3.h"
#include "game.h"
#include "score.h"
#include "boss.h"
#include "bullet2.h"
#include "helath.h"
#include "bullet.h"
#include "meteoro.h"
#include <QTimer>
#include <QGraphicsScene> // create a scene
#include <QDebug>
#include <QList>
#include <stdlib.h>

extern Game * game;

Enemy::Enemy()
{
    //set random posicion
    int random_number = rand() % 730-rect().width();
    setPos(random_number,0);

    //draw a eenmy
    setRect(0,0,100,100);

    //

    //conection
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    // move enemy up
    setPos(x(),y()+5);
    if (pos().y() > scene()->height()){
        //decrese the health
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }

    QList<QGraphicsItem *> colliding_items = collidingItems(); // lista que almacena las colisiones
    for(int i = 0, n = colliding_items.size(); i<n ; i++){
        if (typeid (*(colliding_items[i])) != typeid (meteoro) && typeid (*(colliding_items[i])) != typeid (Bullet) &&  typeid (*(colliding_items[i])) != typeid (boss) && typeid (*(colliding_items[i])) != typeid (score) && typeid (*(colliding_items[i])) != typeid (Health) && typeid (*(colliding_items[i])) != typeid (bullet2) && typeid (*(colliding_items[i])) != typeid (bullet3)){
                    //remove the both
                    scene()->removeItem(colliding_items[i]);
                    scene()->removeItem(this);
                    //delete both
                    delete colliding_items[i];
                    delete this;
                }
    }
}
