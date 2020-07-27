#ifndef OBJET_FISIC_H
#define OBJET_FISIC_H

#include <QGraphicsRectItem>

class Objet_fisic : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Objet_fisic();
    Objet_fisic(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_);
    float get_posX();
    float get_posY();
    float get_Radio();
    float get_e();
    float get_velX();
    float get_velY();
    float get_masa();
    void set_vel(float velx, float vely, float px, float py);
    void actualizar();

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

public slots:
        void show_bulletboss();
};

#endif // OBJET_FISIC_H
