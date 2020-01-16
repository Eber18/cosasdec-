#include<iostream>
#include<cmath>
using namespace std;
int main(void) {
    int valor;
    cout<<"Division entre 2 mediante el desplazamiento de bits a la derecha ."<<endl<<endl;
    while (true) {
          cout<<"Dame un numero: ";
          cin>>valor;
          if (valor==0) break;
          while (abs(valor)!=1) {
                cout<<"El valor "<<valor<<" se va a desplazar una posicion a la derecha.";
                valor=valor>>1;
                cout<<endl<<"Convirtiendose ahora en el valor: ";
                cout<<valor<<endl<<endl;
          }
    }
}
