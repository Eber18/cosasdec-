#include<iostream>
#include <cmath>
using namespace std;

int maximo (int val1, int val2) {
    if (val1 > val2) return val1;
    else return val2;
}

double raiz (int num) {
       return sqrt(num);
}

int main(void) {
    int A,B,C;
    cout<<endl<<endl<<"Ejemplo de Funciones"<<endl<<endl;
    cout<<"proporciona un número entero: ";
    cin>>A;
    cout<<"proporciona otro entero: ";
    cin>>B;
    cout<<"el maximo de "<<A<<" y "<<B<<" es: "<<maximo(A,B)<<endl;
    cout<<"proporciona un entero para la raiz: ";
    cin>>C;
    cout<<"la raiz cuadrada de "<<C<<" es: " <<raiz(C)<<endl;
    system("PAUSE");
}
