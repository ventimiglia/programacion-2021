#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "DesafioProfeHeader.h"
#include "../Bibliotecas/Cadena/cadena.h"

int main()
{
//    char nombre1[] = "     pErEz      GomEz   , JoSe    albeRTO          ";
//    printf("%s\n",nombre1);
//    char nombre2[] = "     pErEz     JoSe    albeRTO          ";
//    printf("%s\n",nombre2);
//
//    _removeDoubleSpaces(nombre1);
//    _trim(nombre1);
//    acomodarComa(nombre1);
//    _capitalize(nombre1);
//    _removeDoubleSpaces(nombre2);
//    _trim(nombre2);
//    acomodarComa(nombre2);
//    _capitalize(nombre2);
//
//    printf("%s.\n",nombre1);
//    printf("%s.\n",nombre2);
    char n1[] = "Hola";
    char n2[] = "ch";
    _strcpy(n1,n2);
    printf("%s",n1);
    return 0;
}
