#include<iostream>
#include<cmath>
using namespace std;

class Potencia {
      private: float base;
               int exponente;
               
      public: Potencia(float Dato1, int Dato2);
              void Calcular_Potencia();
};

Potencia::Potencia(float Dato1, int Dato2) {
                         base=Dato1;
                         exponente=Dato2;
}

void Potencia::Calcular_Potencia() {
                              cout<<base<<"^"<<exponente<<"="<<pow(base,exponente)<<endl;
}

int main(void) {
    int expo;
    float base;
    cout<<endl<<endl<<"Ejemplifica el uso de clases sin plantillas"<<endl<<endl;
    cout<<"proporciona una base flotante: ";
    cin>>base;
    cout<<"proporciona un exponente entero: ";
    cin>>expo;
    Potencia Obj(base,expo);
    Obj.Calcular_Potencia();
    system("PAUSE");
}
