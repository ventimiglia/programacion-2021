#include "vectores.h"

/*
Ejercicio 22
    Desarrollar una funci�n que inserte un elemento en un arreglo de enteros, dada
    la posici�n de inserci�n.
*/
int* insertarElementoDadaPosicion(int *vec, int cantidadElementos, int numero, int posicion)
{
    int *vectorAux = vec;
    if(cantidadElementos < posicion)
    {
        return 0;
    }
    vectorAux[posicion] = numero;
    return vectorAux;
}
