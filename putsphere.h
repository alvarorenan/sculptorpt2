#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

class PutSphere:public FiguraGeometrica
{
protected:
    int xc,yc,zc,raio;
    float r,g,b,a;
public:

    PutSphere(int x,int y,int z ,int raiom,float r,float g ,float b ,float a);
    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
