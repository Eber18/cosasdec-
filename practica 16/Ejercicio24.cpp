#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
    int n,d;
    cout<<"Dame el tamaño de la matriz"<<endl;
    cin>>n;
    int matriz [n][n];
    for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cout<<"ingrese la distancia de "<<i<<" "<<j<<endl;
                cin>>d;
            }
    }
}
