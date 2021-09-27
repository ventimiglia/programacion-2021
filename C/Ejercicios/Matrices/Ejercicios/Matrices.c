#include "Matrices.h"

int sumaEncimaDiagPpal(int mat[][TAM], int ord)
{
    int i, j;
    int suma = 0;
    for(i = 0; i < ord; i++)
    {
        for(j=i+1; j < ord; j++)
        {
            suma+=mat[i][j];
        }
        j++;
    }
    return suma;
}

int sumaEncimaDiagSdria(int mat[][TAM], int ord)
{
    int i, j = 0;
    int suma = 0;
    for(i = 0; i < ord; i++)
    {
        for(j; j < ord - 1; j++)
        {
            suma+=mat[i][j];
        }
    }
    return suma;
}
