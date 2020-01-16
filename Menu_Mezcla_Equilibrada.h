//Menu_Mezcla_Equilibrada.h:
void Menu_Mezcla_Equilibrada(){
 MezclaEquilibrada A;
 char *z[1];
 char *principal[5]={"MENU METODO DE MEZCLA EQUILIBRADA:",
           "INGRESAR DATOS.",
           "ORDENAR LOS DATOS.",
           "MOSTRAR LOS DATOS.",
           "ATRAS"};
 char *a[5]={"MENU METODO DE MEZCLA EQUILIBRADA (INGRESAR):", 
       "INGRESAR UN NUMERO.",
       "INGRESAR VARIOS NUMEROS.",
       "INGRESAR 5 NUMEROS ALEATORIOS.",
       "ATRAS."};

 int op1=1, op2, op3, N, dato;
 //A.limpiar(); 
 srand(0);
 do{
  op1=construirMenu(principal, 5, op1 + 1);
  switch(op1){
   case 1: 
    op2=1;
    do{
     op2=construirMenu(a, 5, op2 + 1);
     if(op2==1 || op2==2){ //UNO O VARIOS DATOS.
      N=1;
      while(op2==2 && (N<=1 || N>=1000)){
       z[0]="Digite cuantos datos desea ingresar:";
       construirMenu(z,1);
       cin>>N;
      }
      for(int i=0; i<N ; i++){
       do{
        z[0]="Digite un dato para colocarlo:";
        construirMenu(z,1);
        cin>>dato;
       }while(dato<-10000 || dato>10000);
       A.insertar(dato, "datos5.txt");
       z[0]="Se ha colocado el dato.";
       construirMenu(z,1);
       system("pause>>NULL");
      }
     }else if(op2==3){ //DATOS ALEATORIOS.
       int RND; 
       z[0]="Se han colocado los datos aleatorios.";
       construirMenu(z,1);
       for(int i=0; i<5 ; i++){
        do{
         RND=rand() % 1000 - 250;
        }while(RND<-1000 || RND>1000);
        cout<<RND<<" ";
        A.insertar(RND,"datos5.txt");
       }
       system("pause>>NULL");
      }
    }while(op2!=4);
    break;
   case 2:
    if(A.hayDatos("datos4.txt")){//Si hay datos.
     z[0]="Se ha ordenado el ficheros.";
     A.ordenar();
    }else
     z[0]="No hay datos en el fichero.";
    construirMenu(z,1);
     system("pause>>NULL");
    break;
   case 3:
    if(A.hayDatos("datos4.txt")){//Si hay datos.
     z[0]="Los datos son: ";
     construirMenu(z,1);
     A.mostrar("datos4.txt");
    }else{
     z[0]="No hay datos en el fichero.";
     construirMenu(z,1);
    }
     system("pause>>NULL");
    break;
  }
 }while(op1!=4);
}
