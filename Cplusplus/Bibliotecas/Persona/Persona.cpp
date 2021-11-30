#include <iostream>
#include <string.h>
#include "Persona.h"

using namespace std;

Persona::Persona(): _edad(0)
{
    this->_nombre = new char [1];
    this->_nombre = (char*)' ';
}

Persona::Persona(const char * nombre, const unsigned int edad) : _edad(edad)
{
    this->_nombre = new char [strlen(nombre) + 1];
    strcpy(this->_nombre, nombre);
}

Persona::~Persona()
{
    delete [] this->_nombre;
}

void Persona::imprimirDatosPersonales()
{
    cout << "\nNombre: " << this->_nombre << endl;
    cout << "\nEdad: " << this->_edad <<  endl;
}
