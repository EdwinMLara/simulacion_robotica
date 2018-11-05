#ifndef ROBOT_H
#define ROBOT_H

#ifndef ROBOT_H
#define ROBOT_H
 
#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <cstdlib>
 
using namespace std;
 
class Robot
{
private:
    float angulo;
    float v1;
    float v2;
    float diametro;
    float radio;
 
    float *posINI;
    float *posNEW;
 
    float **matTrans;
 
 
public:
    int bandera;
 
    vector <float> posglobal;
    vector <float> posRefencial;
 
    GLfloat rtraslateX;
    GLfloat rtraslateY;
    GLfloat rotate;
 
 
    Robot();
    void pintar_robot();
    int obtener_instruccion(int key, int x, int y);
 
    float* mover_derecha();
    void mover_izquierda();
    void mover_arriba();
    void mover_abajo();
 
    void TraslateX(float value);
    void TraslateY(float value);
    void rotateRobot(float value);
 
    void setV1(float v1);
    float getV1(void);
 
    void setV2(float v2);
    float getV2(void);
 
    void setAngulo(float an);
    float getAngulo(void);
 
    void crearmatriz(void);
    void crearMaTRAnd(float angulo);
 
 
};
 
#endif // ROBOT_H
