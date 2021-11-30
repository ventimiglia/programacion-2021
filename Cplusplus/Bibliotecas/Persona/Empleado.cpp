#include <iostream>
#include "Persona.h"
#include "Empleado.h"

using namespace std;

Empleado::Empleado() : Persona(), _sueldo(0)
{}

Empleado::Empleado(const char * nombre, unsigned int edad, float sueldo): Persona(nombre, edad), _sueldo(sueldo)
{}

Empleado::~Empleado()
{}

Empleado::Empleado(Empleado & emp): Persona(emp.getNombre(), emp.getEdad()), _sueldo(emp._sueldo)
{}

void Empleado::imprimirDatosPersonales()
{
    Persona::imprimirDatosPersonales();
    cout << "\nSueldo: " << this->_sueldo << endl;
}

Empleado Empleado::operator++(int)
{
    Empleado temp(Persona::getNombre(), Persona::getEdad() + 1, this->_sueldo);
    return temp;
}

void Empleado::cargarSueldo()
{
    float sueldoAux;
    cout << "\nIngresar sueldo empleado: " << endl;
    cin >> sueldoAux;
    this->_sueldo = sueldoAux;
}
// Empleado& operator =(const Empleado& otra)
// {
//     size_t tam = strlen(otra._nombre) + 1;

//     if(strlen(this->_nombre) != tam)
//     {
//         delete [] this->_nombre;
//         this->_nombre = new char[tam];
//     }
//     strcpy(this->_nombre, otra._nombre);

//     this->_edad = otra._edad;
//     this->_sueldo = otra._sueldo;

//     return *this;
// }



