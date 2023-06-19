#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

class PutEllipsoid:public FiguraGeometrica
{
protected:
    int xc,yc,zc,rx,ry,rz; // variaveis da elipse
    float r,g,b,a; // cor e transparencia
public:

    PutEllipsoid(int x,int y,int z,int raix ,int raiy,int raiz,float r,float g,float b,float a);
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
