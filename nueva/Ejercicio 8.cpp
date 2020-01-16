#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

class Nodo{
	private:
		Nodo *sig;
		Nodo *inferior;
		Nodo *Primero;
		string nombre;
	
	public:
		friend class Autos;
		Nodo(){
			sig = NULL;
			inferior = NULL;
			nombre = "";
			Primero = NULL;
		}	
};

class Autos{
	private: Nodo *PrimerMarca;
	public: Autos(){PrimerMarca = NULL;}
	
	void InsertarMarca(){
		string marca;
		cout << "Escriba el nombre de la marca: ";
		cin >> marca;
		Nodo *nuevo;
		nuevo = new Nodo;
		nuevo->nombre = marca;
		if(Existe(nuevo->nombre) == false){
			if(PrimerMarca == NULL) {
				PrimerMarca = nuevo;
				nuevo->sig=NULL;
			}
			else{
				Nodo *aux;
				if(PrimerMarca->nombre > nuevo->nombre){
					nuevo->sig = PrimerMarca;
					PrimerMarca = nuevo;
				}else{
					aux=PrimerMarca;
					while(aux->sig != NULL && (aux->sig)->nombre <= nuevo->nombre) aux=aux->sig;
					nuevo->sig=aux->sig;
					aux->sig=nuevo;
				}
			}
		}else cout << "La marca que intenta ingresar ya esta registrada";
	}
	
	void InsertarModelo(){
		string marca,modelo;
		if(PrimerMarca != NULL){
			cout << endl << "Escriba el nombre de la marca a la que le asignara un modelo: ";
			cin >> marca;
			Nodo *aux;
			aux = PrimerMarca;
			while(aux->nombre != marca && aux->sig != NULL) aux = aux->sig;
			if(aux->nombre == marca){
				cout << endl << "Escriba el nombre del modelo: ";
				cin >> modelo;
				Nodo *nuevo;
				nuevo = new Nodo;
				nuevo->nombre = modelo;
				if(Existe(nuevo->nombre,marca)==false){
					if(aux->inferior == NULL){
					aux->inferior = nuevo;
					aux->Primero = nuevo;
					nuevo->sig=NULL;
					}
					else{
					Nodo *aux2;
					if((aux->Primero)->nombre > nuevo->nombre){
						nuevo->sig = aux->Primero;
						aux->Primero = nuevo;
					}else{
						aux=aux->Primero;
						while(aux->sig != NULL && (aux->sig)->nombre <= nuevo->nombre) aux=aux->sig;
						nuevo->sig=aux->sig;
						aux->sig=nuevo;
					}
					}	
				}else cout << "El modelo que quiere ingresar ya ha sido registrado" << endl;
				
			}		
			else cout << "No existe la marca ingresada!!" << endl;	
		}
		else cout << "Antes de ingresar un modelo, ingrese una marca" << endl;
	}
	
	void Presentar(){
		if(PrimerMarca != NULL){
			Nodo *aux;
			aux = PrimerMarca;
			do{
				cout << endl << "MARCA: "+aux->nombre <<"\n";
				if(aux->Primero != NULL && aux->inferior != NULL){
					Nodo *aux2;
					aux2 = aux->Primero;
					do{
						cout << "MODELO: "+aux2->nombre << "\n";
						aux2 = aux2->sig;
					}while(aux2 != NULL);
				}
				else cout << aux->nombre+" No tiene modelos" << endl;
				aux = aux->sig;
			}while(aux != NULL);
		}
	}
	
	bool Existe(string nombreMarca){
		Nodo *aux3;
		aux3 = PrimerMarca;
		if(PrimerMarca == NULL) return false;
		else{
			while(aux3 != NULL){
				if(nombreMarca==aux3->nombre){
					return true;
					break;
				}
				aux3 = aux3->sig;
			}
		}
	}
	
	bool Existe(string nombreModelo,string marca1){
		Nodo *aux4;
		aux4=PrimerMarca;
		while(aux4 !=NULL){
			if(marca1 == aux4->nombre){
				if(aux4->Primero == NULL) return false;
				else{
					Nodo *auxMod;
					auxMod = aux4->Primero;
					while(auxMod != NULL){
						if(auxMod->nombre == nombreModelo){
							return true;
							break;
						}
						auxMod = auxMod->sig;
					}
				}
			}
			aux4 = aux4->sig;
		}
	}
	
	void EliminarMar(){
		string marca;
		cout << endl <<"Inserte la marca que desea eliminar: ";
		cin >> marca;
		Nodo *auxMarca;
		auxMarca = PrimerMarca;
		bool fo;
		if(auxMarca != NULL){
				if(auxMarca->nombre == marca){
					cout << endl << "Se elimino la marca "+ auxMarca->nombre << endl;
					if(auxMarca->sig == NULL) PrimerMarca = NULL;
					else{
						PrimerMarca=auxMarca->sig;
						auxMarca=NULL;
					}
					fo=true;
				}else{
					while(auxMarca->sig !=NULL){
						if((auxMarca->sig)->nombre == marca){
							Nodo *auxMa;
							auxMa=auxMarca;
							auxMarca=auxMarca->sig;
							auxMa->sig = auxMarca->sig;
							cout << endl << "Se elimino la marca "+ auxMarca->nombre << endl;
							auxMarca = NULL;
							fo=true;
							break;
						}
					}
				}
			if(!fo) cout << "No se encontro la marca especificada." << endl;
		}else cout << endl << "Necesita ingresar una marca primero" << endl;
	}
	
	void EliminarMod(){
		string marca;
		cout << endl <<"Inserte la marca del modelo que desea eliminar: ";
		cin >> marca;
		Nodo *auxMarca;
		auxMarca = PrimerMarca;
		bool found=false, fo;
		if(auxMarca != NULL){
			while(auxMarca != NULL){
				if(auxMarca->nombre == marca){
					fo = true;
					string mod;
					cout << endl << "Inserte el modelo que quiere eliminar: ";
					cin >> mod;
					Nodo *auxModelo;
					auxModelo = auxMarca->Primero;
					bool found=false;
					if(auxModelo == NULL){
						cout << endl << "No hay modelos agregados aun" << endl;
						break;
					}else{
						if(auxModelo->nombre == mod){
							cout << endl << endl << "Se elimino el modelo "+auxModelo->nombre << endl;
							auxMarca->Primero = auxModelo->sig;
							auxModelo=NULL;
							found =true;
						}
						if(found)break;
						while((auxModelo->sig) != NULL){
							if((auxModelo->sig)->nombre == mod){
								Nodo *auxModAnt;
								auxModAnt=auxModelo;
								auxModelo=auxModelo->sig;
								auxModAnt->sig=auxModelo->sig;
								cout << endl << endl << "Se elimino el modelo "+auxModelo->nombre << endl;
								auxModelo = NULL;
								found = true;
								break;
							}
							auxModelo = auxModelo->sig;
						}
					}
					if(found)break;
					else cout << endl << "No se encontro el modelo que buscaba" << endl;
				}
				auxMarca = auxMarca->sig;
			}
			if(!fo) cout << "No se encontro la marca especificada." << endl;
		}else cout << endl << "No se ha ingresado ninguna marca aun" << endl;
	}
};

int main(){
	int opc;
	Autos lista;
	do{
		cout << endl << endl;
		cout << "1. Insertar marca\n2. Insertar modelo de una marca\n3. Eliminar modelo de una marca\n4. Eliminar marca\n5. Presentar\n6. Salir" << endl << endl;
		cout << "Ingrese una opcion: ";
		cin >> opc;
		switch(opc){
			case 1: lista.InsertarMarca();
			break;
			case 2: lista.InsertarModelo();
			break;
			case 3: lista.EliminarMod();
			break;
			case 4: lista.EliminarMar();
			break;
			case 5: lista.Presentar();
			break;
		}
	}while(opc != 6);
}
