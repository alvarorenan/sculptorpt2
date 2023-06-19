#include "cutsphere.h"

CutSphere:: CutSphere(int x,int y,int z,int radius)
{
xc = x;
yc = y;
zc = z;
r = radius;
}

void CutSphere::draw(Sculptor &t){
    t.cutSphere(xc,yc,zc,r);
}
