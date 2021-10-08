#include <stdio.h>
#include <stdlib.h>

int main()
{
    int elem = 1;
    int i;
    tPila pila_ent;
    crear_pila(&pila_ent); ///Esta lista para poner info en la pila, es como un fopen pero con la pila, ponerla vacia, pone el inicio de la pila en nulo
///Me quedo un puntero a null
    for(i=0; i<80000; i++)
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
Creo el nodo con el tama�o de la informaci�n que voy a necesitar
Si quiero poner en la pila el dato 2, el tama�o de la informaci�n la tengo
es 4, con esto me queda el nodo cargado, le direcci�n siguiente queda vacia
En la posici�n siguiente, va a ir la direcci�n del que era primero antes
Lo saco, de pila_ent

**/


