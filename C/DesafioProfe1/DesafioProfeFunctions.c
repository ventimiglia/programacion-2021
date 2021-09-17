/**
Escriba una función que normalice una cadena de caracteres que representan el nombre y apellido completo de una persona:

Normalización del apellido y nombres, consistente en:



* El/Los apellido/s y nombre/s deben comenzar con letra mayúscula y luego continuar con minúscula.

* El/Los apellido/s deben estar separado/s del/los nombre/s por una coma. De no existir dicha coma,
agregarla a continuación de la primera palabra.

* Cada palabra debe separarse por no más de un espacio.

* La cadena no debe tener espacios al inicio, ni al final de la misma.

* En este caso, los apellido y nombres pueden venir con espacios de mas entre las palabras, más de una coma o ninguna coma,
caracteres especiales y mayusculas y minusculas en lugares incorrectos.

EJ: "     pErEz     JoSe    albeRTO          " --> "Perez, Jose Alberto'
"     pErEz      GomEz   , JoSe    albeRTO          " --> "Perez Gomez, Jose Alberto'
**/

///char * sinEspaciosPrincipioFinal(char * nombre)
///char * sinEspaciosDobles(char * nombre)
///char * capitalizar(char * nombre)
///char * controlarComa(char * nombre)

///EJ: "     pErEz     JoSe    albeRTO          " --> "Perez, Jose Alberto'
///EJ: "pErEz     JoSe    albeRTO" --> "Perez, Jose Alberto'
///EJ: "pErEz JoSe albeRTO" --> "Perez, Jose Alberto'
///EJ: "pErEz, JoSe albeRTO" --> "Perez, Jose Alberto'
///EJ: "Perez, Jose Alberto" --> "Perez, Jose Alberto'

#include <string.h>
#include "DesafioProfeHeader.h"



char * controlarComa(char * nombre)
{
    char * posicionComa = strchr(nombre, ',');
    char * primerEspacio = strchr(nombre, ' ');

    if(!posicionComa)
    {
        memmove(primerEspacio + 1, primerEspacio, strlen(primerEspacio));
        *primerEspacio = ',';
    }
    return nombre;
}

//char * capitalizar(char * nombre);

