#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>
#include <QTimer>

//"myrect.h" <QGraphicsRectItem> (por herencia)



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(NULL)); //inicializacion de timer para psicion en la que salen los enemigos y meteoros

    //create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    //create an item to put in to scene (personaje)
    MyRect * player = new MyRect();
    player->setRect(0,0,100,100);

    //add the item to scene
    scene->addItem(player);

    //Make rect focusable (se enfoca)
    player->setFlag(QGraphicsItem :: ItemIsFocusable);
    player->setFocus();
    //add view
    QGraphicsView *view = new QGraphicsView(scene); // or (view->setScene(scene);)
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);
    view->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2, view->height()-player->rect().height());

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



    return a.exec();
}
