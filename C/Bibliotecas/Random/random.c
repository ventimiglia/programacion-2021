#include "random.h"
#include "../Cadena/cadena.h"
/*
Desofuscar la siguiente lineal de texto:
linea="jN jmot k sji sorjdknodrj; ji ouq jmot so omrkdouq nes sjiio. lkksI vjmesA"
La línea fue ofuscada de la siguiente manera:
1.Se identificaron las palabras, bloques de texto compuestos por letras a..z A..Z
2.Se dieron vuelta las palabras, ej. : hola=>aloh
3.Se retrocedieron los caracteres pertenecientes al conjunto : "acefhijklo" 3 posiciones en el mismo conjunto de forma circular, luego de la o esta la a.

No utilice cadenas auxiliares.
*/

/*
1- Se identifican los espacios para separar los bloques de palabras.
2- Seleccionamos el bloque y lo damos vuelta
3- Verificamos si el bloque en esa cadena se encuentra alguno de los caracteres del conjunto
4- Si se encuentra, se cambia ese valor del texto por el correspondiente
*/

char* darVuelta(char *cadena)
{
//    int size = _strlen(cadena) - 1;
//    char *posicionFinal = cadena + size;
//
//    while(size !=0)
//    {
//        *cadena = *posicionFinal;
//        size--;
//        posicionFinal--;
//        cadena++;
//    }



    char* position = _strchr(cadena, 'l');

    printf("%c", *position);

}

void desofuscar(char* cadena, char* clave)
{
    char *bloque;
    bloque = identificar_bloque(cadena);
    char *bloqueRotado = rotar_bloque(bloque);
}

//"jN jmot k sji sorjdknodrj; ji ouq jmot so omrkdouq nes sjiio. lkksI vjmesA";

char* identificar_bloque(char* cadena)
{
    char espacioFinal = strrchr(cadena, ' ');
//    int longitudBloque = strlen(espacioFinal);
    return espacioFinal;
}
char* rotar_bloque(char* bloque)
{
    return strrev(bloque);
}
//desofuscar_bloque(char* bloque, char* clave);
