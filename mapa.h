#ifndef MAPA_H
#define MAPA_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>

class Mapa
{
public:
    int numObs;
    float tamaX;
    float tamaY;
    int *pos;

    Mapa();
    void dibujar(void);
    void cuadrado(void);
    void FormasIrregu(void);
    void redimencionar(int width, int height);

};

#endif // MAPA_H
