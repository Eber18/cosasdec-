#include<iostream>
#include <cmath>
#include <string>

using namespace std;

template < class t>
         t maximo (t val1, t val2) {
           if (val1 > val2) return val1;
           else return val2;
         }

template < class t>
         double raiz (t num) {
                return sqrt(num);
         }

int main(void) {
    int A,B,C;
    string F,G;
    float H;
    cout<<endl<<endl<<"Ejemplo de Plantillas de Funciones"<<endl;
    cout<<"proporciona un numero entero: ";
    cin>>A;
    cout<<"proporciona otro entero: ";
    cin>>B;
    cout<<"el maximo de "<<A<<" y "<<B<<" es: "<<maximo(A,B)<<endl;
    cout<<"proporciona una cadena: ";
    cin>>F;
    cout<<"proporciona otra cadena: ";
    cin>>G;
    cout<<" el maximo de "<<F<<" y "<<G<<" es: "<<maximo(F,G)<<endl;
    cout<<endl<<"proporciona un entero para la raiz: ";
    cin>>C;
    cout<<"la raiz cuadrada de "<<C<<" es: " <<raiz(C)<<endl;
    cout<<endl<<"proporciona un flotante para la raiz: ";
    cin>>H;
    cout<<"la raiz cuadrada de "<<H<<" es: " <<raiz(H)<<endl;
    system("PAUSE");
}
