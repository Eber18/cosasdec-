//Mezcla Natural en C++

#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <conio.h>
#include <string>
#include <time.h>

using namespace std;

int n,alto,bajo,bajo2;
void haceCadena()
{
    int i;
    int a[] = {73,63,95,256,141,82,47,124,621,52,364,169,86,75,116,205,65,159,334,93,812,9,361,728,37,892,45,350,224,156,69,773,801,900,199,28};    A[]={73,63,95,256,141,82,47,124,621,52,364,169,86,75,116,205,65,159,334,93,812,9,361,728,37,892,45,350,224,156,69,773,801,900,199,28};
    for(i=0;i<37;i++){
            cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"HURRA HA TERMINADO DE CREAR LOS DATOS :D!!\n";
    cin.get();
}
void merge(int a[],int bajo,int bajo2, int alto)
{
    int i=bajo;
    int finbajo=bajo2-1;
    int j=bajo2;
    int k=bajo;
    int temp[37];
    temp[n]=a[n];
    for(int j=0;j<n-1;j++)
    {
        for(int k=j+1;k<n;k++)
        {   
            if(a[j]>a[k])
            {
                int aux;
                aux=a[k];
                a[k]=a[j];
                a[j]=aux;
            }
        }
    }
    while((i<=finbajo)&&(j<=alto))
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
    while(i<=finbajo)
        temp[k++]=a[i++];
    while(j<=alto)
        temp[k++]=a[j++];
    for(i=bajo;i<=alto;i++)
    {
        a[i]=temp[i];
    }
}
void mergesort(int A[],int bajo, int alto)
{
    if(bajo<alto)
    {
        int medio=(alto+bajo)/2;
        mergesort(A,bajo,medio);
        mergesort(A,medio+1,alto);
        merge(A,bajo,medio+1,alto);
    }
}
void despliega()
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
int main()
{
    cout<<"cuantos numeros desea en el vector: ";
    cin>>n;
    haceCadena();
    cout<<"\n\n\n";
    mergesort(A,bajo,alto);
    merge(A,bajo,bajo2,alto);
    system("pause");
    cout<<"\n\n\n";
    despliega();
    system("pause");
    return 0;
}
