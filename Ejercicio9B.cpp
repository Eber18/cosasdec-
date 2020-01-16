#include <iostream>

using namespace std;

int MCD(int a,int b){
	int res;
	if(a>=0&&b>=0){
		if(a==b){
			res=a;
		}
		else{
			if(a>b){
				res=MCD(a-b,b);
			}
			else{
				res=MCD(a,b-a);
			}
		}
	}
	else{
		cout<<endl<<"Numero no natutal";
	}
	return res;
}

int main(){
	int a,b,res;
	cout<<endl<<"Maximo comun divisor de dos numeros naturales"<<endl;
	cout<<endl<<"Introduce el primer numero ";
	cin>>a;
	cout<<endl<<"Introduce el segundo numero ";
	cin>>b;
	res=MCD(a,b);
	cout<<endl<<"El resultado es "<<MCD(a,b)<<endl;
	system("PAUSE()");
}
