#include <stdio.h>
#include <stdlib.h>

#include "Ejercicios/Matrices.h"
#include "../../Bibliotecas/Matrices/Matrices.h"

int main()
{
    int matriz29[][TAM] = {
        {2,0,4,2},
        {1,4,3,1},
        {1,5,6,4},
        {1,5,6,8},
    };

//    printf("%d", sumaEncimaDiagPpal(matriz, 4));
    printf("%d", sumaEncimaDiagSdria(matriz29, 4));

    return 0;
}
