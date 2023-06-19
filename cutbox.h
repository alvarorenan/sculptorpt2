#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"


class CutBox :public FiguraGeometrica
{
protected:
    int xi,xf,yi,yf,zi,zf;
public:

    CutBox(int x0,int x1,int y0,int y1, int z0 ,int z1);
    void draw(Sculptor &T);
    ~CutBox();
};

#endif // CUTBOX_H
