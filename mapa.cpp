#include "mapa.h"

Mapa::Mapa(){
    this->tamaX = 10.0;
    this->tamaY = 10.0;
}

void Mapa::cuadrado(void){
    glBegin(GL_QUADS);
        glColor3f(1.0,1.0,1.0);
        glVertex3f(-7.0f, 4.0f, 0.0f);
        glVertex3f( -4.0f, 4.0f, 0.0f);
        glVertex3f( -4.0f,1.0f, 0.0f);
        glVertex3f(-7.0f,1.0f, 0.0f);
    glEnd();
}

void Mapa::FormasIrregu(void){
    glBegin(GL_TRIANGLES);
        glColor3f(1.0,1.0,1.0);
        glVertex3f( 10.0f,-10.0f, 0.0f);
        glVertex3f(0.0f, -10.0f, 0.0f);
        glVertex3f( 10.0f, 0.0f, 0.0f);
    glEnd();
}

void Mapa::dibujar(void){
    cuadrado();
    FormasIrregu();
}

void Mapa::redimencionar(int width,int height){
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-this->tamaX,this->tamaX,-this->tamaY,this->tamaY,-1.0f,1.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}
