#include "Complejo.h"
#include <iostream>
Complejo::Complejo()
{
    this->_re = 0;
    this->_im = 0;
}

Complejo::Complejo(float re, float im)
//    :   MiembroDeClase(NuevoValor)
    :   _re(re), _im(im)
    {
    }

Complejo::Complejo(const Complejo & complejo)
{
    this->_im = complejo._im;
    this->_re = complejo._re;

}

float Complejo::getReal() const
{
    return this->_re;
}

float Complejo::getIma() const
{
    return this->_im;
}

Complejo Complejo::operator + (const Complejo & num) const
{
    float newReal = this->_re + num._re; ///Con respecto al + Izquierda es this, derecha es el parametro
    float newIm = this->_im + num._im;

    Complejo aux (newReal, newIm);

    return aux;
}

Complejo operator + (const float & f, const Complejo & num)
{
    Complejo aux(f + num._re, num._im);
    return aux;
}

void Complejo::operator += (const Complejo & num)
{
    this->_re = this->_re + num._re;
    this->_im = this->_im + num._im;
}


int Complejo::operator == (const Complejo & num) const
{
    if((this->_re == num._re)&&(this->_im == num._im))
    {
        return 1;
    }
    return 0;
}

ostream & operator << (ostream & salida, const Complejo & num)
{
    salida << num._re;
    salida << " ; j";
    salida << num._im;
    return salida;
}

