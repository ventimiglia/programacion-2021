#include <stdio.h>
#include <stdlib.h>
#include "../../Bibliotecas/PilaDinamica/PilaDinamica.h"
/**
1- Crear/cargar Pila1 por teclado con 5 elementos. Poner los primeros tres elementos de la PilaAux1 y los restantes a otra PilaAux2, ambas inicializadas en null/vacias.
2- Cargar PilaOrigen por teclado e inicializar en vacio PilaDestino. Pasar todos los elementos de PilaOrigen a la PilaDestino.
3- Cargar desde teclado Pila1 y pasar a PilaDestino todos aquellos elementos distintos a 8(ocho).
4- Cargar desde taclado PilaOrigen e inicializar (null) la PilaDestino. Pasar los elementos de PilaOrigen a PilaDestino pero deben quedar en el mismo orden.
5- Cargar desde teclado Pila1. Invertir la pila para que Pila1 contenga los elementos cargados originalmente en orden inverso.
6- Pasar el primer elemento de la Pila1 a su última posición, dejando los restantes en el mismo orden.
7- Pasar el último elemento de la Pila1 a su primera posición, dejando los restantes en el mismo orden.
8- Repartir los elementos de la PilaMazo en la PilaJugador1 y PilaJugador2 en forma alternada.
9- Comparar la cantidad de elementos de la PilaA y PilaB. Mostrar por pantalla el resultado.
10- Comparar la cantidad de elementos de la PilaA y PilaB, evaluando si son complemente iguales (en cant de elementos, valores y posiciones). Mostrar por pantalla el resultado.
11- Suponiendo la existencia de PilaModelo no vacia, eliminar de la Pila1 todos los elementos que sean iguales al tope de la PilaModelo.
12- Suponiendo la existencia de PilaModelo vacia o no, eliminar de la Pila1 todos los elementos que existan en PilaModelo.
13- Suponiendo la existencia de PilaLimite, pasar los elementos de la Pila1 que sean >= que el tope de PilaLimite a la PilaMayores y los menores a la pilaMenores.

**/

#define DUPLICADO   0

typedef struct
{
    char cod_art[7];
    char cod_mat_pri[7];
    int cantidad;
    float costo_unit;
} t_mat_prima;


int main()
{

    tPila pila1, aux1, aux2;

    int i, elem=1, poner_ok, cont = 0;

    crear_pila(&pila1);
    crear_pila(&aux1);
    crear_pila(&aux2);

    for(i = 1; i <= 5; i++)
    {
        poner_ok = poner_en_pila(&pila1, &i, sizeof(int));

        if(!poner_ok)
        {
            printf("Pila 1 LLENA!\n");
            return 0;
        }
        printf("Elemento: %d\n", i);
    }


    while(!pila_vacia(&pila1))
    {
        sacar_de_pila(&pila1, &elem, sizeof(int));
//        if(cont <= 2)
//        {
//            poner_ok = poner_en_pila(&aux1, &elem, sizeof(int));
//
//            if(!poner_ok)
//            {
//                printf("Pila Llena!\n");
//                return 0;
//            }
//        }
        printf("EL TOPE DE LA PILA ES: %d\n", elem);


    }

    return 0;
}


