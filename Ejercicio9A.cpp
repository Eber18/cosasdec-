#include <iostream>

using namespace std;

int potencia(int valor,int p){
	int res;
	if(p==0){
		res=1;
	}
	else{
		res=valor*potencia(valor,p-1);
	}
	return res;
}

int main(){
	int valor, p, res;
	cout<<endl<<"Elevar un numero en forma recursiva"<<endl;
	cout<<endl<<"Introduce el numero ";
	cin>>valor;
	cout<<endl<<"Introduce potencia ";
	cin>>p;
	res=potencia(valor,p);
	cout<<endl<<"El resultado es "<<res<<endl;
	system("PAUSE()");
}
