//Clase_Mezcla_Equilibrada.h:
#include<fstream> //Libreria para los ficheros

class MezclaEquilibrada{
private:
 char nombre[20];
 //-- Metodos de los ficheros --//
 void abrir(fstream *f, char nom[], int tip=1);
 void cerrar(fstream *f);
 //-- Metodos auxiliares de ordenar --//
 void particionInicial();
 void particionFusion();
 void intercalacionDeArchivo(char nom1[], char nom2[], char nom3[], char nom4[]);
public:
 MezclaEquilibrada(){ strcpy(nombre,"datos4.txt");}
 //-- Metodos de los ficheros --//
 void limpiar();
 bool hayDatos(char nom[]);
 void mostrar(char nom[]);
 void insertar(int d, char nom[]);
 //-- Metodo propio de la Mezcla Equilibrada --//
 void ordenar();
};
//-- Metodos para los ficheros --//
void MezclaEquilibrada::abrir(fstream *f, char nom[], int tip){
 if(tip==1) //LECTURA
  (*f).open(nom, ios::in );//->
  //MODO TEXTO (Acceder a los datos) usar� ">>"
 else if(tip==2) //ESCRITURA SIN BORRAR
  (*f).open(nom, ios::out | ios::app); //->
  //MODO TEXTO (Colocar datos y no borrar�) usar� "<<"
 else      //ESCRITURA y BORRAR
  (*f).open(nom, ios::out); //->
  //MODO TEXTO (Colocar datos) usar� "<<"
}
void MezclaEquilibrada::cerrar(fstream *f){
 (*f).close();
}
void MezclaEquilibrada::limpiar(){
  fstream F, F1, F2;
 abrir(&F, nombre, 3);
 abrir(&F1, "F1.txt"  , 3);
 abrir(&F2, "F2.txt"  , 3);
 cerrar(&F);
 cerrar(&F1);
 cerrar(&F2);
}
bool MezclaEquilibrada::hayDatos(char nom[]){
 fstream F;
 abrir(&F, nom,1);
 int x=-10001;
 F>>x;
 if(x!=-10001)
  return true;
 else
  return false;
 cerrar(&F);
}

void MezclaEquilibrada::mostrar(char nom[]){
 fstream F;
 abrir(&F, nom,1);
 int dato;
 F>>dato;
 while(!F.eof()){
  cout<<dato<<" ";
   F>>dato;
 }
 cerrar(&F);
}
void MezclaEquilibrada::insertar(int d, char nom[]){
 fstream F;
 abrir(&F, nom, 2);
 F<<d<<" ";
 cerrar(&F);
}

//-- Metodos propias de la Mezcla Equilibrada --//
void MezclaEquilibrada::ordenar(){

 particionInicial();
 particionFusion();
}
void MezclaEquilibrada::particionInicial(){

 int aux, dato; bool ban=true;
 fstream F, F2, F3;
 abrir(&F ,   nombre, 1);
 abrir(&F2, "F2.txt", 3);
 abrir(&F3, "F3.txt", 3);
 
 F>>aux;
 while(!F.eof() && !F.fail()){
  F>>dato;
  if(ban){
   F2<<aux<<" ";
   if(aux > dato)
    ban=false;
  }else{
   F3<<aux<<" ";
   if(aux > dato)
    ban=true;
  }
  aux=dato;
 }
 cerrar(&F);
 cerrar(&F2);
 cerrar(&F3);
}
void MezclaEquilibrada::particionFusion(){
 fstream F1;
 abrir(&F1, "F1.txt", 1);
 int con=0;
 bool bandera=true;
 do{
  //con++;
  if(bandera){
   bandera=false;
   intercalacionDeArchivo("F2.txt","F3.txt",  nombre,"F1.txt");
  }else{
   bandera=true;
   intercalacionDeArchivo(nombre  ,"F1.txt","F2.txt","F3.txt");
  }
  F1>>con;
 }while(!F1.eof());
 cerrar(&F1);
 // Ya esta ordenado
}
void MezclaEquilibrada::intercalacionDeArchivo(char nom1[], char nom2[], char nom3[], char nom4[]){
 int    aux1,     aux2, dato ; 
  int    mayor1,   mayor2;
 bool bandera1, bandera2=true;
 fstream F1, F2, F3, F4;
 abrir(&F1, nom1, 1);
 abrir(&F2, nom2, 1);
 abrir(&F3, nom3, 3);
 abrir(&F4, nom4, 3);
 //-- Conseguir los primeros numeros --//
 F1>>aux1;
 F2>>aux2;
 //-- Asignar los mayores --// 
 //(Debe estar ya validados los ficheros que contengan al menos un dato.
 mayor1=aux1;
 mayor2=aux2;
 //-- Escribir en orden cuando los dos tengan datos.
 //-- Pero simultaneado los archivos.
 while(!F1.eof() && !F2.eof()){

  //-- Cambio de fichero para la Escritura --//
  if(aux2 < mayor2 && aux1 < mayor1){
   if(bandera2)
    bandera2=false;
   else
    bandera2=true;
   mayor1=aux1;
   mayor2=aux2;
  }
  //----------------------------------------//
  //-- Cambio de fichero para Lectura ------//
  if((aux1 <= aux2 && aux1 >= mayor1) || aux2 < mayor2){
   bandera1=true;
   mayor1=dato=aux1;
  }else{
   bandera1=false;
   mayor2=dato=aux2;
  }
  //---------------------------------------//
  //-- Leer el dato en el fichero tal --//
  if(bandera1)
   F1>>aux1;
  else
   F2>>aux2;
  //-------------------------------------//
  //-- Escribir el dato en el fichero tal --//
  if(bandera2)
   F3<<dato<<" ";
  else
   F4<<dato<<" ";
  //----------------------------------------//
 }
 //-- Escribir lo sobrante.
 if(!F1.eof()){
  while(!F1.eof()){
   //-- Cambio de fichero para la Escritura --//
   if(aux1 < mayor1){
    if(bandera2)
     bandera2=false;
    else
     bandera2=true;
   }
   mayor1=aux1;
   //---------------------------------------//
   //-- Escribir el dato en el fichero tal --//
   if(bandera2)
    F3<<aux1<<" ";
   else
    F4<<aux1<<" ";
   F1>>aux1;
   //---------------------------------------//
  }
 }else if(!F2.eof()){
   while(!F2.eof()){
   //-- Cambio de fichero para la Escritura --//
   if(aux2 < mayor2){
    if(bandera2)
     bandera2=false;
    else
     bandera2=true;
   }
   mayor2=aux2;
   //---------------------------------------//
   //-- Escribir el dato en el fichero tal --//
   if(bandera2)
    F3<<aux2<<" ";
   else
    F4<<aux2<<" ";
   F2>>aux2;
   //---------------------------------------//
   }
 }
 cerrar(&F1);
 cerrar(&F2);
 cerrar(&F3);
 cerrar(&F4);
}
