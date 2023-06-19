#include "putbox.h"

PutBox::PutBox(int x0,int x1,int y0,int y1, int z0 ,int z1,float r,float g,float b,float a)
{
// Colocando os limtes da box
xi = x0;
xf = x1;
yi = y0;
yf = y1;
zi = z0;
zf = z1;

// Cor e transparencia
this->r = r;
this->g = g;
this->b = b;
this->a = a;


}

void PutBox::draw(Sculptor &t){
    t.setColor(r,g,b,a);
    t.putBox(xi,xf,yi,yf,zi,zf);
}

