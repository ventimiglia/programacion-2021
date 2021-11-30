#include <math.h>
#include "Triangulo.h"
#include "FiguraException.h"

Triangulo::Triangulo(const Punto &p1, const Punto &p2, const Punto &p3)
    : _p1(p1), _p2(p2), _p3(p3)
{
    if(this->calcularDeterminante(p1,p2,p3) == 0)
       throw new FiguraException;

}

double Triangulo::perimetro()
{
    return (_p1 - _p2) + (_p2 - _p3) + (_p3 - _p1);
}
double Triangulo::area()
{
    return (1 / 2) * fabs(this->calcularDeterminante(this->_p1,this->_p2,this->_p3));
}

int Triangulo::calcularDeterminante(const Punto &p1, const Punto &p2, const Punto &p3)
{
    return (
            _p1.getX() * (_p2.getY() - _p3.getY()) +
            _p2.getX() * (_p3.getY() - _p1.getY()) +
            _p3.getX() * (_p1.getY() - _p2.getY())
            );
}
