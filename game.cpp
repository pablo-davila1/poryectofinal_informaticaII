#include "game.h"
#include "boss.h"
#include "bullet.h"
#include "bulletboss.h"
#include <QGraphicsScene>
#include "myrect.h"
#include "player2.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QList>
#include <QDebug>
#include <QKeyEvent>
#include <myrect.h>
//"myrect.h" <QGraphicsRectItem> (por herencia)

//QList < MyRect *> rects;



Game::Game(QWidget *parent)
{

    srand(time(NULL)); //inicializacion de timer para psicion en la que salen los enemigos y meteoros

    //create a scene
    scene = new QGraphicsScene();
    setScene(scene);
    scene->setSceneRect(0,0,800,600);


    //create an item to put in to scene (personaje)




    player1 = new MyRect();
    player1->setRect(0,0,100,60);

    //add the item to scene


    scene->addItem(player1);


    //Make rect focusable (se enfoca)
    player1->setFlag(QGraphicsItem :: ItemIsFocusable);
    player1->setFocus();




    //create the score
    Score = new score();
    scene->addItem(Score);

    //create the health
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    //create spawn


    //create the enemy_bullet

    //add view
    QGraphicsView *view = new QGraphicsView(scene); // or (view->setScene(scene);)
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800,600);





    player1->setPos(scene->width()/2, scene->height()-player1->rect().height());



    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player1,SLOT(spawn()));
    timer->start(4000);

    //spawn meteoros
    QTimer * timer2 = new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),player1,SLOT(spawn2()));
    timer2->start(4000 );

     //spawn boss
    QTimer * timer3 = new QTimer();
    QObject::connect(timer3,SIGNAL(timeout()),player1,SLOT(spawnboss()));
    timer3->start(10000);

    //spawn bullet boss
    QTimer * timer4 = new QTimer();
    QObject::connect(timer4,SIGNAL(timeout()),player1,SLOT(spawnbullet2()));
    timer4->start(6000);

    QTimer * timer5 = new QTimer();
    QObject::connect(timer5,SIGNAL(timeout()),player1,SLOT(spawnbullet3()));
    timer5->start(6000);





    //show();
    view->show();

}





//void Game::keyPressEvent(QKeyEvent *event)
//{

//    qDebug()<<"paso por letra";
//    if(rects.size()>0 && rects.size()<2){
//        if(event->key() == Qt::Key_W){
//            player1->setPos(rects.at(0)->x(),rects.at(0)->y()-10);
//        }
//        if(event->key() == Qt::Key_S){
//            rects.at(0)->setPos(rects.at(0)->x(),rects.at(0)->y()+10);
//        }
//        if(event->key() == Qt::Key_A){
//            rects.at(0)->setPos(rects.at(0)->x()-10,rects.at(0)->y());
//        }
//        if(event->key() == Qt::Key_D){
//            rects.at(0)->setPos(rects.at(0)->x()+10,rects.at(0)->y());
//        }
//    }
//    else if(rects.size()==2){
//        MyRect * a = rects.at(0);
//        if(event->key() == Qt::Key_W){
//            a->setPos(a->x(),a->y()-10);
//        }
//        if(event->key() == Qt::Key_S){
//            rects.at(0)->setPos(rects.at(0)->x(),rects.at(0)->y()+10);
//        }
//        if(event->key() == Qt::Key_A){
//            rects.at(0)->setPos(rects.at(0)->x()-10,rects.at(0)->y());
//        }
//        if(event->key() == Qt::Key_D){
//            rects.at(0)->setPos(rects.at(0)->x()+10,rects.at(0)->y());
//        }
//        if(event->key() == Qt::Key_U){
//            rects.at(1)->setPos(rects.at(1)->x(),rects.at(1)->y()-10);
//        }
//        if(event->key() == Qt::Key_J){
//            rects.at(1)->setPos(rects.at(1)->x(),rects.at(1)->y()+10);
//        }
//        if(event->key() == Qt::Key_H){
//            rects.at(1)->setPos(rects.at(1)->x()-10,rects.at(1)->y());
//        }
//        if(event->key() == Qt::Key_K){
//            rects.at(1)->setPos(rects.at(1)->x()+10,rects.at(1)->y());
//        }
//    }
//}


