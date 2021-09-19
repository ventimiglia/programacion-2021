#ifndef COMPLEJO_H_INCLUDED
#define COMPLEJO_H_INCLUDED

class Complejo
{
private:
    float _re;
    float _im;

public:
//    Complejo();
    Complejo(float re = 0, float im = 0);

    float getReal() const;
    void setReal(float _re);

    ///OPERADORES

    ///a + b

    Complejo operator+ (float _re, float_im);
};

#endif // COMPLEJO_H_INCLUDED
