#include "putellipsoid.h"

PutEllipsoid::PutEllipsoid(int x,int y,int z,int raix ,int raiy,int raiz,float r,float g,float b,float a)
{
    // Variaveis da esfera
xc = x;
yc = y;
zc = z;
rx = raix;
ry = raiy;
rz = raiz;

    // Transparencia e cores
this->r = r;
this->b = b;
this->g = g;
this->a = a;

}

void PutEllipsoid::draw(Sculptor &t){
t.setColor(r,g,b,a);
t.putEllipsoid(xc,yc,zc,rx,ry,rz);
}
