using namespace std;

template<class T>
class Nodo {
      public:
             T info;
             Nodo <T> *sig;
             Nodo(const T);
};

template<class T>
class Pila{
      private:
              Nodo <T> *Cima;
      public:
             Pila();
             ~Pila();
             void Push(const T v);
             T Pop();
             //T Mirar();
             //void Ver();
             T Vacia();
             //T Verif(const T n);
};


/*template<class T>
T Pila<T>::Mirar(){
    Nodo<T> *sale;
    int val;
    if(Vacia())
        val=0;
    else {
        sale=Cima;
        val=sale->info;
    }
    return val;
}
*/

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
    if(Vacia())
               val=0;
    else {
         sale=Cima;
         Cima=sale->sig;
         val=sale->info;
         delete(sale);
    }
    return val;
}


template<class T>
T Pila<T>::Vacia(){
    return Cima==NULL ? 1 : 0;
}


/*template<class T>
void Pila<T>::Ver()  {
     Nodo<T> *tmp = Cima;
     if(Vacia())
                cout<<"No existe nada en la pila.";
     else {
          cout <<endl<<"La pila contiene: ";
          while (tmp){
                cout << setw(5) << tmp->info;
                tmp = tmp->sig;
          }
     }
     cout <<endl<<endl;
}


template<class T>
T Pila<T>::Verif(const T n){
    int cont = 1;
    int band = 1;
    Nodo <T> *sale;
    int val;
    if(Vacia()){
        band = 0;}
    else{
    	sale=Cima;
		val=sale->info;
		do{
            if(val!=cont){
                band=0;
            }
            //else{
            	cont++;
			//}
			sale=sale->sig;
        }while(sale->sig!=NULL);
        
        if(n==cont){
            return band=1;
        }
    }
    //return band;
}
*/

