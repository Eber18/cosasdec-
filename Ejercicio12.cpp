#include <iostream>
#include <iomanip>
#include "pila.h"

using namespace std;

static Pila <char> A,B,C;

void Mover(char O,char D){
     cout<<"hola"<<endl;
}

int main(){
    Pila <int> pila,A,B,C;
    int valor;
    char opc;
    cout<<"Operaciones con varias pilas"<<endl;
    do{
       cout<<"\n1.-Insertar\n2.-Eliminar\n3.-Mover\n4.-Ver pilas\n5.-Salir\n\n";
       cout<<"Opcion: ";
       cin>>opc;
       switch(opc){
                   case '1':
                        cout<<endl<<"introduce un valor diferente de cero:";
                        cin>>valor;
                        A.Push(valor);
                        break;
       }
    }while(opc!='4');
    Mover(' ','1');
    system("PAUSE");
}
/*
                   case '2': 
                        valor=pila.Pop();
                        if(valor ==0) cout<<endl<<"La Pila esta vacia."<<endl;
                        else cout<<endl<<"Se elimino dato: "<<valor<<endl;
                        break;
                   case '3': pila.Ver();
                        break;
       }
    } while(opc!='4');
}*/

