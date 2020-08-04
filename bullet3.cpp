#include "bullet3.h"
#include "bullet2.h"
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

bullet3::bullet3(float pos2X_, float pos2Y_, float vel2X_, float vel2Y_, float masa_, float radio_, float K_, float e_)
{
    int random_number = rand() % 400;

    int random_numberVX = rand() % 38;

    int random_numberVY = rand() % 20;



    PX2 = pos2X_;
    PY2 = pos2Y_;
    mass = masa_;
    R = radio_;
    VX2 = random_numberVX;
    VY2 = random_numberVY;
    AX2 = 0;
    AY2 = 0;
    G = 10;
    K = K_;
    e = e_;
    V = 0;
    dt = 0.1;

    //draw a bullet
    setRect(800,random_number,20,20);

    //conection
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move3()) );
    timer->start(50);

}

void bullet3::move3()
{

     if(pos().x()<1 || pos().x() > 800){
         V = pow(((VX2*VX2*(-1*e))+(VY2*VY2)),1/2);
        angulo = atan2(VY2, VX2);
        AX2 = -((K*(V*V)*(R*R))/mass)*cos(angulo);
        AY2 = (-((K*(V*V)*(R*R))/mass)*sin(angulo))-G;
        PX2 = (PX2 + (VX2*dt) + ((AX2*(dt*dt))/2))*(PX2 + (VX2*dt) + ((AX2*(dt*dt))/2));
        PX2 = sqrt(PX2);
        PY2 = PY2 + (VY2*dt) + ((AY2*(dt*dt))/2);
        VX2 =(VX2 + AX2*dt);
        VY2 = VY2 + AY2*dt;


    }
    else{
         V = pow(((VX2*VX2*(-1*e))+(VY2*VY2)),1/2);
        angulo = atan2(VY2, VX2);
        AX2 = -((K*(V*V)*(R*R))/mass)*cos(angulo);
        AY2 = (-((K*(V*V)*(R*R))/mass)*sin(angulo))-G;
        PX2 = -1*(PX2 + (VX2*dt) + ((AX2*(dt*dt))/2));
        PY2 = PY2 + (VY2*dt) + ((AY2*(dt*dt))/2);
        VX2 = -1*(VX2 + AX2*dt);
        VY2 = VY2 + AY2*dt;
}



    // move bullet2 in scene
    setPos(x()+VX2,y()-VY2);

    if (pos().y() < -rect().height()){
        scene()->removeItem(this);
        delete this;
   }

    QList<QGraphicsItem *> colliding_items = collidingItems(); // lista que almacena las colisiones
    for(int i = 0, n = colliding_items.size(); i<n ; i++){
        if (typeid (*(colliding_items[i])) != typeid (Enemy) &&  typeid (*(colliding_items[i])) != typeid (boss) && typeid (*(colliding_items[i])) != typeid (score) && typeid (*(colliding_items[i])) != typeid (Health) && typeid (*(colliding_items[i])) != typeid (bullet2) && typeid (*(colliding_items[i])) != typeid (meteoro)){
                //remove the both
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                //delete both
                delete colliding_items[i];
                delete this;

        }


    }








}
