#include <iostream>

using namespace std;
 
int main(void){
    int a[36]={73,63,95,256,141,82,47,124,621,52,364,169,86,75,116,205,65,159,334,93,812,9,361,728,37,892,45,350,224,156,69,773,801,900,199,28},i1=0;
    cout<<"Ordenamiento por el metodo shellsort"<<endl<<endl;
    cout<<"Numeros:\n"<<endl;
    for(int k=0;k<36;k++){
            if(k==18){
                      cout<<endl;
            }
            cout<<a[k]<<" ";
    }
    cout<<endl<<endl;
    int i, j, incremento, temp,numero_elementos=36;
    for(incremento = numero_elementos/2;incremento > 0; incremento /= 2){
                  for(i = incremento; i<numero_elementos; i++){
                        temp = a[i];
                        for(j = i; j >= incremento ;j-=incremento){
                              if(temp < a[j-incremento]){
                                      a[j] = a[j-incremento];
                              }
                              else{
                                   break;
                              }
                        }
                        a[j] = temp;
                  }
    }
    
    cout<<"Ordenados:"<<endl;
    for(i1=0;i1<36;i1++){
                         cout<<i1+1<<".- "<<a[i1]<<"\n";
    }
    system("PAUSE");
}
