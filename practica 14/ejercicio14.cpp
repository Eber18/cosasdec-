#include<iostream> 
#include <string>
#include <stdio.h>     
#include <stdlib.h> 
#include "pila.h" 

using namespace std; 

static Pila <double> A;

int main(){
	int n,cont;
	double db,x,y,res,z;
	string ope,num;
	char asd [3];
	char* pEnd;
    cout<<"Operacion Posfija."<<endl<<endl;
    cout<<"Ingrese la operacion (ingrese una espacio para indicar el final): "<<endl;
    getline(cin,ope);
    for(n=0;n<ope.size();n++){
    	if(ope[n]!='+' && ope[n]!='-' && ope[n]!='*' && ope[n]!='/' && ope[n]!=' ' && ope[n]!=0){
    		num="";
    		cont=0;
    		while(ope[n]!=' '){
    			num+=ope[n];
    			asd[cont]=ope[n];
    			cont++;
    			n++;
			}
			if(num!=""){
				db = strtod (asd, &pEnd);
				A.Push(db);
				asd[0]=' ';
				asd[1]=' ';
				asd[2]=' ';
			}
			
			//cout<<db<<endl<<endl;
		}
		if(ope[n]=='+' || ope[n]=='-' || ope[n]=='*' || ope[n]=='/'){
            switch(ope[n]){
                case '+':
					y=A.Pop();
					x=A.Pop();
					res=x+y;
					A.Push(res);
				break;
				case '-':
					y=A.Pop();
					x=A.Pop();
					res=x-y;
					A.Push(res);
				break;
				case '*':
					y=A.Pop();
					x=A.Pop();
					res=x*y;
					A.Push(res);
				break;
				case '/':
					y=A.Pop();
					x=A.Pop();
					res=x/y;
					A.Push(res);
            }
        }
	}
	
	cout<<"El resultado es: "<<A.Pop()<<endl<<endl;
	system("pause");
}

