#include "funciones.h"


void mayor_matriz_cuadrada(int mat[][COL], int fil, int col)
{
    int i, j, opciones;
    int fila, columna;
    printf("Ingrese la fila y columna vertice: ");
    scanf("%d %d",&fila,&columna);
    fila--;
    columna--;
    opciones=validar_cuadrante(fila,columna,fil,col);
    switch(opciones)
    {
    case 1: ///primer cuadrante
      for(i=fila;i<=fila+(MENOR(fil-fila-1,col-columna-1));i++)
      {
        for(j=columna;j<=columna+(MENOR(fil-fila-1,col-columna-1));j++)
        {
          printf("[%d]",mat[i][j]);
        }
        printf("\n");
      }
    break;
    case 2:
      for(i=fila-(MENOR(fil-fila-1,col-columna-1));i<=fila;i++)
      {
        for(j=columna-(MENOR(fil-fila-1,col-columna-1));j<=columna;j++)
        {
          printf("[%d]",mat[i][j]);
        }
        printf("\n");
      }
    break;
    case 3:
      for(i=fila-(MENOR(fil-fila-1,col-columna-1));i<=fila+(MENOR(fil-fila-1,col-columna-1));i++)
      {
        for(j=columna-(MENOR(fil-fila-1,col-columna-1));j<=columna+(MENOR(fil-fila-1,col-columna-1));j++)
        {
          printf("[%d]",mat[i][j]);
        }
        printf("\n");
      }
    break;

    }

}

int validar_cuadrante(int i, int j, int fil,int col)
{
  if(i<((fil/2)+fil%2))
  {
    if(j<((col/2)+col%2))
    {
      return PRIMER_CUADRANTE;
    }
    else
      return SEGUNDO_CUADRANTE;
  }
  if(j<((col/2)+col%2))
    return TERCER_CUADRANTE;
  else
    return CUARTO_CUADRANTE;
}
