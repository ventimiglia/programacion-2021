#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "Persona.h"

using namespace std;

class Empleado
{
    public:
        Empleado(float, char*, Persona&);
        Empleado(const Empleado& other);
        Empleado();
        ~Empleado();
        Empleado& operator+(int);
        friend istream& operator>>(istream&, Empleado&);
        friend ostream& operator<<(ostream&,const Empleado&);

    protected:
        float sueldo;
        char* cargo;
        Persona emple;

};

#endif // EMPLEADO_H
