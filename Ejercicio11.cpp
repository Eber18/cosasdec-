#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

template<class T>
class Nodo {
      public:
             T info;
             Nodo<T> *sig;
             Nodo( const T);
};

template<class T>
class Pila{
      private:
              Nodo<T> *Cima;
      public:
      Pila();
      ~Pila();
      void Push(const T);
      T Pop();
      void Ver();
      int Vacia();
};

template<class T>
Nodo<T>::Nodo(const T v) {
                    info = v;
                    sig = NULL;
}

template<class T>
Pila<T>::Pila() {
                Cima = NULL;
}

template<class T>
Pila<T>::~Pila() {
                 Nodo<T> *sale;
                 T val;
                 while(Cima) {
                             sale=Cima;
                             Cima=Cima->sig;
                             val=sale->info;
                             delete(sale);
                             cout<<"Bloque de memoria Liberado:"<<val<<endl;
                 }
                 delete(Cima);
}

template<class T>
void Pila<T>::Push(const T v) {
     Nodo<T> *nvo = new Nodo<T>(v);
     nvo->sig=Cima;
     Cima=nvo;
}

template<class T>
T Pila<T>::Pop() {
  Nodo<T> *sale;
  T val;
  if(Vacia()) val=0;
  else {
       sale=Cima;
       Cima=sale->sig;
       val=sale->info;
       delete(sale);
  }
  return val;
}

template<class T>
int Pila<T>::Vacia(){
    return Cima==NULL ? 1 : 0;
}

template<class T>
void Pila<T>::Ver()  {
     Nodo<T> *tmp = Cima;
     if(Vacia()) cout<<"No existe nada en la pila.";
     else {
          cout <<endl<<"La pila contiene: ";
          while (tmp){ 
                cout << setw(5) << tmp->info;
                tmp = tmp->sig;
          }
     }
     cout <<endl;
}

int main(){
    Pila <char> pila;
    string v;
    bool band;
    cout<<"Aplicaciones de las pilas: Palindromas"<<endl<<endl;
    cout<<"ingrese una cadena"<<endl;
    getline(cin,v);
    for(int i=0;i<v.size();i++){
            if(v[i]!=' '){
                       pila.Push(v[i]);
            }
    }
    for(int j=0;j<v.size();j++){
            if(v[j]!=' '){
                       if(v[j]==pila.Pop()){
                                            band=true;
                       }
                       else{
                            band=false;
                            break;
                       }
            }
    }
    if(band){
             cout<<"es palindroma"<<endl;
    }
    else{
         cout<<"no es palindroma"<<endl;
    }
    cout<<endl;
    system("PAUSE");
}
