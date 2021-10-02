#include <iostream>
#include <string.h>
#include "Cadena.h"
using namespace std;

Cadena::Cadena()
{
    this->_cad = new char[1];
    this->_cad = (char *) '\0';
}

Cadena::Cadena(const char * cadena)
{
    this->_cad = new char[strlen(cadena) + 1];
    strcpy(this->_cad, cadena);
}

Cadena::Cadena(const Cadena & copia)
{
    this->_cad = new char[strlen(copia._cad) + 1];
    strcpy(this->_cad, copia._cad);
}

Cadena::~Cadena()
{
    delete [] this->_cad;
}

ostream &operator << (ostream &sal, const Cadena & cad)
{
    return sal << cad._cad;
}

Cadena Cadena::operator + (const char * otra)
{
    char * cadena = new char[strlen(this->_cad) + strlen(otra) + 2];

    strcpy(cadena, this->_cad);

    strcat(cadena, otra);

    Cadena nueva(cadena);

    return nueva;
}

Cadena Cadena::operator = (const Cadena & cadena)
{
    delete [] this->_cad;

    this->_cad = new char[strlen(cadena._cad) + 1];

    strcpy(this->_cad, cadena._cad);

    return this->_cad;
}

