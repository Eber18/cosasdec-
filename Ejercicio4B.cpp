#include<iostream>
#include <iomanip>

using namespace std;

template <class T>
class Nodo {
      public: T info;
              Nodo <T> *ant,*sig;
              Nodo(const T);
};

template<class T>
class Lista_Doble {
      private: Nodo <T> *le;
      public:  Lista_Doble ();
               ~ Lista_Doble ();
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
                    ant  = NULL;
                    sig  = NULL;
}

template<class T>
Lista_Doble<T>::Lista_Doble() {
                              le = NULL;
}

template <class T>
Lista_Doble<T>::~Lista_Doble () {
                             Nodo <T>*sale;
                             T val;
                             while(le) {
                                       sale=le;
                                       le=le->sig;
                                       val=sale->info;
                                       delete(sale);
                                       cout<<"Bloque de Memo Liberado: "<<val<<endl;
                             }
                             delete le;
}

template <class T>
void Lista_Doble<T>::Ins_Ini(const T v) {
     Nodo <T>*nvo = new Nodo<T>(v);
     if(Vacia()) le=nvo;
     else {
          nvo->sig=le;
          le->ant=nvo;
          le=nvo;
     }
}

template <class T>
void Lista_Doble<T>::Ins_Fin(const T v) {
     Nodo <T>*nvo = new Nodo<T>(v);
     Nodo <T>*tmp;
     if(Vacia()) le=nvo;
     else {
          tmp=le;
          while(tmp->sig!=NULL) tmp=tmp->sig;
          tmp->sig=nvo;
          nvo->ant=tmp;
     }
}

template <class T>
T Lista_Doble<T>::Eli_Ini() {
  Nodo <T>*sale;
  T val;
  if(Vacia()) return 0;
  else {
       sale=le;
       if(sale->sig==NULL) le=NULL;
       else {
            le=sale->sig;
            le->ant=NULL;
            sale->sig=NULL;
       }
       val=sale->info;
       delete sale;
       return val;
  }
}

template <class T>
T Lista_Doble<T>::Eli_Fin() {
  Nodo <T>*sale,*aux;
  T val;
  if(Vacia()) return 0;
  else {
       sale=le;
       if(sale->sig==NULL) le=NULL;
       else {
            while(sale->sig!=NULL) {
                                   aux=sale;
                                   sale=sale->sig;
            }
            aux->sig=NULL;
            sale->ant=NULL;
       }
       val=sale->info;
       delete sale;
       return val;
  }
}

template <class T>
int Lista_Doble<T>::Vacia() {
    return le==NULL ? 1 : 0;
}

template <class T>
void Lista_Doble<T>::Ver() {
     Nodo <T>*tmp = le;
     if(Vacia()) cout<<endl<<"Lista vacia.";
     else {
          cout <<endl<<"La lista es: ";
          while (tmp) {
                cout << setw(5) << tmp->info;
                tmp = tmp->sig;
          }
     }
     cout <<endl;
}

int main(void) {
    Lista_Doble <int> le;
    int valor;
    char opc;
    cout<<endl<<" Implementacion de una Lista Doble"<<endl<<endl;
    do {
       cout<<"\n1.-Insertar Inicio\n2.-Insertar Final";
       cout<<"\n3.-Eliminar Inicio\n4.-Eliminar Final";
       cout<<"\n5.-Ver lista actual\n6.-Salir\n\nOpcion: ";
       cin>>opc;
       switch(opc) {
                   case '1': cout<<endl<<"Introduce un valor diferente de cero: ";
                        cin>>valor;
                        le.Ins_Ini(valor);
                        break;
                   case '2': cout<<endl<<"Introduce un valor diferente de cero: ";
                        cin>>valor;
                        le.Ins_Fin(valor);
                        break;
                   case '3': 
                        valor=le.Eli_Ini();
                        if(valor==0) cout<<endl<<"Lista vacia."<<endl;
                        else cout<<endl<<"Se elimino dato: "<<valor<<endl;
                        break;
                   case '4': 
                        valor=le.Eli_Fin();
                        if(valor==0) cout<<endl<<"Lista vacia."<<endl;
                        else cout<<endl<<"Se elimino dato: "<<valor<<endl;
                        break;
                   case '5': le.Ver();
                        break;
       }
    } while(opc!='6');
}
