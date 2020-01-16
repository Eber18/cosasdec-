class Circulo{// friend Cilindro{
      public:
             Circulo(double radio){
                            radio=0;
             }
             double perimetro(double radio){
                    double p=2*3.1416*radio;
                    return p;
             }
             double area(double radio){
                    double a=3.1416*radio*radio;
                    return a;
             }
}

class Cilindro{// friend Circulo{
      public:
             Cilindro(double radio, double altura){
                             radio=0;
                             altura=0;
             }
             double volumen(double radio,double altura){
                    double v=area(radio)*altura;
                    return v;
             }
}

int main(){
    cout<<"Dame el radio de un circulo"<<endl;
    cin>>r;
    Circulo ci=new Circulo(r);
    cout<<"Se ha creado un nuevo circulo"<<ci<<endl;
}
