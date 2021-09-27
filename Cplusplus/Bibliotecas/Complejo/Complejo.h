#ifndef COMPLEJO_H_INCLUDED
#define COMPLEJO_H_INCLUDED
#include <iostream>

using namespace std;

class Complejo
{
private:
    float _re;
    float _im;

public:
    Complejo();
    Complejo(float re = 0, float im = 0);
    Complejo(const Complejo & complejo);

    float getReal() const;
    float getIma() const;
    void setReal(float _re);

    ///OPERADORES

    Complejo operator + (const Complejo & num) const;
    Complejo operator * (const Complejo & num) const;
    /// float + a
    friend Complejo operator + (const float & f, const Complejo & num);

    void operator += (const Complejo & num);
    int operator == (const Complejo & num) const;


    friend ostream & operator << (ostream & salida, const Complejo & num);

};

#endif // COMPLEJO_H_INCLUDED
