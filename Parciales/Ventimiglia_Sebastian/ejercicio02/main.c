#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cadena1[] = "hola";
    char cadena2[] = "olah";

    if(cadena1 - cadena2 < 0)
    {
        printf("No es anagrama");
        return 0;
    }

    printf("Es anagrama");
    return 0;
}
