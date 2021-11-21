#include "ejercicio4.h"
void mostrar_matriz(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
            printf("%d\t",m[i][j]);
        printf("\n");
    }
}

void transponer_matriz_sobreSimisma(int m[][COL],int f,int c)
{
    int i,j,aux;
    for(i=0;i<f;i++)
    {
        for(j=0;j<c/2;j++)
        {
            aux=m[i][j];
            m[i][j]=m[i][c-1-j];
            m[i][c-1-j]=aux;
        }
    }
}
