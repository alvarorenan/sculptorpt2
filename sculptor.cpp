#include "sculptor.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

Sculptor::Sculptor(int nx, int ny, int nz){
    this->nx = nx;
    this->ny = ny;
    this->nz = nz;

    v = new Voxel**[nx];
    for(int i=0; i<nx; i++){
        v[i] = new Voxel*[ny];
        for(int j=0; j<ny; j++){
            v[i][j] = new Voxel[nz];
        }
    }

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                v[i][j][k].isOn = false;
                v[i][j][k].r = 0;
                v[i][j][k].g = 0;
                v[i][j][k].b = 0;
            }
        }
    }
}

Sculptor::~Sculptor(){
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            delete[] v[i][j];
        }
    }
    for(int i=0; i<nx; i++){
        delete[] v[i];
    }
    delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0;i< x1;i++){
        for(int j = y0;j< y1;j++){
            for(int k = z0;k< z1;k++){
                putVoxel(i,j,k);
            }
         }
     }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0;i< x1;i++){
        for(int j = y0;j< y1;j++){
            for(int k = z0;k< z1;k++){
                cutVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    double cal;
    for(int i =0;i<nx;i++){
        for(int j=0;j <ny;j++){
            for(int k=0; k<ny; k++){
                cal = sqrt(pow(i - xcenter,2) + pow(j - ycenter,2) + pow(k - zcenter,2));
                if( cal <= radius){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    double cal;
    for(int i =0;i<nx;i++){
        for(int j=0;j <ny;j++){
            for(int k=0; k<ny; k++){
                cal = sqrt(pow(i - xcenter,2) + pow(j - ycenter,2) + pow(k - zcenter,2));
                if( cal <= radius){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i=xcenter-rx; i< xcenter+rx; i++){
        for(int j=ycenter-ry; j< ycenter+ry; j++){
            for(int k=zcenter - rz; k< zcenter + rz; k++){
                if (((float)pow((i-xcenter),2)/(pow(rx,2))) + (((float)pow((j-ycenter),2))/(float)(pow(ry,2))) + (((float)pow((k-zcenter),2))/(float)(pow(rz,2))) <=1.0){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i=xcenter-rx; i< xcenter+rx; i++){
        for(int j=ycenter-ry; j< ycenter+ry; j++){
            for(int k=zcenter - rz; k< zcenter + rz; k++){
                if (((float)pow((i-xcenter),2)/(pow(rx,2))) + (((float)pow((j-ycenter),2))/(float)(pow(ry,2))) + (((float)pow((k-zcenter),2))/(float)(pow(rz,2))) <=1.0){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::writeOFF(char* filename){





     ofstream outfile;
     outfile.open(filename);

     if(outfile.is_open()==true){
         cout<<"ok"<<endl;
     }

     outfile<<"OFF"<<endl;

     int nv = 0;

     for(int i = 0; i < nx; i++){
         for(int j = 0; j < ny; j++){
             for(int k = 0; k < nz; k++){
                 if (v[i][j][k].isOn){
                     nv++;
                 }
             }
         }
     }

 outfile << 8*nv << " " << 6*nv << " " << 0 << endl;

 for(int k=0;k<nz; k++){
         for(int j=0;j<ny;j++){
             for (int i=0;i<nx;i++) {
                 if(v[i][j][k].isOn ){
                         outfile<<-0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl;
                         outfile<<-0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                         outfile<<0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                         outfile<<0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl;
                         outfile<<-0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl;
                         outfile<<-0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                         outfile<<0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                         outfile<<0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl;
                 }
             }
         }

     }


 int nf =0;
      for(int k=0;k<nz; k++){
           for(int j=0;j<ny;j++){
               for (int i=0;i<nx;i++) {
                   if(v[i][j][k].isOn){
                       outfile<<"4 "<<0+nf*8<<" "<<3+nf*8<<" "<<2+nf*8<<" "<<1+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                           <<"4 "<<4+nf*8<<" "<<5+nf*8<<" "<<6+nf*8<<" "<<7+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                           <<"4 "<<0+nf*8<<" "<<1+nf*8<<" "<<5+nf*8<<" "<<4+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                           <<"4 "<<0+nf*8<<" "<<4+nf*8<<" "<<7+nf*8<<" "<<3+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                           <<"4 "<<3+nf*8<<" "<<7+nf*8<<" "<<6+nf*8<<" "<<2+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                           <<"4 "<<1+nf*8<<" "<<2+nf*8<<" "<<6+nf*8<<" "<<5+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                       nf++;
                   }


               }
           }

       }
       outfile.close();

}
