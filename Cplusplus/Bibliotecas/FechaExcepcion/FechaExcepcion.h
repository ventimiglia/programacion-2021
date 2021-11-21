#ifndef FECHAEXCEPCION_H_INCLUDED
#define FECHAEXCEPCION_H_INCLUDED

#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>
using namespace std;

class Fecha
{
private:
    int _dia,_mes,_anio;
    static bool esFechaValida( int dia,  int mes,  int anio);
    static bool esBisiesto(int anio);
public:
    Fecha();
    Fecha( int dia,  int mes,  int anio);

    Fecha   operator +  (int dias);
    Fecha&  operator ++ ();
    Fecha   operator ++ (int);
    Fecha&  operator += (const int dia);
    Fecha   operator -  (const int dia);
    Fecha&  operator -- ();
    Fecha   operator -- (int);
    bool    operator == (Fecha & fecha) const;

    friend ostream &operator << (ostream &sal, const Fecha &f);

    friend istream &operator >> (istream &ent, Fecha &f);
};

#endif // FECHA_H_INCLUDED


#endif // FECHAEXCEPCION_H_INCLUDED
