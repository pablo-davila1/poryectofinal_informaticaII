#include "bullet2.h"
#include "bullet3.h"
#include "bullet.h"
#include "meteoro.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene> // create a scene
#include <QGraphicsItem>
#include <QList>
#include <math.h>
#include <cmath>
#include <QDebug>



extern Game * game;


bullet2::bullet2(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_)
{
    int random_number = rand() % 400;

    int random_numberVX = rand() % 68;

    int random_numberVY = rand() % 5;


    PX = posX_;
    PY = posY_;
    mass = masa_;
    R = radio_;
    VX = random_numberVX;
    VY = random_numberVY;
    AX = 0;
    AY = 0;
    G = 10;
    K = K_;
    e = e_;
    V = 0;
    dt = 0.1;

    //draw a bullet
    setRect(0,random_number,20,20);

    //conection
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move2()) );
    timer->start(50);

}

void bullet2::move2()
{
    if(pos().x() > 800 || pos().x() < 0){
        V = pow(((VX*VX*(-1*e))+(VY*VY)),1/2);
        angulo = atan2(VY, VX);
        AX = -((K*(V*V)*(R*R))/mass)*cos(angulo);
        AY = (-((K*(V*V)*(R*R))/mass)*sin(angulo))-G;
        PX = -1*(PX + (VX*dt) + ((AX*(dt*dt))/2));
        PY = PY + (VY*dt) + ((AY*(dt*dt))/2);
        VX = -1*(VX + AX*dt);
        VY = VY + AY*dt;
    }
    else{
        V = pow(((VX*VX)+(VY*VY)),1/2);
        angulo = atan2(VY, VX);
        AX = -((K*(V*V)*(R*R))/mass)*cos(angulo);
        AY = (-((K*(V*V)*(R*R))/mass)*sin(angulo))-G;
        PX = PX + (VX*dt) + ((AX*(dt*dt))/2);
        PY = PY + (VY*dt) + ((AY*(dt*dt))/2);
        VX = VX + AX*dt;
        VY = VY + AY*dt;}


    // move bullet2 in scene
    setPos(x()+VX,y()-VY);

    if (pos().y() < -rect().height()){
        scene()->removeItem(this);
        delete this;
   }



    QList<QGraphicsItem *> colliding_items = collidingItems(); // lista que almacena las colisiones
    for(int i = 0, n = colliding_items.size(); i<n ; i++){
        if (typeid (*(colliding_items[i])) != typeid (Enemy) && typeid (*(colliding_items[i])) != typeid (boss) && typeid (*(colliding_items[i])) != typeid (score) && typeid (*(colliding_items[i])) != typeid (Health) && typeid (*(colliding_items[i])) != typeid (bullet3) && typeid (*(colliding_items[i])) != typeid (meteoro)){
                //remove the both
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                //delete both
                delete colliding_items[i];
                delete this;

        }


    }







}
