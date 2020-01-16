#include<iostream>
using namespace std;

int main(void){
    const int MAX=5;
    int Fil,sum;
    int A[MAX];
    char B[MAX];
    cout<<"Ejercicio sencillo con arreglos unidimensionales"<<endl<<endl;
    cout<<"Proporciona "<<MAX+1<<" enteros: "<<endl;
    sum=0;
    for(Fil=0;Fil<=MAX;Fil++) {
                              cin>>A[Fil];
                              sum+=A[Fil];
    }
    cout<<"La suma de los valores dados es: "<<sum<<endl;
    cout<<"Proporciona "<<MAX+1<<" caracteres: "<<endl;
    for(Fil=0;Fil<=MAX;Fil++) cin>>B[Fil];
    cout<<"La concatenacion de los caracteres es: "<<B<<endl;
    system("PAUSE");
}
