#include "game.h"
#include "boss.h"
#include "bulletboss.h"
#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
//"myrect.h" <QGraphicsRectItem> (por herencia)


Game::Game(QWidget *parent)
{

    srand(time(NULL)); //inicializacion de timer para psicion en la que salen los enemigos y meteoros

    //create a scene
    scene = new QGraphicsScene();
    setScene(scene);
    scene->setSceneRect(0,0,800,600);


    //create an item to put in to scene (personaje)
    player = new MyRect();
    player->setRect(0,0,100,100);

    //add the item to scene
    scene->addItem(player);

    //Make rect focusable (se enfoca)
    player->setFlag(QGraphicsItem :: ItemIsFocusable);
    player->setFocus();

    //create the score
    Score = new score();
    scene->addItem(Score);

    //create the health
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    //create the enemy_bullet

    //add view
    QGraphicsView *view = new QGraphicsView(scene); // or (view->setScene(scene);)
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800,600);



    player->setPos(scene->width()/2, scene->height()-player->rect().height());

    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //spawn meteoros
    QTimer * timer2 = new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(spawn2()));
    timer2->start(2000);

    //spawn boss
    QTimer * timer3 = new QTimer();
    QObject::connect(timer3,SIGNAL(timeout()),player,SLOT(spawnboss()));
    timer3->start(10000);

    //spawn bullet boss
    QTimer * timer4 = new QTimer();
    QObject::connect(timer4,SIGNAL(timeout()),player,SLOT(spawnbullet2()));
    timer4->start(3000);

    QTimer * timer5 = new QTimer();
    QObject::connect(timer5,SIGNAL(timeout()),player,SLOT(spawnbullet3()));
    timer5->start(3000);




    //show();
    view->show();

}
