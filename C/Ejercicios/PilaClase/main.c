#include <stdio.h>
#include <stdlib.h>

#include "../../Bibliotecas/PilaDinamica/PilaDinamica.h"
int main()
{
    int elem = 1;
    int i;
    tPila pila_ent;
    crear_pila(&pila_ent); ///Esta lista para poner info en la pila, es como un fopen pero con la pila, ponerla vacia, pone el inicio de la pila en nulo
///Me quedo un puntero a null

    for(i=0; i<8; i++)
    {
        int r = poner_en_pila(&pila_ent, &i, sizeof(i));
        if(!r)
        {
            printf("Pila llena!\n");
        }
    }

    system("pause");

    while(!pila_vacia(&pila_ent))
    {
        sacar_de_pila(&pila_ent, &elem, sizeof(elem));
        printf("-%d", elem);
    }
    return 0;
}

/**
Creo el nodo con el tamaño de la información que voy a necesitar
Si quiero poner en la pila el dato 2, el tamaño de la información la tengo
es 4, con esto me queda el nodo cargado, le dirección siguiente queda vacia
En la posición siguiente, va a ir la dirección del que era primero antes
Lo saco, de pila_ent

**/
/**
Vamos a recibir un archivo con dos numeros, leer el primero y sumarlo al segundo y el resultado escribirlo en el archivo
Cuando lo leo, es un string, deboi parsearlo y guardarlo en una pila. Voy a tener 3 pilas, 1 para el numero 1 otgra para el 2
y otra pára el resultado.

Leo el archivo, abro, el archivo, lo leo, al registro lo tengo que parsear, hay que parsear de adelante hacia atras
712343
  3456
guardo primero el 7
Hay que tener en cuenta el acarreo.
**/


