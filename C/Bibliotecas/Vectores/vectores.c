#include <stdio.h>
#include "vectores.h"

void mostrarVector (const int * vec, int cantidadElementos)
{
    int * fin = vec + cantidadElementos;

    while (vec < fin)
    {
        printf("-%d-", *vec);
        vec++;
    }
}

int insertarElemPos(int * vec, int * ce, int tam, int elem, unsigned pos)
{
    int * aux = vec + *ce;
    int * destino = vec + pos;

    if(*ce==tam)
        return 0;
    if(pos>*ce)
        return 0;

    while(aux > destino)
    {
        *aux = *(aux-1);
        aux--;
    }
    *destino = elem;
    (*ce)++;
    return 1;
}
/*
Ejercicio 22
Desarrollar una función que inserte un elemento en un arreglo de enteros, dada
la posición de inserción
*/

//void insertarEnVectorDadaPosicion(int vectorcio, int posicion, int valor)
//{
//    int *nuevaPosicion = vectorcio + posicion;
//
//    *nuevaPosicion=valor;
//}
