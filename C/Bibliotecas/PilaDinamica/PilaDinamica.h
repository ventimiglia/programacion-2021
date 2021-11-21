#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

#define MINIMO(X,Y) ((X) < (Y) ? (X) : (Y))

/**
El nodo es una estructua que contiene un puntero a la info
el tamaño de esa información y un puntero al siguiente
**/

typedef struct sNodo
{
    void *      info;
    unsigned    tamInfo;
    struct      sNodo * sig;
} tNodo;

typedef tNodo * tPila;

void    crear_pila      (tPila * pp);
int     poner_en_pila   (tPila * pp, const void * pd, unsigned tam);
int     sacar_de_pila   (tPila * pp, void * pd, unsigned tam);
int     pila_vacia      (const tPila * pp);
int     pila_llena      (const tPila * pp, unsigned tam);
int     ver_tope_pila   (const tPila * pp, void * pd, unsigned tam);





#endif // PILADINAMICA_H_INCLUDED
