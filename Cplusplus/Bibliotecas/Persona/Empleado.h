#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"


class Empleado : public Persona
{
private:
    float _sueldo;

public:
    Empleado();
    Empleado(const char * nombre, unsigned int edad, float sueldo);
    Empleado(Empleado & emp);
    ~Empleado();
    void imprimirDatosPersonales();
    void cargarSueldo();

    Empleado operator++(int);
    // Empleado & operator = (Empleado & otra);


};

#endif // EMPLEADO_H
