#include <iostream>

using namespace std;

/**
Ejercicio:

Desarrollar una clase que simule el comportamiento de una cadena de texto, sin utilizar el tipo string de C++

La misma se debe poder utilizar con el siguiente main:
**/

int main()
{
    Cadena c1("Hola");
    cout << "c1: " << c1 << endl;

    Cadena c2(c1);
    cout << "c2: " << c2 << endl;

    Cadena c3;
    c3 = c1 + " Mundo";
    cout << "c3: " << c3 << endl;

    cout << "Resumen:" << endl;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c3: " << c3 << endl;

    return 0;
}

/**
Generar un archivo Zip con la resolución del ejercicio. Eliminar los binarios (bin y obj). El archivo debe tener el nombre:
DDDDDDDD_20210925_cadena.zip, donde DDDDDDDD es el número de DNI del alumno.

Subir el archivo como prácticas en la plataforma MIEL.
**/
