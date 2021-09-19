#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#define TAM 10

int main()
{
    int vectorPrueba[] = {1,2,3,4,5,6};
    int cantidadElementos = 6;
    int posicion = 2;
    int numero = 45;
    int i = 0;
    int *ejercicio22 = insertarElementoDadaPosicion(vectorPrueba, cantidadElementos, numero, posicion);

    for(i; i < cantidadElementos; i++)
    {
        printf("%d,", ejercicio22[i]);
    }
    return 0;
}
