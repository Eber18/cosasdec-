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

//Método que indica el inicio del programa
void Circulo::iniciar(void){
     cout <<endl<<endl<<"Programa que ejemplifica la clase Circulo."<<endl<<endl;
}

//Método que permite la entrada de los datos
void Circulo::entradaDatos(void){
     cout<<"Introduzca el radio: ";
     cin>>radio;
}

//Método que calcula el área de la figura círculo
void Circulo::calcularArea(void){
     area = pi * radio * radio;
}

//Método que calcula el perímetro  de la figura círculo
void Circulo::calcularPerim(void){
     perimetro = 2 * pi * radio;
}

//Método que realiza la salida de los datos
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
