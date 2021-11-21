#include "funciones.h"

int main()
{
    char cadena[]="Desarrolle una  funcion que realice, dentro de una cadena, el reemplazo de todas las ocurrencias de una subcadena por otra cadena";

    char reemplazo[]="string";
    char buscar[]="cadena";
    puts("\n Cadena antes del reemplazo----------------------------------");
    printf("\n %s",cadena);
    puts("\n \n Cadena despues del reemplazo-----------------------------");
    printf("\n \n %s",reemplazarUnacadena(cadena,reemplazo,buscar));
    puts("\n");
    return 0;
}
