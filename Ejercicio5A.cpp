#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Nodo {
      public:
             Nodo *sig;
             int valor;
             string nombre;
             float sueldo;
             Nodo(int v, string n, float s) {
                      sig=NULL;
                      valor = v;
                      nombre=n;
                      sueldo=s;
             }
};

class Lista {
      public:
             Lista() { le = NULL; }
             ~Lista();
             void Insertar(int v,string n, float s);
             int Eliminar(int v);
             bool Vacia() { return le == NULL;} 
             void Ver();
             private:
                     Nodo *le;
};

Lista::~Lista() {
                Nodo *aux;
                while(le) {
                          aux = le;
                          le = le->sig;
                          delete aux;
                }
}

void Lista::Insertar(int v,string n, float p) {
     Nodo *tmp;
     if(Vacia() ||le->valor > v) {
                Nodo *nvo= new Nodo(v,n,p);
                nvo->sig=le;
                le=nvo;
     }
     else {
          tmp= le;
          while(tmp->sig && tmp->sig->valor <= v) tmp= tmp->sig;
          Nodo *nvo= new Nodo(v,n,p);
          nvo->sig=tmp->sig;
          tmp->sig = nvo;
     }
     Ver();
}

int Lista::Eliminar(int v) {
    Nodo *tmp, *nodo;
    nodo = le;
    tmp = NULL;
    while(nodo && nodo->valor < v) {
               tmp = nodo; 
               nodo = nodo->sig;
    }
    if(!nodo || nodo->valor != v) return 0;
    else {  
         if(nodo==le) 
                      le = nodo->sig;
         else tmp->sig = nodo->sig;
         delete nodo;
    }
    return v;
}

void Lista::Ver() {
     Nodo *tmp=le;
     if(Vacia()) cout << "La Lista esta Vacia."<<endl;
     else {
          cout <<endl<< "La Lista actual es:\n";
          while(tmp) {
                     cout<< setw(5) << tmp->valor<< setw(18) <<tmp->nombre<< setw(12) <<tmp->sueldo<<endl;
                     tmp= tmp->sig;
          }
     }
     cout << endl;
}

int main() {
    Lista le;
    string nombre;
    float sueldo;
    int valor;
    bool band;
    char opc;
    cout<<endl<<"Implementacion de una Lista con nodos complejos\n\n";
    do {
       cout<<"\n1.-Insertar \n2.-Eliminar \n3.-Ver lista actual\n4.-Salir\n\n";
       cout<<"Opcion: ";
       cin>>opc;
       switch(opc) {
                   case '1': cout<<endl<<"Introduce un valor: ";
                        cin>>valor;
                        cout<<endl<<"Introduce un nombre: ";
                        cin>>nombre;
                        cout<<endl<<"Introduce un sueldo: ";
                        cin>>sueldo;
                        le.Insertar(valor,nombre,sueldo);
                        break;
                   case '2': cout<<endl<<"Introduce el valor a eliminar: ";
                        cin>>valor;
                        band=le.Eliminar(valor);
                        if(!band) cout<<endl<<"El dato no se encuentra."<<endl;
                        else cout<<endl<<"El dato ha sido eliminado." <<endl;
                        le.Ver();
                        break;
                   case '3': le.Ver();
                        break;
       }
    }while(opc!='4');
}
