#include<iostream>
#include<cmath>
using namespace std;

template<class T1, class T2>
class Potencia {
      private: T1 base;
               T2 exponente;
      public: Potencia(T1,T2);
              void Calcular_Potencia();
};

template<class T1, class T2>
Potencia<T1,T2>::Potencia(T1 Dato1,T2 Dato2) {
                             base=Dato1;
                             exponente=Dato2;
}

template<class T1, class T2>
void Potencia<T1,T2>::Calcular_Potencia() {
                                     cout<<base<<"^"<<exponente<<"="<<pow(base,exponente)<<endl;
}

int main(void) {
    double expo,base;
    cout<<endl<<endl<<"Ejemplifica el uso de plantillas de clases"<<endl<<endl;
    cout<<"proporciona una base doble: ";
    cin>>base;
    cout<<"proporciona un exponente doble: ";
    cin>>expo;
    Potencia<double,double> Obj(base,expo);
    Obj.Calcular_Potencia();
    system("PAUSE");
}
