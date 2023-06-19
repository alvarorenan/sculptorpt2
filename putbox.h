#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"

class PutBox:public FiguraGeometrica
{
protected:
    int xi,xf,yi,yf,zi,zf;
    float r,g,b,a;


public:

    PutBox(int x0,int x1,int y0,int y1, int z0 ,int z1,float r,float g,float b,float a);
    void draw(Sculptor &t);
};

#endif // PUTBOX_H
