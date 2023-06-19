#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

class CutSphere:public FiguraGeometrica
{
protected:
    int xc,yc,zc,r;
public:
    CutSphere(int x,int y,int z,int radius);
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
