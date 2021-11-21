#ifndef FECHAINVALIDAEXCEPCION_H_INCLUDED
#define FECHAINVALIDAEXCEPCION_H_INCLUDED
#include <exception>


class FechaInvalidaException : public std::exception
{
public:
const char* what() throw()
{
return "Error en la fecha";
}
};

#endif // FECHAINVALIDAEXCEPCION_H_INCLUDED
