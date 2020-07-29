#include "myrect.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene> // create a scene
#include <QGraphicsRectItem>
#include <QDebug>
#include "enemy.h"
#include "meteoro.h"
#include "boss.h"
#include "bullet2.h"
#include "bullet3.h"



MyRect::MyRect(QGraphicsItem *parent)
{

}

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
        bullet->setPos(x(),y()); // para crearla justo donde esta el cuerpo
        scene()->addItem(bullet);


    }
}

void MyRect::spawn()
{
    //create a enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void MyRect::spawn2()
{
    //create a meteoro
    meteoro * Meteoro = new meteoro();
    scene()->addItem(Meteoro);
}


void MyRect::spawnboss()
{
    boss *Boss = new boss();
    scene()->addItem(Boss);

}

void MyRect::spawnbullet2()
{
    float posx, posy, velx , vely ,r, mass, K, e;
    posx = 32;
    posy = 150;
    r = 20;
    mass = 20;
    velx = 100;
    vely = 3;
    K = 0.08;
    e = 0.5;

    bullet2 *Bullet2 = new bullet2(posx,posy, vely, vely, mass, r, K,  e);
    scene()->addItem(Bullet2);

}

void MyRect::spawnbullet3()
{
    float posx2, posy2, velx2 , vely2 ,r, mass, K, e;
    posx2 = 700;
    posy2 = 400;
    r = 20;
    mass = 20;
    velx2 = 100;
    vely2 = 3;
    K = 0.08;
    e = 0.5;

    bullet3 *Bullet3 = new bullet3(posx2,posy2, vely2, vely2, mass, r, K,  e);
    scene()->addItem(Bullet3);

}






