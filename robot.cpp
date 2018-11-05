#include "robot.h"

Robot::Robot(){
    this->v1 = 0;
    this->v2 = 0;
    this->radio = 1;
    this->diametro = 1;
    this->angulo = (3.1416/2);
    this->rtraslateX = 0;
    this->rtraslateY = 0;
}

void Robot::pintar_robot(){
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-9.5f,-9.5f);
    glVertex2f(-10.0f,-10.0f);
    glVertex2f(-9.0f,-10.0f);
    glEnd();
}

int Robot::obtener_instruccion(int key, int x, int y){
    switch(key){
    case GLUT_KEY_UP:
        TraslateY(0.1);
        cout<<("Arriba\n");
        break;
    case GLUT_KEY_DOWN:
        TraslateY(-0.1);
        cout<<("Abajo\n");
        break;
    case GLUT_KEY_RIGHT:
        TraslateX(0.1);
        cout<<("Derecha\n");
        break;
    case GLUT_KEY_LEFT:
        TraslateX(-0.1);
        cout<<("Izquierda\n");
        break;
    }
    return 0;
}

void Robot::TraslateX(float value)
{
    this->rtraslateX+=value;
}

void Robot::TraslateY(float value)
{
    this->rtraslateY+=value;
}

