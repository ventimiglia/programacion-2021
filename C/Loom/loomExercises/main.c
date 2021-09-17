#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Unidad1/Bibliotecas/Random/random.h"
#include "../../Unidad1/Bibliotecas/Cadena/cadena.h"

int main()
{
    const char cadena[] = "jN jmot k sji sorjdknodrj; ji ouq jmot so omrkdouq nes sjiio. lkksI vjmesA";
    const char clave[] = "acefhijklo";
//    printf("%s", cadena);
//    const char prueba[] = "PIPIR";
desofuscar(cadena, clave);
//    int cantidad = _strlen(prueba);

    return 0;
}
