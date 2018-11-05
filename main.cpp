#include <iostream>
#include "mapa.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include "robot.h"
#include <vector>

void display(void);
void reshape(int width,int height);
void keySpecial (int key, int x, int y);

Robot r;

int main(int argc, char *argv[]){


    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);
    glutCreateWindow("Inicio");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(keySpecial);


    glutMainLoop();
    return 0;
}

void display(void){
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    Mapa m1;

    m1.dibujar();

    glPushMatrix();
    glTranslatef(r.rtraslateX,r.rtraslateY,0.0);
    r.pintar_robot();
    glPopMatrix();


    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

void reshape(int width, int height){
    Mapa m1;
    m1.redimencionar(width, height);
}
void keySpecial (int key, int x, int y){
    r.obtener_instruccion(key,x,y);
}
