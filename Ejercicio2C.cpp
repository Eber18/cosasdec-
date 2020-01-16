#include <iostream>
using namespace std;

class Circulo {
      public: 
              Circulo ();
              void iniciar(void);
              void entradaDatos(void);
              void calcularArea(void);
              void calcularPerim(void);
              void salidaDatos(void);
              ~ Circulo();
      private:
      double radio, area, perimetro, pi;
};

//Constructor de la clase Circulo
Circulo::Circulo(){
                   pi=3.1416;
}

//M�todo que indica el inicio del programa
void Circulo::iniciar(void){
     cout <<endl<<endl<<"Programa que ejemplifica la clase Circulo."<<endl<<endl;
}

//M�todo que permite la entrada de los datos
void Circulo::entradaDatos(void){
     cout<<"Introduzca el radio: ";
     cin>>radio;
}

//M�todo que calcula el �rea de la figura c�rculo
void Circulo::calcularArea(void){
     area = pi * radio * radio;
}

//M�todo que calcula el per�metro  de la figura c�rculo
void Circulo::calcularPerim(void){
     perimetro = 2 * pi * radio;
}

//M�todo que realiza la salida de los datos
void Circulo::salidaDatos(void){
     cout<< "Area: " <<area<<endl;
     cout<< "Perimetro: " <<perimetro<<endl;
}

//Destructor de la clase Circulo
Circulo::~Circulo(){
}

int main(void){    
    Circulo obj;
    obj.iniciar();
    obj.entradaDatos();
    obj.calcularArea();
    obj.calcularPerim();
    obj.salidaDatos();
    system("PAUSE");
}
