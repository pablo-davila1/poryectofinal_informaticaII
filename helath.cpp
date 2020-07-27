#include "helath.h"
#include "game.h"
#include "myrect.h"
#include "score.h"
#include <QFont>
//using namespace std;

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //inicializar el puntaje a 0
    health = 2;

    //luego se pinta
    setPlainText(QString("Helath: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

}

void Health::decrease()
{
    health--;
    setPlainText(QString("Helath: ") + QString::number(health)); //health ++ actualizado
}

int Health::getHealth()
{
    return health;
}

