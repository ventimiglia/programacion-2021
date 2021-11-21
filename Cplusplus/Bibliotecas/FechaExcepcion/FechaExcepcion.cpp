#include "Fecha.h"

static const int diasPorMes[][13] =
{
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

Fecha::Fecha( int dia,  int mes,  int anio)
{
    if(!Fecha::esFechaValida(dia,mes,anio))
    {
        throw FechaInvalidaException()
    }
    else
    {
        this->_anio = anio;
        this->_mes = mes;
        this->_dia = dia;
    }
}

bool Fecha::esFechaValida( int dia,  int mes,  int anio)
{
    return ((anio > 1600 && anio < 3000) &&
            (mes > 0 && mes <= 12 ) &&
            (dia > 0 && dia <= diasPorMes[Fecha::esBisiesto(anio)][mes]));
}

bool Fecha::esBisiesto(int anio)
{
    return ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0));
}

Fecha Fecha::operator +(int dias)
{
    Fecha fAux = *this;

    fAux._dia = fAux._dia + dias;

    if(fAux._dia > diasPorMes[Fecha::esBisiesto(fAux._anio)][fAux._mes])
    {
        fAux._mes++;
        fAux._dia = 1;
        if(fAux._mes > 12)
        {
            fAux._anio++;
            fAux._mes = 1;
        }
    }

    return fAux;
}

Fecha& Fecha::operator ++()
{
    *this = *this + 1;
    return *this;
}

Fecha Fecha::operator ++(int)
{
    Fecha aux = *this;
    operator++();
    return aux;
}


bool Fecha::operator == (Fecha & fecha) const
{
    return ((this->_anio == fecha._anio) && (this->_mes == fecha._mes) && (this->_dia == fecha._dia));
}

Fecha& Fecha::operator += (const int dia)
{
    *this = *this + dia;
    return *this;
}

Fecha Fecha::operator - (const int dia)
{
    Fecha fAux = *this;

//    fAux._dia = fAux._dia - dias;

    if((fAux._dia = fAux._dia - dia) < 1)
    {

        fAux._mes--;

        if(fAux._mes == 0)
        {
            fAux._anio--;
            fAux._mes = 12;
            fAux._dia = diasPorMes[Fecha::esBisiesto(fAux._anio)][fAux._mes] - fAux._dia;

            return fAux;
        }

        fAux._dia = diasPorMes[Fecha::esBisiesto(fAux._anio)][fAux._mes] - fAux._dia;
    }

    return fAux;
}

Fecha& Fecha::operator -- ()
{
    *this = *this - 1;
    return *this;
}

Fecha Fecha::operator -- (int)
{
    Fecha aux = *this;
    operator--();
    return aux;
}

ostream &operator << (ostream &sal, const Fecha &f)
{
    return sal << f._dia << "/" << f._mes << "/" << f._anio << "\n";
}

istream &operator >> (istream &ent, Fecha &f)
{
    int d, m, a;
    char c;

    ent >> d >> c >> m >> c >> a;

    if(Fecha::esFechaValida((int)d,(int)m,(int)a))
    {
        f._dia = d;
        f._mes = m;
        f._anio = a;
    }
    else
    {
        f._dia = 0;
        f._mes = 0;
        f._anio = 0;
    }
    return ent;
}


//Fecha Fecha::operator+(int der) const
//{
//    Fecha aux = *this;
//
//    static const char dias[][12] =
//    {
//        { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
//        { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
//    };
//
//
//    if(aux._dia + der > dias[esBisiesto(aux._anio)][aux._mes - 1])
//    {
//        aux._dia = aux._dia+der-dias[esBisiesto(aux._anio)][aux._mes-1];
//        if(aux._mes+1 > 12)
//        {
//            aux._anio++;
//            aux._mes = 1;
//        }
//        else
//        {
//            aux._mes++;
//        }
//    }
//    else
//    {
//        aux._dia += der;
//    }
//
//    return aux;
//}

