#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int d,m,a;
} tFecha;

int esFechaValida(const tFecha *f);


#endif // FECHA_H_INCLUDED
