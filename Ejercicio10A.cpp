#include<iostream>
#include <iomanip>

using namespace std;

const int MAX=6;

template<class T>
class Pila{
      private: T Arreglo [MAX];
               int cima;
      public:
             Pila();
             void Push(const T Dato);
             int Pop(void);
             int PilaLlena(void);
             int PilaVacia(void);
             void Ver(void);
};

template<class T>
Pila<T>::Pila(){
                cima=-1;
}

template<class T>
int Pila<T>::PilaVacia(void){
    return (cima==-1);
}

template<class T>
int Pila<T>::PilaLlena(void){
    return (cima==(MAX-1));
}

template<class T>
void Pila<T>::Push(const T Dato){
     if(PilaLlena())cout<<"Pila llena\n";
     else Arreglo[++cima]=Dato;
}

template<class T>
int Pila<T>::Pop(void){
    int Val;
    if(!PilaVacia()) {
                     Val=Arreglo[cima--];
                     return Val;
    }
}

template<class T>
void Pila<T>::Ver(void){
     int i=0,j;
     j=cima;
     if(j==-1) cout<<"\nNo hay datos que mostrar";
     else {
          cout<<endl<<"Los datos contenidos en la pila son:";
          while(j>=i) {
                      cout<< setw(5) <<Arreglo[j];
                      j--;
          }
     }
     cout<<endl;
}

int main(void){
    Pila<int> pila;
    char opc;
    int dato;
    cout<<"Implementacion de una pila estatica"<<endl<<endl;
    do {
       cout<<"\nMenu de opciones:";cout<<"\n1.-Insertar\n2.-Eliminar\n3.-Ver\n4.-Salir\n";
       cout<<"\nElija una opcion:";
       cin>>opc;
       switch(opc) {
                   case '1': 
                        if(!pila.PilaLlena()) {
                                              cout<<"\nDame el dato a insertar: ";
                                              cin>>dato;
                                              pila.Push(dato);
                        }
                        else cout<<"\nLa Pila esta llena.";
                        break;
                   case '2': 
                        if(pila.PilaVacia())cout<<"\nLa Pila esta vacia\n";
                        else  cout<<"El dato eliminado es: "<<pila.Pop();
                        break;
                   case '3': 
                        pila.Ver();
                        break;
       }
    }while(opc!='4');
}
