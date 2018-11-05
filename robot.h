#ifndef ROBOT_H
#define ROBOT_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Robot
{
public:
    float angulo;
    float v1;
    float v2;
    float diametro;
    float radio;
    vector <float> posglobal;
    vector <float> posRefencial;

    GLfloat rtraslateX;
    GLfloat rtraslateY;


    Robot();
    void pintar_robot();
    int obtener_instruccion(int key, int x, int y);

    void mover_derecha();
    void mover_izquierda();
    void mover_arriba();
    void mover_abajo();

    void TraslateX(float value);
    void TraslateY(float value);
};

#endif // ROBOT_H
