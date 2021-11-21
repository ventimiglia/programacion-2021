#include <stdio.h>
#include <stdlib.h>
#include "ejercicio4.h"

int main()
{
    int mat[FIL][COL]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int f=FIL;
    int c=COL;
    mostrar_matriz(mat,f,c);
    printf("\n");
    transponer_matriz_sobreSimisma(mat,f,c);
    printf("\n");
    mostrar_matriz(mat,f,c);
    return 0;
}

