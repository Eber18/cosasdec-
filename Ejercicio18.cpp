#include<iostream> 
#include <iomanip> 

using namespace std; 

template<class T> 
class NodoArbol { 
    public: NodoArbol<T> *HijoIzq; 
                 NodoArbol<T> *HijoDer; 
                 NodoArbol(T); 
                 T Info; 
}; 

template<class T> 
NodoArbol<T>::NodoArbol(T v) { 
    Info = v; 
    HijoIzq=NULL; 
    HijoDer=NULL; 
} 

template<class T> 
class Arbol { 
    public: NodoArbol<T> *Raiz; 
                Arbol(); 
                NodoArbol<T> *Ins_Izq(T,T); 
                NodoArbol<T> *Ins_Der(T,T); 
                NodoArbol<T> *BEA(T); 
                NodoArbol<T> *BEP(T); 
}; 

template<class T> 
Arbol<T>::Arbol() { 
    Raiz=NULL; 
} 

template<class T> 
NodoArbol<T> *Arbol<T>::Ins_Izq(T Padre,T Dato) { 
    NodoArbol<T> *Apu; 
    if(Raiz!=NULL) { 
        Apu=BEA(Padre); 
        if(Apu==NULL) return NULL; 
        if(Apu->HijoIzq==NULL) return Apu->HijoIzq=new NodoArbol<T>(Dato); 
        else return NULL; 
    } 
    else return Raiz=new NodoArbol<T>(Dato); 
}

template<class T> 
NodoArbol<T> *Arbol<T>::Ins_Der(T Padre,T Dato) { 
    NodoArbol<T> *Apu; 
    if(Raiz!=NULL) { 
        Apu=BEA(Padre); 
        if(Apu==NULL) return NULL; 
        if(Apu->HijoDer==NULL) return Apu->HijoDer=new NodoArbol<T>(Dato); 
        else return NULL; 
    } 
    else return Raiz=new NodoArbol<T>(Dato); 
} 

template<class T> 
NodoArbol<T> *Arbol<T>::BEP(T Dato) { 
    NodoArbol<T> *Apu=Raiz; 
    if (Raiz != NULL) { 
        int Cima=-1; 
        NodoArbol<T> *pila[10];
        cout<<endl<<"inicio la busqueda del dato: "<<Dato<<endl; 
        do { 
            cout<<endl<<"checando el nodo: "<<Apu->Info<<endl; 
            if (Apu->Info==Dato) { 
               cout<<"Nodo encontrado."<<endl; 
               return Apu; 
            } 
            else { 
                if (Apu->HijoDer !=NULL) { 
                   Cima++; 
                   pila[Cima]=Apu->HijoDer; 
                   if (Cima>=10) cout <<"OJO: Pila llena"; 
                } 
                if (Apu->HijoIzq !=NULL) { 
                   Cima++; 
                   pila[Cima]=Apu->HijoIzq; 
                   if (Cima>=10) cout <<"OJO: Pila llena"; 
                } 
                cout << "estado actual de la pila: "; 
                for (int i=0;i<=Cima;i++) cout <<setw(6)<<pila[i]->Info; 
                if(Cima==-1) break; 
                Apu=pila[Cima]; 
                Cima--; 
            } 
        } while (true); 
    } 
    cout<<endl; 
    return NULL; 
}

template<class T> 
NodoArbol<T> *Arbol<T>::BEA(T Dato) { 
    NodoArbol<T> *Apu=Raiz; 
    if (Raiz != NULL) { 
        int i,Frente=-1,Final=0; 
        NodoArbol<T> *cola[10]; 
        cout<<endl<<"inicio la busqueda del dato: "<<Dato<<endl; 
        do { 
            cout<<endl<<"checando el nodo: "<<Apu->Info<<endl; 
            if (Apu->Info==Dato) { 
                cout<<"Nodo encontrado."<<endl; 
                return Apu;
            } 
            else { 
                if (Apu->HijoIzq !=NULL) { 
                    cola[Final]=Apu->HijoIzq; 
                    Final++; 
                    if (Final>10) Final=0; 
                } 
                if (Apu->HijoDer !=NULL) { 
                    cola[Final]=Apu->HijoDer; 
                    Final++; 
                    if (Final>10) Final=0; 
                } 
                if (Final==Frente+1) break; 
                cout << "estado actual de la cola: "; 
                i=Frente+1; 
                while (i<Final){ 
                    cout <<setw(6)<<cola[i]->Info; 
                    i++; 
                    if (i>10) i=0; 
                } 
                Frente++; 
                Apu=cola[Frente]; 
                if (Frente>=10) Frente=-1; 
            } 
        } while (Final!=Frente); 
    } 
    cout<<endl; 
    return NULL; 
}

int main (void) { 
    Arbol<int> arbol; 
    NodoArbol<int> *Apu; 
    char Opc; 
    int Valor,Padre; 
    do { 
        cout<<endl<<"Implementacion de un arbol Binario\n"; 
        cout<<"\n1.- Insertar un nodo izquierdo\n2.- Insertar un nodo derecho\n"; 
        cout<<"3.- Realizar busqueda en Profundidad\n4.- Realizar busqueda en Anchura\n"; 
        cout<<"5.- Salir\n\nOpcion: "; 
        cin>>Opc; 
        switch(Opc) { 
            case '1': cout<<endl<<"Introduce el valor del Nodo Padre: "; 
                 cin>>Padre; 
                 cout<<endl<<"Introduce el valor a insertar: "; 
                 cin>>Valor;
                 Apu=arbol.Ins_Izq(Padre,Valor);
                 if (Apu==NULL) cout<<"No procedio la insercion"<<endl;
                 else cout<<"Se inserto el valor: "<<Apu->Info<<endl;
                 break; 
            case '2': cout<<endl<<"Introduce el valor del Nodo Padre: ";
                 cin>>Padre;
                 cout<<endl<<"Introduce el valor a insertar: ";
                 cin>>Valor;
                 Apu=arbol.Ins_Der(Padre,Valor);
                 if (Apu==NULL) cout<<"No procedio la insercion"<<endl;
                 else cout <<"Se inserto el valor: "<<Apu->Info<<endl;
                 break;
            case '3': cout<<endl<<"Introduce un valor a buscar: ";
                 cin>>Valor;
                 Apu=arbol.BEP(Valor);
                 if (Apu==NULL) cout<<"No se encontro el valor"<<endl;
                 break; 
            case '4': cout<<endl<<"Introduce un valor a buscar: ";
                 cin>>Valor;
                 Apu=arbol.BEA(Valor);
                 if (Apu==NULL) cout<<"No se encontro el valor"<<endl;
                 break; 
        } 
    } while(Opc!='5'); 
} 
