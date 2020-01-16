#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
class Nodo {
      public:
             T info;
             Nodo<T> *sig;
             Nodo(const T);
};

template <class T>
class Lista {
      private: Nodo <T> *le;
      public: Lista ();
              ~ Lista ();
              void Ins_Ini(const T);
              void Ins_Fin(const T);
              T Eli_Ini();
              T Eli_Fin();
              void Ver();
              int  Vacia();
};

template <class T>
Nodo<T>::Nodo(const T v) {
                    info = v;
                    sig = NULL;
}

template <class T>
Lista<T>::Lista() {
                  le= NULL;
}

template <class T>
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

template <class T>
void Lista<T>::Ins_Ini(const T v) {
     Nodo <T>*nvo = new Nodo<T>(v);
     nvo->sig=le;
     le=nvo;
}

template <class T>
void Lista<T>::Ins_Fin(const T v) {
     Nodo <T>*nvo = new Nodo<T>(v);
     Nodo <T>*tmp;
     if(Vacia()) le=nvo;
     else {
          tmp=le;
          while(tmp->sig!=NULL) tmp=tmp->sig;
          tmp->sig=nvo;
     }
}

template<class T>
T Lista<T>::Eli_Ini() {
  Nodo <T>*sale;
  T val;
  if(Vacia()) val=0;
  else {
       sale=le;
       le=sale->sig;
       val=sale->info;
       delete sale;}
  return val;
}

template<class T>
T Lista<T>::Eli_Fin() {
  Nodo <T>*sale, *aux;
  T val;
  if(Vacia()) return 0;
  else {
       sale=le;
       if(le->sig==NULL) le=NULL;
       else {
            while(sale->sig!=NULL) {
                                   aux=sale;
                                   sale=sale->sig;
            }
            aux->sig=NULL;
       }
       val=sale->info;
       delete sale;
       return val;
  }
}

template<class T>
int Lista<T>::Vacia()  {
    return le==NULL ? 1 : 0;
}

template<class T>
void Lista<T>::Ver()  {
     Nodo <T>*tmp = le;
     if(Vacia()) cout<<"Lista vacia.";
     else {
          cout <<endl<< "La lista es: ";
          while (tmp) {
                cout << setw(5) << tmp->info;
                tmp = tmp->sig;
          }
     }
     cout <<endl;
}

int main(void) {
    Lista <int> lista;
    int valor;
    char opc;
    cout<<endl<<"Implementacion de una Lista Simple"<<endl;
    do {
       cout<<"\n1.-Insertar Inicio\n2.-Insertar Final";
       cout<<"\n3.-Eliminar Inicio\n4.-Eliminar Final";
       cout<<"\n5.-Ver lista actual\n6.-Salir\n\nOpcion: ";
       cin>>opc;
       switch(opc) {
                   case '1': cout<<endl<<"Introduce un valor diferente de cero: ";
                        cin>>valor;
                        lista.Ins_Ini(valor);
                        break;
                   case '2': cout<<endl<<"Introduce un valor diferente de cero: ";
                        cin>>valor;
                        lista.Ins_Fin(valor);
                        break;
                   case '3': valor=lista.Eli_Ini();
                        if(valor ==0) cout<<endl<<"Lista vacia."<<endl;
                        else cout<<endl<<"Se elimino dato: "<<valor <<endl;
                        break;
                   case '4': 
                        valor =lista.Eli_Fin();
                        if(valor ==0) cout<<endl<<"Lista vacia."<<endl;
                        else cout<<endl<<"Se elimino dato: "<<valor <<endl;
                        break;
                   case '5': lista.Ver();
                   break;
       }
    } while(opc!='6');
}
