#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

typedef struct sNodo
{
    void * info;
    unsigned tamInfo;
    struct sNodo * sig;
} tNodo;

typedef tNodo * tPila;

#endif // PILADINAMICA_H_INCLUDED
