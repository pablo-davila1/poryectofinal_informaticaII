#ifndef BULLET2_H
#define BULLET2_H
#include <QGraphicsRectItem>


class bullet2 : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    bullet2(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_);

private slots:
    void move2();

private:
    float PX;//posicion en x
    float PY;//posicion en y
    float mass;//masa del cuerpo
    float R;//radio del cuerpo
    float VX;//velocidad en x
    float VY;//velocidad en y
    float angulo;//angulo en el que va el cuerpo.
    float AX;//aceleracion en x
    float AY;//aceleracion en y
    float G;//gravedad
    float K;//resistencia del aire
    float e;//coeficiente de restitucion.
    float V;//vector velocidad.
    float dt;//delta de tiempo.


};

#endif // BULLET2_H
