#ifndef PERSONA_H
#define PERSONA_H
#include <string.h>
#include <iostream>

using namespace std;

class Persona
{
    public:
        Persona(int, char*, char);
        Persona(const Persona& other);
        Persona();
        ~Persona();
        bool operator ==(const Persona&);

    protected:
        int dni;
        char* apyn;
        char sex
};

#endif // PERSONA_H
