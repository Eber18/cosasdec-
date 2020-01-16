#include<iostream>
#include<iomanip>
using namespace std;


template<class T>
class Nodo {
    public: 
        T info,dist;
        string pueblo;
        Nodo<T> *sig;
        Nodo(const T,const T,string s);
};


template<class T>
class Cola {
    private: 
        Nodo<T> *Ini,*Fin;
    public:
        Cola();
        ~Cola();
        void Put(const T,const T, string s);
        T Get();
        void Ver();
        int Vacia();
        T contar(const T,const T);
};


template<class T>
Nodo<T>::Nodo(const T v, const T x, string s) {
    info = v;
    dist = x;
    pueblo = s;
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
void Cola<T>::Put(const T v, const T x, string s) {
    Nodo <T>*nvo= new Nodo<T>(v,x,s);
    if(Vacia())
        Ini=Fin=nvo;
    else {
        Fin->sig=nvo;
        Fin=nvo;
    }
}


template<class T>
T Cola<T>::contar(const T v,const T x){
    Nodo <T>*tmp = Ini;
    int cont=0;
    if(Vacia()) {
        cout<<endl<<"Lista Cola esta vacia.";
		return 0;
	}
    else {
        while(tmp->info<v){
            tmp=tmp->sig;
        }
        while(tmp->info<x){
            tmp=tmp->sig;
            cont+=tmp->dist;
        }
	   return cont;
    }
    //return cont;
}

template<class T>
int Cola<T>::Vacia(){
    return (Ini==NULL && Fin==NULL) ?1 :0;
}


template<class T>
void Cola<T>::Ver(){
    Nodo <T>*tmp = Ini;
    if(Vacia()) 
        cout<<endl<<"Lista Cola esta vacia.";
    else {
        cout << "\nLa cola es: \n";
        while (tmp) {
            cout << tmp->info<<setw(4)<< tmp->dist<<setw(4)<< tmp->pueblo<<"\n\n";
            tmp = tmp->sig;
        }
    }
    cout <<endl;
}


int main(void) {
    Cola <int> cola;
    char opc;
    int valor,val;
    string val2;
    cout<<endl<<"\nImplementacion de una Cola mediante una Lista"<<endl;
    do {
        cout<<"\n1.- Insertar(Put)\n2.- Mostrar recorrido.\n3.- Ver\n4.- Salir\n\n";
        cout<<"Opcion: ";
        cin>>opc;
        switch(opc) {
            case '1': 
                cout<<endl<<"Introduce la etapa de viaje: ";
                cin>>valor;
                cout<<endl<<"Introduce la localidad: ";
                cin>>val2;
                cout<<endl<<"Introduce la distancia: ";
                cin>>val;
                
                cola.Put(valor,val,val2);
            break;
            case '2':
                int in,fi;
                if(valor==0)
                    cout<<endl<<"La Cola esta vacia."<<endl;
                else{
                    cola.Ver();
                    cout<<"Ingrese localidad de partida\n";
                    cin>>in;
                    cout<<"Ingrese destino de llegada\n";
                    cin>>fi;
                    cout<<"La distancia entre el punto "<<in<<" y el punto "<<fi<<" es: "<<cola.contar(in,fi);
                }
            break;
            case '3': 
                cola.Ver();
            break;
        }
    } while(opc!='4');
}
