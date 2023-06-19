#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

class CutEllipsoid : public FiguraGeometrica
{
protected:
    int xc,yc,zc,rx,ry,rz; // variaveis da elipse

public:

    CutEllipsoid(int x,int y,int z,int raix ,int raiy,int raiz);
    void draw(Sculptor &t);
    ~CutEllipsoid();
};

#endif // CUTELLIPSOID_H
