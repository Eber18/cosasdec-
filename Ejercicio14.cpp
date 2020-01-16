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
    Pila <int> pila;
    string v,a="";
    bool band;
    cout<<"Aplicaciones de las pilas: notacion postfija"<<endl<<endl;
    cout<<"ingrese una cadena"<<endl;
    cout<<"como este ejemplo 5 10 15 + - "<<endl;
    getline(cin,v);
    for(int i=0;i<v.size();i++){
            if(v[i]=='1'||v[i]=='2'||v[i]=='3'||v[i]=='4'||v[i]=='5'||v[i]=='6'||v[i]=='7'||v[i]=='8'||v[i]=='9'){
                          pila.Push(v[i]);
            }
            if(v[i]=='+'){
                          int y=pila.Pop();
                          cout<<y<<endl;
                          int x=pila.Pop();
                          cout<<x<<endl;
                          pila.Push(x+y);
            }
            if(v[i]=='-'){
                          const char y=pila.Pop();
                          const char x=pila.Pop();
                          pila.Push(x-y);
            }
            if(v[i]=='*'){
                          const char y=pila.Pop();
                          const char x=pila.Pop();
                          pila.Push(x*y);
            }
            if(v[i]=='/'){
                          const char y=pila.Pop();
                          const char x=pila.Pop();
                          pila.Push(x/y);
            }
            if(v[i]=='^'){
                          const char y=pila.Pop();
                          const char x=pila.Pop();
                          pila.Push(x+y);
            }
    }
    pila.Ver();
    cout<<a<<endl;
    system("PAUSE");
}
