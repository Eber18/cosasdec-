//#include<fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


//void Lee() { 
// int I=0; 
// cout<< "Leyendo los datos del archivo, "; 
//    ifstream fe("datos.txt"); 
//    while(!fe.eof()) { 
//         fe >> A[I]; 
//        I++; 
//    } 
//    nElementos=I; 
//    fe.close(); 
//    cout<<nElementos<<" datos leidos."<<endl; 
//} 
int divide(int *array, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;
 
    pivot = array[start];
    left = start;
    right = end;
 
    // Mientras no se cruzen los índices
    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }
 
        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }
 
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }
 
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;
 
    // La nueva posición del pivot
    return right;
}


void quicksort(int *array, int start, int end)
{
    int pivot;
 
    if (start < end) {
        pivot = divide(array, start, end);
 
        // Ordeno la lista de los menores
        quicksort(array, start, pivot - 1);
 
        // Ordeno la lista de los mayores
        quicksort(array, pivot + 1, end);
    }
}

int main(){
   int A[]={73,63,95,256,141,82,47,124,621,52,364,169,86,75,116,205,65,159,334,93,812,9,361,728,37,892,45,350,224,156,69,773,801,900,199,28};
   cout << "Array antes de ordenarse: " << endl;
    for (int i = 0; i < 36; i++) {
        cout << A[i] << " ";
    }
 
    cout << endl << endl;
 
    quicksort(A, 0, 36 - 1);
   
   cout << "Array ordenado " << endl;
    for (int i = 0; i < 36; i++ ){
        cout << A[i] << " ";
    }
 
    cout << endl << endl;
    system("PAUSE");
 
    return 0;
}
