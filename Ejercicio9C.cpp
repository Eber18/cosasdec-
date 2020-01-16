#include <iostream>

using namespace std;

int sumar(int a[],int n){
	int res;
	if(n==0){
		res=a[0];
	}
	else{
		res=a[n]+sumar(a,n-1);
	}
	return res;
}

int main(){
    int tam,n,res;
	cout<<endl<<"Suma de los numeros en un arreglo"<<endl;
	cout<<endl<<"Introduce la dimension del arreglo ";
	cin>>tam;
	int a[tam];
	for(int i=0;i<tam;i++){
		cout<<"introduce el numero "<<(i+1)<<":";
		cin>>n;
		a[i]=n;
		cout<<endl;
	}
	res=sumar(a,n);
	cout<<endl<<"El resultado es "<<res<<endl;
	system("PAUSE()");
}
