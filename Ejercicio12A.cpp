#include<iostream> 
#include <iomanip>  
#include "pila.h" 
using namespace std; 

static Pila <char> A,B,C;

void Mover(char o,char d){
    
}

int main(){
    int des;
    char valor;
	char pil,pil2,car;
    cout<<"Uso de pilas."<<endl<<endl;
    do{
        cout<<"¿Que deseas hacer?\n1. Ingresar un valor a una pila.\n2. Eliminar un valor a una pila."<<
		"\n3. Hacer un traspaso de un valor de pila a otra.\n4. Ver listas.\n5. Salir.\n"<<endl<<endl;
        cin>>des;
        switch(des){
            case 1:
            	cout<<"¿Que pila seria: A, B o C"<<endl;
            	cin>>pil;
            	switch(pil){
            		case 'A':
            			cout<<"¿Que caracter seria?"<<endl;
                		cin>>pil;
            			A.Push(pil);
            		break;
            		case 'B':
            			cout<<"¿Que caracter seria?"<<endl;
                		cin>>pil;
            			B.Push(pil);
            		break;
            		case 'C':
            			cout<<"¿Que caracter seria?"<<endl;
                		cin>>pil;
            			C.Push(pil);
            		break;
            		default:
            			cout<<"Esa pila no es valida."<<endl;
            		break;
				}
				cout<<endl;
            break;
            case 2:
            	cout<<"¿De que pila seria?"<<endl;
            	cin>>pil;
            	switch(pil){
            		case 'A':
            			valor=A.Pop();
            			if(valor ==0) 
                                  cout<<endl<<"La Pila esta vacia."<<endl<<endl;
                         else 
                                  cout<<endl<<"Se elimino dato: "<<valor<<endl<<endl;
            		break;
            		case 'B':
            			valor=B.Pop();
            			if(valor ==0) 
                                  cout<<endl<<"La Pila esta vacia."<<endl<<endl;
                         else 
                                  cout<<endl<<"Se elimino dato: "<<valor<<endl<<endl;
            		break;
            		case 'C':
            			valor=C.Pop();
            			if(valor ==0) 
                                  cout<<endl<<"La Pila esta vacia."<<endl<<endl;
                         else 
                                  cout<<endl<<"Se elimino dato: "<<valor<<endl<<endl;
            		break;
            		default:
            			cout<<"Esa pila no es valida."<<endl;
            		break;
            	}
            break;
            case 3:
            	valor=0;
                cout<<"¿De que pila seria?"<<endl;
            	cin>>pil;
            	cout<<"¿A que pila seria?"<<endl;
            	cin>>pil2;
            	switch(pil){
            		case 'A':
            			valor=A.Pop();
            				if(valor == 0) 
                            	cout<<endl<<"La Pila de origen esta vacia."<<endl<<endl;
                         	else {
                        		cout<<endl<<"Se traslado el dato: "<<valor<<endl<<endl;
						 }
            		break;
            		case 'B':
            			valor=B.Pop();
            			if(valor ==0) 
                                  cout<<endl<<"La Pila de origen esta vacia."<<endl<<endl;
                         else 
                                  cout<<endl<<"Se traslado el dato: "<<valor<<endl<<endl;
            		break;
            		case 'C':
            			valor=C.Pop();
            			if(valor ==0) 
                                  cout<<endl<<"La Pila de origen esta vacia."<<endl<<endl;
                         else 
                                  cout<<endl<<"Se traslado el dato: "<<valor<<endl<<endl;
            		break;
            		default:
            			cout<<"Esa pila no es valida."<<endl;
            		break;
            	}
            	if(valor!=0){
            		switch(pil2){
            			case 'A':
                         	A.Push(valor);
                        break;
                        case 'B':
                         	B.Push(valor);
                        break;
                        case 'C':
                       		C.Push(valor);
                        break;
                        default:
                    		cout<<"Esa pila no es valida."<<endl;
                    	break;
                    }
				}
				cout<<endl;
            break;
            case 4:
                 cout<<"PILA A:"<<endl;
            	A.Ver();
            	cout<<"\nPILA B:"<<endl;
            	B.Ver();
            	cout<<"\nPILA C:"<<endl;
            	C.Ver();
            break;
        }
    }while(des!=5);
}
