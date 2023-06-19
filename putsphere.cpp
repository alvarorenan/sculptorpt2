#include "putsphere.h"

PutSphere::PutSphere(int x,int y,int z ,int raio ,float r,float g ,float b ,float a)
{
    // Variaveis esfera
xc = x;
yc = y;
zc = z;
this->raio = raio;
    //Variaveis cor/transparencia
this->r = r;
this->g = g;
this->b  =b;
this->a = a;


}

void PutSphere::draw(Sculptor &t){
    t.setColor(r,g,b,a);
    t.putSphere(xc,yc,zc,raio);
}
