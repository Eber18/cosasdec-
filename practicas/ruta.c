/* Encontrar la ruta más corta entre n ciudades */
/* (C) Agosto de 2.000 Salvador Pozo Coronado
	salvapozo@inicia.es
   http://inicia.es/de/salvadorpozo */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nCiudades;  	/* Número de ciudades */
int **Distancia;	/* Matriz de distancias entre parejas de ciudades */
char *Ruta;			/* Cadena de caracteres que almacena una ruta de la forma:
							ABCEDFG...Z */
long int	MinimaActual;	/* Distancia mínima encontrada durante los cálculos */
char *RutaMinima;	      /* Ruta para la distancia mínima */

/* MideDistanciaEntre(A, B);
	calcula la distacia entre las ciudades
	A y B y la devuelve */
int MideDistanciaEntre(int A, int B)
{
	if(A == B) return 0;
	else if(A < B) return Distancia[A][B];
   else return Distancia[B][A];
}

/* DistanciaRuta(n):
	Calcula la distancia total de la ruta actual hasta la ciudad n */
long int DistanciaRuta(int l)
{
	long int d;
   int i;

	for(i = 0, d = 0; i < l; i++)
   	d += MideDistanciaEntre(Ruta[i]-'A', Ruta[i+1]-'A');
   return d;
}

/* VerificarOptima():
	Compueba si la ruta actual es mejor que la que hasta ahora se
   considera la mejor. En este caso la nueva ruta pasa a ser la mejor. */
void VerificarOptima()
{
	long int d;

	d = DistanciaRuta(nCiudades-1);
   if(d < MinimaActual || MinimaActual < 0)
   {
	   printf("Por ahora la ruta óptima es:\n %s con %ld Km\n", Ruta, d);
   	strcpy(RutaMinima, Ruta);
      MinimaActual = d;
   }
}

/* Permutaciones(d, n):
   calcula todas las permutaciones posibles de n elementos
   teniendo en cuenta que el primero y el último son siempre
   los mismos, para que el primero no cambie llamaremos con
   Permutaciones(1), para que no cambie el último, el limite
   estará en nCiudades-1
   El otro parámetro se usa para evitar cálculos innecesarios.
   Si la distacia de la ruta que estamos calculando hasta el
   punto l ya es mayor que la distancia de una ruta anterior,
   no seguiremos calculando permutaciones con este principio
   de ruta.

	ALGORITMO RECURSIVO PARA CALCULAR PERMUTACIONES
   Siendo "n" el número de elementos, "l" el primer elemento a
   permutar, int lista[0..n-1], los elementos a permutar:
   void Permutaciones(int l)
   {
   	int i, j;

	   for(i = 0; i < n-l; i++)
	   {
   	   if(n-l > 2) Permutaciones(l+1);
			else combinación_de_salida(lista);
   		j = lista[l];
	      lista[l] = lista[l+i+1];
      	lista[l+i+1] = j;
      	if(l+i == n-2)
      		for(j = l; j < n; j++) lista[j] = lista[j+1];
	   }
   }
   */
void Permutaciones(long int d, int l)
{
	int i, j;
   char a;

   for(i = 0; i < nCiudades-l-1; i++)
   {
      if(nCiudades-l-1 > 2)
      {
      	if(d < MinimaActual || MinimaActual < 0)
         	Permutaciones(DistanciaRuta(l), l+1);
      }
		else
      {
         VerificarOptima();
      }
   	a = Ruta[l];
      Ruta[l] = Ruta[l+i+1];
      Ruta[l+i+1] = a;
      if(l+i == nCiudades-2)
      {
      	for(j = l; j < nCiudades-1; j++) Ruta[j] = Ruta[j+1];
         Ruta[nCiudades-1] = 'A'+nCiudades-1;
         Ruta[nCiudades] = 0;
      }
   }
}

void main()
{
	int i, j;
   int error;

	printf("Algoritmo del agente viajero\n\n");
	printf("Numero de ciudades a visitar: ");
   scanf("%d", &nCiudades);

   printf("%d\n", nCiudades);
   /* Necesitamos al menos dos ciudades */
   if(nCiudades < 2)
   {
   	printf("ERROR: Al menos hay que introducir la ciudad de origen y destino\n");
      return;
   }
   if(nCiudades > 26)
   {
   	printf("ERROR: Demasiadas ciudades, el máximo son 26\n");
      return;
   }
   /* Reservar memoria para la matriz Distancia[nCiudades][nCiudades] */
   /* La tabla de distancias será de este modo:
      | A | B | C | ...
    A | 0 | d1| d2| ...
    B | d1| 0 | d3| ...
    C | d2| d3| 0 | ...
    . | . | . | . | ...
    Podemos ignorar las distancias entre A y A, B y B, etc. También podemos
    ignorar la mitad de las distancias ya que entre A y B hay la misma que
    entre B y A
    De modo que no necesitamos almacenar una tabla de nCiudades*nCiudades, sino
    de (nCiudades*nCiudades-1)/2
    Guardaremos una tabla de este tipo:
      | B | C | D |...
    A | d1| d2| d3| ...
    B      |d4| d5| ...
    C         | d6| ...
    .             | ...
    */

   Distancia = (int **)malloc((nCiudades-1)*sizeof(int *));
   if(Distancia == NULL)
   {
   	printf("ERROR: No hay memoria suficiente\n");
      return;
   }
   i = 0;
   error = 0;
   while(i < nCiudades-1 && !error)
   {
   	Distancia[i] = (int *)malloc((nCiudades-1-i)*sizeof(int));
		error = (Distancia[i] == NULL);
      i++;
   }
   if(error)
   {
   	printf("ERROR: No hay memoria suficiente\n");
      for(j = 0; j < i-1; j++) free(Distancia[j]); /* Eliminar elementos creados */
      free(Distancia);
      return;
   }

   Ruta = (char *)malloc(1+nCiudades*sizeof(char));
   if(Ruta == NULL)
	{
   	printf("ERROR: No hay memoria suficiente\n");
      for(j = 0; j < nCiudades-1; j++) free(Distancia[j]); /* Eliminar elementos creados */
      free(Distancia);
      return;
   }
   RutaMinima = (char *)malloc(1+nCiudades*sizeof(char));
   if(Ruta == NULL)
	{
   	printf("ERROR: No hay memoria suficiente\n");
      for(j = 0; j < nCiudades-1; j++) free(Distancia[j]); /* Eliminar elementos creados */
      free(Distancia);
      free(Ruta);
      return;
   }

   /* Excluimos la lectura entre cada ciudad y si misma */
	for(i = 0; i < nCiudades-1; i++) /* Distancias entre las nCiudades-1 y... */
   	for(j = i+1; j < nCiudades; j++) /* todas las demás*/
      {
      	printf("Distancia entre %c y %c: ", 'A'+i, 'A'+j);
         scanf("%d", &Distancia[i][j]);
      }


	/* Mostrar la tabla de distancias */
   /*for(i = 0; i < nCiudades; i++)
   {
   	for(j = 0; j < nCiudades; j++)
   		printf("%6d", MideDistanciaEntre(i, j));
      printf("\n");
   } */

   /********************************************************************/

   MinimaActual = -1; /* La distancia de la ruta más corta hasta ahora
   							 -1 significa que aún no tenemos una ruta corta */
   for(i = 0; i < nCiudades; i++) Ruta[i] = 'A'+i; /* Primera ruta propuesta */
   Ruta[nCiudades] = 0;		        /* Terminador de cadena */
   Permutaciones(MinimaActual, 1); /* Busca la mejor de todas las posibles */

	/* Resultado de la búsqueda */
	
	MinimaActual=MinimaActual+50;
	printf("Mejor Ruta encontrada: %sA, %ld Km\n", RutaMinima, MinimaActual);

	/* Liberar memoria */
   for(j = 0; j < nCiudades-1; j++) free(Distancia[j]);
   free(Distancia);
   free(Ruta);
   free(RutaMinima);
   system("PAUSE");
}
