#include "../Fecha/fecha.h"

int esFechaValida(const tFecha *f)
{
    if(f->a > 1600)
    {
        return 1;
    }
}

int cantDiasMes(int m, int a)
{
    static const int diasMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    //static no se libera el espacio de memoria cuando se termina la función
    //queda estatico en la memoria, esa memoria no es liberada con la función
    //se mantiene hasta que termina el programa
    //el vector no se tiene que volver a crear cada vez que se llama a la función
    return esBisiesto(a) && m==2 ? 29 : diasMes[m-1];
}

int esBisiesto(int a)
{
    return a%400 == 0 || (a % 4 == 0 && a % 100 != 0);
}
