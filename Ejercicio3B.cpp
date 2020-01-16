#include <iostream>
#include <iomanip>

using namespace std;

class MATRIZ{
      private: int **ar;
               unsigned short dim;
      public: MATRIZ (int dim);
              void leer(int dim);
              void sumar(int dim,const MATRIZ &, const MATRIZ &);
              void producto(int dim,const MATRIZ &, const MATRIZ &);
              void ver(int dim, const char *);
              ~MATRIZ();
};

MATRIZ::MATRIZ(int dim) {
                   ar=new int *[dim];
                   int i;
                   for (i=0;i<dim;i++) ar[i]=new int [dim];
                   for (i=0;i<dim;i++)
                       for (int j=0;j<dim;j++) ar[i][j]=0;
}

void MATRIZ::leer(int dim) {
     int i;
     for (i=0;i<dim;i++)
     for (int j=0;j<dim;j++) {
         cin>>ar[i][j];
     }
}

void MATRIZ::sumar(int dim,const MATRIZ &A,const MATRIZ &B){
     for (int i=0;i<dim;i++)
         for (int j=0;j<dim;j++)
             ar[i][j]=A.ar[i][j]+B.ar[i][j];
}

void MATRIZ::producto(int dim,const MATRIZ &A,const MATRIZ &B){
     for (int i=0;i<dim;i++)
         for (int j=0;j<dim;j++) {
             ar[i][j]=0;
             for (int k=0;k<dim;k++)
                 ar[i][j]=(A.ar[i][k]*B.ar[k][j])+ar[i][j];
         }
}

void MATRIZ::ver(int dim,const char *msg) {
     cout<<endl<<"\t\t"<<msg<<endl<<endl;
     for (int i=0;i<dim;i++) {
         cout<<"\t\t";
         for (int j=0;j<dim;j++) cout<< setw(6) << ar[i][j];
         cout<<endl;
     }
}

MATRIZ::~MATRIZ() {
                  delete []ar;
}

int main() {
    int dim;
    cout<<endl<<endl<<"Operaciones con matrices cuadradas utilizando memoria dinamica"<<endl<<endl;
    cout<<endl<<"Orden de la matriz: ";
    cin>>dim;
    MATRIZ A(dim),B(dim),C(dim);
    cout<<endl<<"Inserta "<<dim*dim<< " elementos de la matriz A:"<<endl;
    A.leer(dim);
    cout<<endl<<"Inserta "<<dim*dim<< " elementos de la matriz B:"<<endl;
    B.leer(dim);
    A.ver(dim,"Matriz A");
    B.ver(dim,"Matriz B");
    C.sumar(dim,A,B);
    C.ver(dim,"Matriz A + B");
    C.producto(dim,A,B);
    C.ver(dim,"Matriz A * B");
    system("PAUSE");
}
