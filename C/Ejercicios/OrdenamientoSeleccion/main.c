#include <stdio.h>
#include <stdlib.h>
#include "../../Bibliotecas/Ordenamiento/ordenamiento.h"

typedef struct
{
    char nombre[30];
    int dni;
    char apellido[30];
} t_persona;

int cmp_ent(const void * e1, const void * e2);
int cmp_persona(const void * e1, const void * e2);

int main()
{
    const t_persona persona1[] = {
        {"Carlos", 39000000, "Paez"},{"Pedro", 32000000, "Pipo"},{"Eugenio", 38000000, "Culini"}
    };

    for(int i = 0; i < 3; i++)
    {
        printf("%s%d%s\n", persona1[i].nombre,persona1[i].dni,persona1[i].apellido);
    }

    ordenarSeleccion(persona1, sizeof(persona1)/sizeof(t_persona), sizeof(t_persona), cmp_persona);

    for(int i = 0; i < 3; i++)
    {
        printf("%s%d%s\n", persona1[i].nombre,persona1[i].dni,persona1[i].apellido);
    }

    return 0;
}

int cmp_ent(const void * v1, const void * v2)
{
    const int * e1 = v1;
    const int * e2 = v2;

    return *e1 - *e2;
}

int cmp_persona(const void * v1, const void * v2)
{
    const t_persona * p1 = v1,
                    * p2 = v2;

    return p1->dni - p2->dni;
}
