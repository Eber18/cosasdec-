#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
class Nodo {
      public: T info;
              Nodo<T> *sig;
              Nodo(const T);
};

template<class T>
class Lista {
      private: Nodo <T> *le;
      public: Lista();
              ~Lista();
              void Insertar(const T);
              T Eliminar(const T);
              void Ver();
              int Vacia();
};

template<class T>
Nodo<T>::Nodo(const T v) {
                    info = v;
                    sig = NULL;
}

template<class T>
Lista<T>::Lista() {
                  le = NULL;
}

template<class T>
Lista<T>::~Lista() {
                   Nodo <T>*sale;
                   T val;
                   while(le) {
                             sale=le;
                             le=le->sig;
                             val=sale->info;
                             delete(sale);
                             cout<<"Bloque de memoria liberado: "<<val<<endl;
                   }
                   delete le;
}

template<class T>
void Lista<T>::Insertar(const T v) {
     Nodo<T> *tmp;
     if(Vacia() || le->info > v) {
                Nodo <T> *nvo = new Nodo<T>(v);
                nvo->sig = le;
                le= nvo;
     }
     else {
          tmp= le;
          while(tmp->sig && tmp->sig->info <= v) tmp = tmp->sig;
          Nodo <T>*nvo = new Nodo<T>(v);
          nvo->sig = tmp->sig;
          tmp->sig = nvo;
     }
     cout<<"Hemos insertado el valor. "<<v<<endl;
     Ver();
}

template<class T>
T Lista <T>::Eliminar(const T v) {
  Nodo <T>*tmp, *nodo;
  nodo = le;
  tmp= NULL;
  while(nodo && nodo->info< v) {
             tmp= nodo;
             nodo = nodo->sig;
  }
  if(!nodo || nodo->info!= v) return 0;
  else {
       if(nodo==le)
                   le= nodo->sig;
       else
                   tmp->sig= nodo->sig;
       delete nodo;
  }
  return v;
}

template<class T>
int Lista<T>::Vacia()  {
    return le==NULL ? 1 : 0;
}

template<class T>
void Lista<T>::Ver() {
     Nodo<T> *tmp=le;
     if(Vacia()) cout << "La lista esta Vacia.";
     else {
          cout << "La lista actual es: ";
          while(tmp) {
                     cout<<setw(5)<< tmp->info;
                     tmp= tmp->sig;
          }
     }
     cout << endl;
}

int main() {
    Lista <int> le;
    int valor, band;
    char opc;
    cout<<endl<<"Implementacion de una Lista Ordenada"<<endl;
    do {
       cout<<"\n1.-Insertar\n2.-Eliminar\n3.-Ver lista actual\n4.-Salir\n\n";
       cout<<"Opcion: ";
       cin>>opc;
       switch(opc) {
                   case '1': cout<<endl<<"Introduce un valor: ";
                        cin>>valor;
                        le.Insertar(valor);
                        break;
                   case '2': 
                        cout<<endl<<"Introduce un valor a eliminar: ";
                        cin>>valor;
                        band=le.Eliminar(valor);
                        if(band==0)cout<<endl<<"El dato no se encuentra."<<endl;
                        else
                            cout<<endl<<"El dato ha sido eliminado."<<endl;
                        le.Ver();
                        break;
                   case '3': 
                        le.Ver();
                        break;
       }
    }while(opc!='4');
}
