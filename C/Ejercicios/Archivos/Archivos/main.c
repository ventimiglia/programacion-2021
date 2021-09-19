#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int d,m,a;
} t_fecha;

typedef struct
{
    int dni;
    char apyn[30];
    char sex;
    float promedio;
    int notas[50];
    t_fecha f_ing;
    char estado;
} t_alumno;


int main()
{
    FILE * pf1, *pf2, *pfr;
    t_alumno alu1, alu2;

//    cargar_archivo("alu1.dat");
//    cargar_archivo("alu2.dat");

    pf1 = fopen("alu1.dat", "rb");

    if(!pf1)
    {
        return 1;
    }

    pf2 = fopen("alu2.dat", "rb");

    if(!pf2)
    {
        fclose(pf1);
        return 2;
    }

    pfr = fopen("alu_res.dat", "wb");

    if(!pfr)
    {
        fclose(pf1);
        fclose(pf2);
        return 3;
    }

    printf("Hello world!\n");
    return 0;
}
