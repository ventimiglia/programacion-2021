#include "Complejo.h"

Complejo::Complejo(float re, float im)
//    :   MiembroDeClase(NuevoValor)
    :   _re(re), _im(im)
    {
    }

float Complejo::getReal() const
{
    return this->_re;
}
