#include<iostream>
#include<iomanip>

using namespace std;

template<class T>
class Nodo {
      public: T info;
              Nodo<T> *sig;
              Nodo( const T);
};

template<class T>
class Cola {
      private: 
               Nodo<T> *Ini,*Fin;
      public:
             Cola();~Cola();
             void Put(const T);
             T Get();
             void Ver();
             int Vacia();
};

template<class T>
Nodo<T>::Nodo(const T v) {
                    info = v;
                    sig = NULL;
}

template<class T>
Cola<T>::Cola() { 
                Ini= Fin = NULL;
}

template<class T>
Cola<T>::~Cola() {
                 Nodo <T> *sale;
                 int val;
                 while(Ini) {
                            sale=Ini;
                            Ini=Ini->sig;
                            val=sale->info;
                            delete(sale);
                            cout<<"Bloque de memoria liberado:"<<val<<endl;
                 }
                 delete(Ini);
}

template<class T>
void Cola<T>::Put(const T v) {
     Nodo <T>*nvo= new Nodo<T>(v);
     if(Vacia())
                Ini=Fin=nvo;
     else {
          Fin->sig=nvo;
          Fin=nvo;
     }
}

template<class T>
T Cola<T>::Get() {
  T val;
  Nodo<T> *sale = Ini;
  if(Vacia()) 
              val=0;
  else {
       val=sale->info;
       if(Ini==Fin) 
                    Ini=Fin=NULL;
       else Ini=sale->sig;
       delete sale;
  }
  return val;
}

template<class T>
int Cola<T>::Vacia(){
    return (Ini==NULL && Fin==NULL) ?1 :0;
}

template<class T>
void Cola<T>::Ver(){
     Nodo <T>*tmp = Ini;
     if(Vacia()) cout<<endl<<"Lista Cola esta vacia.";
     else {   
          cout << "\nLa cola es: ";
          while (tmp) {
                cout <<setw(4)<< tmp->info;
                tmp = tmp->sig;
          }
     }
     cout <<endl;
}

int main(void) {
    Cola <int> cola;
    char opc;
    int valor;
    cout<<endl<<"\nImplementacion de una Cola mediante una Lista"<<endl;
    do {
       cout<<"\n1.-Insertar(Put)\n2.-Eliminar (Get)\n3.-Ver\n4.-Salir\n\n";
       cout<<"Opcion: ";
       cin>>opc;
       switch(opc) {
                   case '1': cout<<endl<<"Introduce un valordiferente de cero: ";
                        cin>>valor;
                        cola.Put(valor);
                   break;
                   case '2': 
                        valor=cola.Get();
                        if(valor==0)
                                    cout<<endl<<"La Cola esta vacia."<<endl;
                        else
                            cout<<endl<<"El dato quitado es: "<<valor<<endl;
                   break;
                   case '3': 
                        cola.Ver();
                   break;
       }
    } while(opc!='4');
}
