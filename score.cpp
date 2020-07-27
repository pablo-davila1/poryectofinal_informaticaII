#include "score.h"
#include <QFont>
//using namespace std;

score::score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //inicializar el puntaje a 0
    Score = 0;

    //luego se pinta
    setPlainText(QString("Score: ") + QString::number(Score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));

}

void score::increase()
{
    Score++;
    setPlainText(QString("Score: ") + QString::number(Score)); //score ++ actualizado
}

int score::getscore()
{
    return Score;
}
