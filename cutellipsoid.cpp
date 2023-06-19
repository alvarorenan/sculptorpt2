#include "cutellipsoid.h"

CutEllipsoid:: CutEllipsoid(int x,int y,int z,int raix ,int raiy,int raiz)
{
    // Variaveis da esfera
    xc = x;
    yc = y;
    zc = z;
    rx = raix;
    ry = raiy;
    rz = raiz;


}
void CutEllipsoid::draw(Sculptor &t){

    t.cutEllipsoid(xc,yc,zc,rx,ry,rz);
}
CutEllipsoid::~CutEllipsoid(){

}
