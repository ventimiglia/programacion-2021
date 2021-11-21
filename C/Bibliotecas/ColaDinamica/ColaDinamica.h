#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED

#define MINIMO(X,Y) ((X) < (Y) ? (X) : (Y))

typedef struct sNodo
{
    void * info; ///
    unsigned tamInfo; ///Como no se el tipo de dato, tengo que saber cuanto ocupa el dato
    struct sNodo * sig;
}tNodo;

typedef struct
{
    tNodo * pri;
    tNodo * ult;
}tCola;

void crear_cola(tCola * pc);
int poner_en_cola(tCola * pc, const void * pd, unsigned tam);
int sacar_de_cola(tCola * pc, void * pd, unsigned tam);
int frente_de_cola(const tCola * pc, void * pd, unsigned tam);
int cola_llena(const tCola * pc, unsigned tam);
int cola_vacia(const tCola * pc);
void vaciar_cola(tCola * pc);

#endif // COLADINAMICA_H_INCLUDED
