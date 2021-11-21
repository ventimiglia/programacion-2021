#include <stdio.h>
#include <stdlib.h>

//#include "Ejercicios/Matrices.h"
#include "../../Bibliotecas/Matrices/Matrices.h"

int main()
{
    int matriz29[][TAM] =
    {
        {1,5,2,4,7},
        {3,7,9,6,5},
        {8,3,4,4,2},
        {1,5,3,7,8},
        {9,2,1,3,2}
    };

//    printf("%d", sumaEncimaDiagPpal(matriz, 4));
//    printf("%d", sumaEncimaDiagSdria(matriz29, 4));

//    triangulo_der(matriz29, 4);
primer_cuadrante(matriz29, 5);
//    debajo_diag_ppal(matriz29, 4);

    return 0;
}
