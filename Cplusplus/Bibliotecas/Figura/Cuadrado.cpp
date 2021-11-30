#include "Cuadrado.h"

Cuadrado::Cuadrado(double lado)
: lado(lado)
{}

double Cuadrado::perimetro()
{
    return this->lado*4;
}
double Cuadrado::area()
{
    return this->lado * this->lado;
}
