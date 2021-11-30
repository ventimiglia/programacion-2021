#ifndef PERSONA_H
#define PERSONA_H


class Persona
{
    private:
        char * _nombre;
        unsigned int _edad;
    public:
        Persona();
        Persona(const char * nombre, const unsigned int edad);
        virtual void imprimirDatosPersonales();
        ~Persona();
        char * getNombre() { return this->_nombre; };
        unsigned int getEdad() { return this->_edad; };
};

#endif // PERSONA_H
