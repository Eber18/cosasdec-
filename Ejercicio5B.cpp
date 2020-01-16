#include <iostream>
#include <iomanip>

using namespace std;

struct Persona {
       int  Valor;
       char Nombre[15]; 
       float Sueldo; 
};

class Nodo {
      public: Persona F;
              Nodo *sig;
              Nodo(Persona);
};

class Lista {
      private: Nodo *le;
      public:  Lista();
               ~Lista();
               void Insertar(Persona);
               int Eliminar(Persona);
               void Ver();
               int Vacia();
};

Nodo::Nodo(Persona P) {
                   F = P;
                   sig = NULL;
}

Lista::Lista() {
               le = NULL;
}

Lista::~Lista() {
                Nodo *sale;
                int val;
                while(le) {
                          sale=le;
                          le=le->sig;
                          val=sale->F.Valor;
                          delete(sale);
                          cout<<"Bloque de memoria liberado: "<<val<<endl;
                }
                delete le;
}

void Lista::Insertar(Persona P) {
     Nodo *tmp;
     if (Vacia() || le->F.Valor > P.Valor) {
        Nodo *nvo = new Nodo(P);
        nvo->sig = le;
        le = nvo;
     }
     else {
          tmp = le;
          while(tmp->sig && tmp->sig->F.Valor <= P.Valor)  tmp = tmp->sig;
          Nodo *nvo = new Nodo(P);
          nvo->sig = tmp->sig;
          tmp->sig = nvo;
     }
     cout<<"Hemos insertado el valor. "<<P.Valor<<endl;
     Ver();
}

int Lista::Eliminar(Persona P) {
    Nodo *tmp, *nodo;
    nodo = le;
    tmp = NULL;
    while(nodo && nodo->F.Valor < P.Valor) {
               tmp = nodo; 
               nodo = nodo->sig;
    }
    if(!nodo || nodo->F.Valor != P.Valor) return 0;
    else {  
         if(nodo==le) 
                      le = nodo->sig;
         else tmp->sig = nodo->sig;
         delete nodo;
    }
    return P.Valor;
}

int Lista::Vacia() {
    return le==NULL ? 1 : 0;
}

void Lista::Ver() {
     Nodo *tmp=le;
     if(Vacia()) cout << "La lista esta Vacia.";
     else {
          cout << "La lista actual es: "<<endl;
          while(tmp) {
                     cout << setw(5) << tmp->F.Valor<< setw(18) << tmp->F.Nombre << setw(12);
                     cout << tmp->F.Sueldo<<endl;
                     tmp = tmp->sig;
          }
     }
     cout << endl;
}

int main() {
    Lista le;
    Persona Fulanito;
    int band;
    char opc;
    cout<<endl<<"Implementacion de una lista de registros\n\n";
    do {
       cout<<"\n1.-Insertar \n2.-Eliminar \n3.-Ver lista actual\n4.-Salir\n\n";
       cout<<"Opcion: ";
       cin>>opc;
       switch(opc) {
                   case '1': cout<<endl<<"Introduce el Valor: ";
                        cin>>Fulanito.Valor;
                        cout<<endl<<"Introduce el nombre: ";
                        cin>>Fulanito.Nombre;
                        cout<<endl<<"Introduce el Sueldo: ";
                        cin>>Fulanito.Sueldo;
                        le.Insertar(Fulanito);
                        break;
                   case '2': cout<<endl<<"Introduce un valor a eliminar: ";
                        cin>>Fulanito.Valor;
                        band=le.Eliminar(Fulanito);
                        if(band==0) cout<<endl<<"El dato no se encuentra."<<endl;
                        else cout<<endl<<"El dato ha sido eliminado."<<endl;
                        le.Ver();
                        break;
                   case '3': le.Ver();
                        break;
       }
    }while(opc!='4');
}
