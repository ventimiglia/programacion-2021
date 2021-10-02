#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED
#include <iostream>

using namespace std;

class Cadena
{
private:
    char * _cad;

public:
    Cadena();
    Cadena(const char * cadena);
    Cadena(const Cadena & copia);
    ~Cadena();

    Cadena operator = (const Cadena & cad);
    Cadena operator + (const char * otra);

    friend ostream &operator << (ostream &sal, const Cadena & cad);
};


#endif // CADENA_H_INCLUDED
