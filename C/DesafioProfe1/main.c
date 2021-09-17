#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "DesafioProfeHeader.h"
#include "../Bibliotecas/Cadena/cadena.h"

int main()
{
    char nombre[] = "     pErEz         JoSe           albeRTO          ";
    printf("%s\n",nombre);

    _removeDoubleSpaces(nombre);
    _trim(nombre);
    controlarComa(nombre);
    _capitalize(nombre);

    printf("%s.\n",nombre);
    return 0;
}
