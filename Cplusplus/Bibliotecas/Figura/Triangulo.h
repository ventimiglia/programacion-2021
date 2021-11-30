#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"
#include "Punto.h"


class Triangulo : public Figura
{
private:
    Punto _p1;
    Punto _p2;
    Punto _p3;
public:
    Triangulo(const Punto & p1,const Punto & p2,const Punto & p3);
    int calcularDeterminante(const Punto &p1, const Punto &p2, const Punto &p3);
    double perimetro();
    double area();
};

#endif // TRIANGULO_H
