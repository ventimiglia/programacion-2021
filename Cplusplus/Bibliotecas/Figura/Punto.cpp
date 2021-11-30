#include <math.h>
#include "Punto.h"

Punto::Punto(double x, double y)
: x(x), y(y)
{}

double Punto::operator -(const Punto & otro) const
{
    double catetoX = fabs(this->x - otro.x);
    double catetoY = fabs(this->y - otro.y);
    return sqrt(pow(catetoX, 2) + pow(catetoY, 2));
}
