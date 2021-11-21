#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

typedef struct sNodo
{
    void * info;
    unsigned tamInfo;
    struct sNodo * sig;
} tNodo;

typedef tNodo * tPila;

void crear_pila(tPila pp);
int poner_en_pila(tPila pp, void * info);

#endif // PILADINAMICA_H_INCLUDED
