#include "objet_fisic.h"
#include <math.h>
#include <cmath>
#include <QTimer>
#include <QGraphicsScene> // create a scene
#include <QDebug>
#include <QList>
#include <stdlib.h>

Objet_fisic::Objet_fisic()
{
    setRect(300,10,200,50);

    //connect
    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()),this,SLOT(show_bulletboss()));
    timer->start(50);
}

Objet_fisic::Objet_fisic(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_)
{
    PX = posX_;
    PY = posY_;
    mass = masa_;
    R = radio_;
    VX = velX_;
    VY = velY_;
    AX = 10;
    AY = 10;
    G = 10;
    K = K_;
    e = e_;
    V = 0;
    dt = 0.1;

}

float Objet_fisic::get_posX()
{
    return PX;
}

float Objet_fisic::get_posY()
{
    return PY;
}

float Objet_fisic::get_Radio()
{
    return R;
}

float Objet_fisic::get_e()
{
    return e;
}

float Objet_fisic::get_velX()
{
    return VX;
}

float Objet_fisic::get_velY()
{
    return VY;
}

float Objet_fisic::get_masa()
{
    return mass;
}

void Objet_fisic::set_vel(float velx, float vely, float px, float py)
{
    VX = velx;
    VY = vely;
    PX = px;
    PY = py;
}

void Objet_fisic::actualizar()
{
    V = pow(((VX*VX)+(VY*VY)),1/2);
    angulo = atan2(VY, VX);
    AX = -((K*(V*V)*(R*R))/mass)*cos(angulo);
    AY = (-((K*(V*V)*(R*R))/mass)*sin(angulo))-G;
    PX = PX + (VX*dt) + ((AX*(dt*dt))/2);
    PY = PY + (VY*dt) + ((AY*(dt*dt))/2);
    VX = VX + AX*dt;
    VY = VY + AY*dt;
}

void Objet_fisic::show_bulletboss()
{

}
