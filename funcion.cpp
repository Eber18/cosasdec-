//ejemplo de funcion
#include<iostream>
using namespace std;
int suma(int a,int b){
    int r;
    r=a+b;
    return r;
}
int main(){
    int z;
    z=suma(5,3);
    cout<<"El resultado es: "<<z<<endl;
    system("PAUSE");
}
// int suma(int &a,int &b){} Con modificacion de valores
// int suma(const int &a,const int &b){} sin modificacion de valores
// inline int suma(int &a,int &b){} llamada en linea
// int suma(int &a,int &b=2){}  si hacemos esto al enviar los parametros toma el 2 como default ejemplo w=suma(10);
//definir una funcion anteriormete int suma(int, int)

// long fact (long n){
        //if(n>1) return n*fact(n-1)
        //else return 1;
//}

//template=plantilla <class T>{T suma(T,T)} x=suma<int>(a,b);
//template <class T, int n> T multiplica(t val){return val*n} x=multiplica<int,2>(10);
//global es estatico valor por default de 0, local es temporal no tiene valor puede arrojar cualquier cosa y se tiene que inicializar
//namespace mio{ int a,b} mio::a
