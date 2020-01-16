#include <iostream>

using namespace std;

int Mayor(int a[],int ini,int fin){
	int mayor,dev;
	if(ini==1){
		dev=a[ini-1];
	}
	else{
         mayor=Mayor(a,ini-1,fin);
         if(a[ini]>mayor){
                          dev=a[ini];
         }
         else{
              dev=mayor;     
         }
    }
	return dev;
}

int main(){
	int tam,n;
	cout<<endl<<"El mayor de los numeros en un arreglo"<<endl;
	cout<<endl<<"Introduce la dimension del arreglo ";
	cin>>tam;
	int a[tam];
	for(int i=0;i<tam;i++){
		cout<<"introduce el numero "<<(i+1)<<":";
		cin>>n;
		a[i]=n;
		cout<<endl;
	}
	cout<<endl<<"El resultado es "<<Mayor(a,tam,tam)<<endl;
	system("PAUSE()");
}
