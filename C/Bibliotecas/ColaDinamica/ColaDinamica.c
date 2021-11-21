#include <stdlib.h>
#include <string.h>
#include "ColaDinamica.h"

void crear_cola(tCola * pc)
{
    pc->pri = NULL;
    pc->ult = NULL;
}

int poner_en_cola(tCola * pc, const void * pd, unsigned tam)
{
    tNodo * nue = (tNodo*) malloc(sizeof(tNodo));
    if(!nue)
    {
        return 0; ///Cola Llena.
    }
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tamInfo = tam;
    memcpy(nue->info, pd, tam);
    nue->sig = NULL;

    if(pc->ult)
    {
        pc->ult->sig = nue;
    }
    else
    {
        pc->pri = nue;
    }

    pc->ult = nue;

    return 1;
}

void vaciar_cola(tCola * pc)
{
    tNodo* elim;

    while(pc->pri)
    {
        elim = pc->pri;
        pc->pri = elim->sig;

        free(elim->info);
        free(elim);
    }
    //frente se hace null en el while
    pc->ult = NULL;
}

int sacar_de_cola(tCola * pc, void * pd, unsigned tam)
{
    tNodo * elim = pc->pri;

    if(!elim)
    {
        return 0;
    }

    memcpy(pd, elim->info, MINIMO(tam, elim->tamInfo));
    pc->pri = elim->sig;

    if(!pc->pri)
    {
        pc->ult = NULL;
    }

    free(elim->info);
    free(elim);


    return 1;///Verdadero
}

int frente_de_cola(const tCola * pc, void * pd, unsigned tam)
{
    if(!pc->pri)
        return 0;

    //memcpy(dato, pc->frente->dato, min(tamElem, pc->frente->tamElem));
    tNodo* frente = pc->pri;
    memcpy(pd, frente->info, MINIMO(tam, frente->tamInfo));
    //los 2 de arriba son lo mismo pero la 2da es mas optima, en la primera
    //desreferencio 4 veces, mientras que en la 2da ahorro eso
    return 1;
}

int cola_llena(const tCola * pc, unsigned tam)
{
    void* nodo = malloc(sizeof(tNodo));
    void* dato = malloc(tam);

    free(nodo);
    free(dato);

    return !nodo || !dato;
}

int cola_vacia(const tCola * pc)
{
    return !pc->pri;
}
