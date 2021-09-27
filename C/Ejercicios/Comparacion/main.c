#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char ape[20];
    char nom[20];
    int dni;
} tEmpleado;

int compararEmpleado(const tEmpleado * e1, const tEmpleado * e2)
{
    int r;
    if((r=strcmpi(e1->ape, e2->ape)) == 0 && (r=strcmpi(e1->nom, e2->nom)) == 0)
    {
        return e1->dni - e2->dni;
    }
    return r;
}

int compararEmpleado2(const tEmpleado * e1, const tEmpleado * e2)
{
    char aux1[49], aux2[49];
    sprintf(aux1, "%-19s%-19s%08d", e1->ape, e1->nom, e1->dni);
    sprintf(aux2, "%-19s%-19s%08d", e2->ape, e2->nom, e2->dni);
    return strcmpi(aux1,aux2);
    ///% campo  s cadena   19 cantidad exacta que tiene la cadena, si tiene menos los complete, el - para que alinie a la izquierda 08 8 minimo, y si tiene menos, completa con 0 a la izquierda.
}

int main()
{
    tEmpleado e1 = {"aa","ab", 12345678};
    tEmpleado e2 = {"aa","ab", 12345679};

    if(compararEmpleado(&e1, &e2) < 0)
    {
        printf("Menor");
    }

    return 0;
}
