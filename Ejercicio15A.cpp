#include<iostream>

using namespace std;

const int MAXCOLA=5;

template<class T>
class ColaCircular { 
      private: T EspacioCola[MAXCOLA];
               int Frente,Final;
      public:
             ColaCircular();
             int Put(const T);
             int Get();
             int ColaLlena()const;
             int ColaVacia()const;
             void VerCola(void)const;
};

template<class T>
ColaCircular<T>::ColaCircular() { 
                                Frente=MAXCOLA-1;
                                Final=MAXCOLA-1;
}

template<class T>
int ColaCircular<T>::ColaVacia(void) const {  
    if (Frente==Final)
       return 1;
    else
        return 0;
}

template<class T>
int ColaCircular<T>::ColaLlena(void) const {
    if((Final+1)%MAXCOLA==Frente) return 1;
    else return 0;
}

template<class T>
int ColaCircular<T>::Put(const T Dato) {
    if(ColaLlena()==1) return 0;
    Final=(Final+1)%MAXCOLA;
    EspacioCola[Final]=Dato;
    return 1;
}

template<class T>
int ColaCircular<T>::Get(void) {
    int Val;
    if(ColaVacia()==1) return 0;
    Frente=(Frente+1)%MAXCOLA;
    Val=EspacioCola[Frente];
    return Val;
}

template<class T>
void ColaCircular<T>::VerCola(void)const {
     int ini,fin;
     ini=Frente;
     fin=Final;
     if(ini==fin) 
                  cout<<endl<<"No hay elementos que mostrar.";
     else {
          if(ini!=fin) {
                       cout<<endl<<"Estado de la cola: ";
                       while(ini!=fin) {   
                                       ini=(ini+1)%MAXCOLA;
                                       cout<<EspacioCola[ini]<<" ";
                       }
          }
     }
}

int main(void) {
    ColaCircular<int> ObjCola;
    char opc;
    int dato,band;
    cout<<endl<<"Implementacion de una cola estatica";
    do {
       cout<<endl<<endl<<"Menu de opciones:";
       cout<<endl<<"1.-Insertar(Put)";
       cout<<endl<<"2.-Eliminar (Get)";
       cout<<endl<<"3.-Ver";
       cout<<endl<<"4.-Salir"<<endl;
       cout<<endl<<"Elija una opcion:";
       cin>>opc;
       switch(opc) {
                   case '1': cout<<endl<<"Introduce un valor numerico: ";
                        cin>>dato;
                        band=ObjCola.Put(dato);
                        if(band==1)
                                   cout<<"El dato se ha insertado.";
                        else
                            if(band==0)
                                       cout<<"El dato no se pudo insertar, cola llena.";
                   break;
                   case '2': dato=ObjCola.Get();
                        if(dato!=0)
                                   cout<<endl<<"Se quito el:"<<dato;
                        else
                            if(dato==0) cout<<"Cola vacia.";
                   break;
                   case '3': ObjCola.VerCola();
                   break;
                   case '4': cout<<"El programa ha terminado."<<endl;
                   break;
       }
    } while(opc!='4');
}
