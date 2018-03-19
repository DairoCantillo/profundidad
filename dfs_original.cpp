 /***********************************************************
* You can use all the programs on  www.c-program-example.com
* for personal and learning purposes. For permissions to use the
* programs for commercial purposes,
* contact info@c-program-example.com
* To find more C programs, do visit www.c-program-example.com
* and browse!
* 
*                      Happy Coding
***********************************************************/

#include<stdio.h>
//#include<conio.h>
#include<string.h>

#define N 14


char * states[N] = {"A", "B", "C", "D", "E",
                    "F", "G", "H", "I", "J"};

int a[N][N], visitado[100];


void fillAdjacencyMatrix();   //construye una matriz de adyacencia con las transiciones entre estados que son validas.
void initilizeVisitados();
int indexState(char * s);
char * stateName(int idx);
int DFS(int v, int obj);


/////////////////////////////////////////////////////////////////////
void initilizeVisitados()   //Lista de estados validos del problema
{
    
    for(int i=0; i<N; i++)
      visitado[i] = 0;
    
}


void fillAdjacencyMatrix()   //la matriz de adyacencia es a
{

//La matriz construida es una matriz binaria en la que el valor 1 indica que es posible pasar del estado actual representado por la fila a
//un futuro estado representado por la columna a travez de una de las acciones definidas para el problema. 

     for(int i =0; i<N; i++)
       for(int j =0; j<N; j++)
          a[i][j] = 0;

    a[0][5] = 1;
    a[1][6] = 1; a[1][7] = 1;
    a[2][6] = 1; a[2][8] = 1;
    a[3][5] = 1; a[3][7] = 1; a[3][8] = 1;
    a[4][6] = 1; a[4][9] = 1;
    a[5][0] = 1; a[5][3] = 1;
    a[6][1] = 1; a[6][2] = 1; a[6][4] = 1;
    a[7][1] = 1; a[7][3] = 1;
    a[8][2] = 1; a[8][3] = 1;
    a[9][4] = 1;

}


int indexState(char * s)
{
    for(int i=0; i<N; i++)
		if(strcmp(s, states[i]) == 0)
			return i;

	printf("State: %s was not founded\n", s);
    return -1;
}

char * stateName(int idx)
{
   return states[idx];

}



int DFS(int v, int obj)
{
 
 visitado[v] = 1;
 
 for(int i=0; i<N; i++)
  if(a[v][i] && !visitado[i])
  {
    printf("nodo: %s\n", stateName(i));
    if(i == obj) return 1;
    if(DFS(i, obj)) return 1;
  }

  return 0;
}



int main()
{

   char * iniState = "A";
   char * objState = "H";
   
   initilizeVisitados();  
   fillAdjacencyMatrix();
  
   int id_iniEstate   =  indexState(iniState);
   int id_finalEstate =  indexState(objState);

   if(DFS(id_iniEstate, id_finalEstate))
	   printf("\nEncotro la solucion\n");
   else
	   printf("\nNo encontro solucion\n");
      
  return 0;

}
