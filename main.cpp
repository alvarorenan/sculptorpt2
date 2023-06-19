#include <iostream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "sculptor.h"
#include "figurageometrica.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

using namespace std;

int main(){
    string String,comando;
    ifstream arq;
    FiguraGeometrica *v;
    Sculptor *t;
    arq.open("C:/Users/breno/Desktop/Escultor3d/Escultor3D/instrucoes.txt");

    while(arq.is_open()){
        getline(arq,String);
        if(arq.good()){
            stringstream ss(String);
            ss>>comando;
            if(comando.compare("dim") == 0 ){
                int nx,ny,nz;
                ss>>nx>>ny>>nz;
                 t = new Sculptor(nx,ny,nz);
            }
            else if(comando.compare("putvoxel") == 0){
                int x,y,z;
                float r,g,b,a;
                ss>>x>>y>>z>>r>>g>>b>>a;
                v = new PutVoxel(x,y,z,r,g,b,a);
                v->draw(*t);
                delete v;
            }
            else if(comando.compare("cutvoxel") == 0){
                int x,y,z;
                ss>>x>>y>>z;
                v = new CutVoxel(x,y,z);
                v->draw(*t);
                delete v;
            }
            else if(comando.compare("putbox")==0){
                int x0,x1,y0,y1,z0,z1;
                float r,g,b,a;
                ss>>x0>>x1>>y0>>y1>>z0>>z1>>r>>g>>b>>a;
                v = new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a);
                v->draw(*t);
                delete v;
            }
            else if(comando.compare("cutbox") == 0){
                 int x0,x1,y0,y1,z0,z1;
                  ss>>x0>>x1>>y0>>y1>>z0>>z1;
                  v = new CutBox(x0,x1,y0,y1,z0,z1);
                  v->draw(*t);
                  delete v;
            }
            else if(comando.compare("putsphere") == 0){
                int x,y,z,raio;
                float r,g,b,a;
                ss>>x>>y>>z>>raio>>r>>g>>b>>a;
                v = new PutSphere(x,y,z,raio,r,g,b,a);
                v->draw(*t);
                delete v;
            }
            else if(comando.compare("cutsphere")==0){
                int x,y,z,raio;
                ss>>x>>y>>z>>raio;
                v = new CutSphere(x,y,z,raio);
                v->draw(*t);
                delete v;
            }
            else if(comando.compare("putellipsoid") == 0){
                int x,y,z,raix,raiy,raiz;
                float r,g,b,a;
                ss>>x>>y>>z>>raix>>raiy>>raiz>>r>>g>>b>>a;
                v = new PutEllipsoid(x,y,z,raix,raiy,raiz,r,g,b,a);
                v->draw(*t);
                delete v;
            }
            else if(comando.compare("cutellipsoid") == 0){
                int x,y,z,raix,raiy,raiz;
                ss>>x>>y>>z>>raix>>raiy>>raiz;
                v = new CutEllipsoid(x,y,z,raix,raiy,raiz);
                v->draw(*t);
                delete v;
            }

        } else{
            arq.close();
        }

    }

    t->writeOFF("C:/Users/breno/Desktop/Escultor3d/Escultor3D/teste.off");
    //g.writeOFF("C:/Users/breno/Desktop/Escultor3d/Escultor3D/teste.off");
    return 0;
}
