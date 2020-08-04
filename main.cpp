#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "game.h"
#include <QDebug>

//"myrect.h" <QGraphicsRectItem> (por herencia)

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    game = new Game;
    //game->show();

    return a.exec();
}
