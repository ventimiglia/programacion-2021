#include <iostream>
#include "..\..\Bibliotecas\Persona\Persona.h"
#include "..\..\Bibliotecas\Persona\Empleado.h"

using namespace std;

int main()
{
    Persona persona1;
    persona1.imprimirDatosPersonales();

    Empleado empleado1;
    empleado1.cargarSueldo();
    Empleado empleado2("Ricardo", 34,50000);
    empleado1 = empleado2++;  // El metodo ++ suma uno a la edad
    empleado1.imprimirDatosPersonales(); // muestra todo null salvo el sueldo cargado por teclado.
    empleado2.imprimirDatosPersonales(); // muestra todos los datos de empleado2.
    return 0;
}
