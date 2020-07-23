#include "boss.h"
#include <QTimer>
#include <QGraphicsScene> // create a scene
#include <QDebug>
#include "myrect.h"
#include "bullet.h"
#include "enemy.h"
#include <QList>
#include <stdlib.h>


boss::boss(){
    setRect(300,10,200,50);

    //connect
    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()),this,SLOT(show_boss()));
    timer->start(50);
}

void boss::show_boss()
{

}
