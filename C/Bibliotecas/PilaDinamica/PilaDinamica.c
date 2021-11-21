#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "PilaDinamica.h"


/**
crear_pila => toma el puntero y lo setea a null,
pone el puntero en null.
**/
void crear_pila(tPila * pp)
{
    *pp = NULL;
}

int poner_en_pila(tPila * pp, const void * pd, unsigned tam)
{
    ///Lo primero que tengo que hacer es crear el nodo
    ///Creo el nodo sin el dato
    ///Luego creo el espacio que necesito para el dato
    tNodo * nue = (tNodo*) malloc(sizeof(tNodo));
    //Guarda la referencia del nodo que voy a crear, reserva el espacio de memoria
    if(!nue)
    {
        return 0; ///
    }

    nue->info = malloc(tam);

    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tamInfo = tam;
    nue->sig = *pp;
    memcpy(nue->info, pd, tam);

    *pp = nue;
    return 1;
}

/**
*
*@param
*   Son 3:
*       direcci�n de memoria de la pila de enteros en pp
*       la direcci�in de memoria del dato que voy a guardar
*       El tama�o de lo que estoy esperando sacar
**/
int sacar_de_pila(tPila * pp, void * pd, unsigned tam)
{
    ///Guardo la referencia de lo que voy a eliminar
    tNodo * elim = *pp; ///Apunta a un nodo que lo habia creado con malloc

    if(!*pp)
    {
        return 0;
        /**
        Pregunto si la pila est� vacia
        **/
    }

    memcpy(pd, elim->info, MINIMO(elim->tamInfo, tam));///Copio el dato
    *pp = elim->sig; ///Hago que la flecha apunte al nodo siguiente

    free(elim->info);   ///Libero memoria informaci�n
    free(elim);         ///Libero memoria del nodo
    return 1;
    /**
    MINIMO
    Que pasa si en pila estoy guardando una cadena de caracteres�?
    quiero que mi pila guarde el tama�o exacto de mi cadena
    Si lo que me pasan para sacar de una pila sea mas grande
    que lo que realmente tengo guardado?
    El problema est� en que me envian un recipiente para almacenar 20 caramelos
    y tengo 15, estoy desperdiciando memoria, ahora que pasa si me envian un recip�ente
    para almacenar 20 caramelos y yo tengo que darle 25, es un error del programador

        * tamInfo == tam => genial
        * tamInfo < tam => solo quiero copiar tam, no quiero desperdiciar espacio
        * tamInfo > tam => es un error, voy a perder info, pero solo voy a guardar el tama�o de tam

    Con la funci�n MINIMO nos aseguramos que copiaremos el mas chico, osea, tamInfo
    **/
}

/**
*Valida que una pila no est� vacia
**/
int pila_vacia(const tPila * pp)
{
    return *pp == NULL;
    /**
    Si el puntero pp est� apuntando a NULL, est� vacia la pila
    **/
}

int pila_llena(const tPila * pp, unsigned tam)
{
    /**
    Reservo las dos memorias, la que es para el nodo y la que es para la info
    **/

    void * nodo = malloc(sizeof(tNodo));
    void * info = malloc(sizeof(tam));
    free(nodo);
    free(info);

    /**
    Si no pude crear el espacio de memoria, es porque la pila est� llena.
    Por mas que hya aliberado la memoria, las variables aun existe, y puedo preguntar si pudieron reservar memoria o no
    **/

    return !nodo || !info;

}

/**
Mostrar el dato que se encuentra en el tope de la pila
**/
int ver_tope_pila(const tPila * pp, void * pd, unsigned tam)
{
    if(!*pp)
    {
        return 0;
    }

    tNodo * elem = *pp;

    memcpy(pd, elem->info, MINIMO(tam, elem->tamInfo));
    return 1;
}
//
//
void vaciar_pila(tPila * pp)
{
    tNodo * elim; ///Apunta a un nodo que lo habia creado con malloc

    while(*pp)
    {
        elim = *pp;
        *pp = elim->sig;
        free(elim->info);   ///Libero memoria informaci�n
        free(elim);         ///Libero memoria del nodo
    }
}
