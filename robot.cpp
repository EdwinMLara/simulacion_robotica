#include "robot.h"
 
Robot::Robot(){
    this->v1 = 0;
    this->v2 = 0;
    this->radio = 1;
    this->diametro = 1;
    this->angulo = (3.1416/2);
    this->rtraslateX = 0;
    this->rtraslateY = 0;
    this->rotate = 0;
    this->bandera = 0;
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
    float * posnew;
    float x1,y1,an;
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
       /* posnew = this->mover_derecha();
        x1 = posnew[0];
        y1 = posnew[1];
        an = posnew[2];*/
        TraslateX(0.1);
        rotateRobot(-0.5);
        cout<<("Derecha\n");
        break;
    case GLUT_KEY_LEFT:
        TraslateX(0.1);
        rotateRobot(0.5);
        cout<<("Izquierda\n");
        break;
    }
    return 0;
}
 
void Robot::TraslateX(float value){
    this->rtraslateX+=value;
}
 
void Robot::TraslateY(float value){
    this->rtraslateY+=value;
}
 
void Robot::rotateRobot(float value){
    this->rotate += value;
}
void Robot::setV1(float v1){
    this->v1 = v1;
}
 
float Robot::getV1()
{
   return this->v1;
}
 
void Robot::setV2(float v2){
    this->v2 = v2;
}
 
float Robot::getV2(){
   return this->v2;
}
 
float Robot::getAngulo(){
    return this->angulo;
}
 
void Robot::crearmatriz(){
    this->posINI = new float[3];
    this->posNEW = new float[3];
 
    for(int i=0;i<2;i++)
    {
        posINI[i]=0.0;
        posNEW[i]=0.0;
    }
    posINI[2] = this->getAngulo();
}
 
void Robot::crearMaTRAnd(float angulo){
 
    this->matTrans = new float*[3];
    for(int i=0;i<3;i++)
    {
        this->matTrans[i] = new float[3];
    }
    this->matTrans[0][0] = cos(angulo);
    this->matTrans[1][0] = -sin(angulo);
    this->matTrans[2][0] = 0;
 
    this->matTrans[0][1] = sin(angulo);
    this->matTrans[1][1] = cos(angulo);
    this->matTrans[2][1] = 0;
 
    this->matTrans[0][2] = 0;
    this->matTrans[1][2] = 0;
    this->matTrans[2][2] = 1;
}
 
float* Robot::mover_derecha(){
    float v1 = 4;
    float v2 = 2;
    float r = 1;
    float deltaT = 0.1;
    float x,y,z;
 
    float **auxtran;
 
    crearmatriz();
    crearMaTRAnd(this->angulo);
    auxtran = this->matTrans;
 
    posINI[0] = (v1*r)/2 + (v2*r)/2;
    posINI[1] = 0;
    posINI[2] = (v1*r)/2 - (v2*r)/2;
 
    for(int i=0;i<3;i++)
    {
        for(int k=0;k<3;k++)
        {
            this->posNEW[i] += auxtran[i][k]*this->posINI[i];
        }
    }
 
    this->angulo = posNEW[2];
 
    x = posNEW[0];
    y = posNEW[1];
    z = posNEW[2];
 
    for(int i=0;i<3;i++)
    {
            posNEW[i] = posINI[i] + posNEW[i]*deltaT;
    }
    this->bandera = 1;
 
 
    return this->posNEW;
}

