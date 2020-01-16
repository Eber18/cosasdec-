//char palabra[]={´h´,´o´,´l´,´a´,´\o´}; \o es un caracter nulo que termina la cadena para que no lea basura
//para direcciones se utiliza & y es para localizar una variable ejemplo dir=&var;
//var=*dir es lo contrario extraer la referencia de lo que hay en un apuntador
//int *num;
#include <iostream>
using namespace std;
int main(){
    int val1,val2;
    int *p;
    p=&val1;
    *p=10;
    p=&val2;
    *p=20;
    cout<<val1<<endl;
    cout<<val2<<endl;
    system("PAUSE");
    return 0;
}
//int a[20]
//int *q;
//q=a; se posiciona en el primer elemento del arreglo
//*q=5; escribe 5 en el primer elemento
//*q++; se posiciona en el siguiente entero que se encuentra en el arreglo
//*q=7; escribe el segundo
//q=&a[3]; apunta a el cuarto
//*q=10;
//q=arr+3; apunta a el cuarto elemento
//*q=12;
//q=a; 
//*(q+4)=20; estaria escribiendo en el quinto elemento el numero 20
//int **r; es un apuntador de apuntadores y el uso mas util es para arreglos de dos dimensiones
//int *s=nullptr; o *s=NULL; es un apuntador que no apunta a ningun lado

//int suma(int a,int b){return (a+b)} int resta(int a,int b){return(a-b)} int opera(int x,int y),int(*tipo)(int,int){int g; g=(*tipo)(x,y); return g;}
//en el main int(*menos)(int,int)=resta;
