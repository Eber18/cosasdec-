#include <iostream>
#include <cstring>

using namespace std;

class Nodo { 
      public: 
               Nodo *sig; 
               Nodo *PrimerModelo; 
               string nombre; 
      public: 
              Nodo(){ 
                      sig=NULL;
                      PrimerModelo=NULL; 
                      nombre=""; 
              }
};
 
class Autos { 
      private: Nodo *PrimerMarca; 
      public: Autos(){ PrimerMarca=NULL; }
      
              void InsertarMarca(){
                   string marca;
                   cout<<endl<<"Escriba el nombre de la marca: "; 
                   cin>>marca;
                   Nodo *nuevo,*aux;
                   nuevo=new Nodo;
                   if(PrimerMarca==NULL){
                                         PrimerMarca=nuevo;
                                         PrimerMarca->nombre=marca;
                                         return;
                   }
                   if(PrimerMarca!=NULL){
                                         if(PrimerMarca->nombre<marca){
                                                                       aux=PrimerMarca;
                                                                       while(aux->sig!=NULL){
                                                                                            aux=aux->sig;
                                                                       }
                                                                       aux->sig=nuevo;
                                                                       if(aux->sig->nombre!=marca)
                                                                       nuevo->nombre=marca;
                                                                       else cout<<"Ya existe marca!"<<endl;
                                         }
                   }
              }
              
              void InsertarModelo(){
                   string marca,modelo;                    
                   if(PrimerMarca!=NULL){
                                         cout<<endl<<"Escriba el nombre de la marca a la que asignara un modelo: ";
                                         cin>>marca;
                                         Nodo*aux;
                                         aux=PrimerMarca; 
                                         while(aux->nombre!=marca && aux->sig!=NULL) aux=aux->sig;
                                         if(aux->nombre==marca){
                                                                cout<<endl<<"Escriba el nombre del modelo: ";
                                                                cin>>modelo;
                                                                Nodo *aux2,*nuevo;
                                                                nuevo=new Nodo;
                                                                nuevo->nombre=modelo;
                                                                if(aux->PrimerModelo==NULL) aux->PrimerModelo=nuevo;
                                                                else {
                                                                     if(aux->PrimerModelo->nombre==modelo){
                                                                                                      cout<<"Modelo existente!"<<endl;
                                                                     }
                                                                     else{
                                                                          aux2=aux->PrimerModelo;
                                                                          while(aux2->sig!=NULL) aux2=aux2->sig;
                                                                          aux2->sig=nuevo;     
                                                                     }
                                                                     
                                                                }
                                         }
                                         else cout<<"No existe la marca ingresada!!"<<endl;
                   }
                   else cout<<"Antes de ingresar un modelo, ingrese una marca"<<endl;
              }
              
              void Presentar(){ 
                   if(PrimerMarca!=NULL){
                                         Nodo*aux;
                                         aux=PrimerMarca; 
                                         do {
                                            cout<<endl<<"MARCA: "+aux->nombre<<"\n"; 
                                            if(aux->PrimerModelo!=NULL){
                                                                        Nodo *aux2;
                                                                        aux2=aux->PrimerModelo; 
                                                                        do { 
                                                                           cout<<"  MODELO: "+aux2->nombre<<"\n";
                                                                           aux2=aux2->sig;
                                                                        } while(aux2!=NULL);
                                            }
                                            else cout<<aux->nombre+" No tiene modelos"<<endl;
                                            aux=aux->sig;
                                         } while(aux!=NULL);
                   }
              }
};

int main(){ 
    char opc;
    Autos autos; 
    do{ 
        cout<<endl<<endl; 
        cout<<"1. Insertar Marca"<<endl; 
        cout<<"2. Insertar Modelo de una Marca"<<endl; 
        cout<<"3. Presentar"<<endl; 
        cout<<"4. Salir"<<endl<<endl; 
        cout<<"Ingrese una opcion: "; 
        cin>>opc; 
        switch(opc) { 
                    case '1': 
                         autos.InsertarMarca(); 
                         break; 
                    case '2': 
                         autos.InsertarModelo();
                         break;
                    case '3': 
                         autos.Presentar();
                         break;
        } 
    } while(opc!='4');
};
