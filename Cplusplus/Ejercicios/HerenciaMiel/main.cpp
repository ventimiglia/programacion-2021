#include <iostream>
#include <string.h>

using namespace std;

class Animal
{
protected:
    char * _nombre;
public:
    Animal(char * nombre);

    ~Animal();
    void dormir(void);
    void comer (void);

    friend ostream &operator << (ostream &sal, const Animal & nombre);
};


class Perro : public Animal
{
public:
    Perro(char * nombre);
    void moverCola(void);
};

class Gato : public Animal
{
public:
    Gato(char * nombre);
    void jugarConLaser(void);
};

using namespace std;

int main()
{
    Perro pluto("pluto");
    cout << "pluto: " << pluto << endl;
    pluto.dormir();
    pluto.comer();
    pluto.moverCola();

    Gato garfield("Garfield");
    garfield.dormir();
    garfield.comer();
    garfield.jugarConLaser();

    return 0;
}

Animal::Animal(char * nombre)
{
    this->_nombre = new char[strlen(nombre) + 1];
    strcpy(this->_nombre, nombre);
}

Animal::~Animal()
{
    delete [] this->_nombre;
}

void Animal::dormir(void)
{
    cout << "Soy: " << this->_nombre << " y estoy durmiendo" << endl;
}
void Animal::comer (void)
{
    cout << "Soy: " << this->_nombre << " y estoy comiendo" << endl;
}

ostream &operator << (ostream &sal, const Animal & animal)
{
    return sal << animal._nombre << "\n";
}

Perro::Perro(char * nombre):Animal(nombre)
{

}

void Perro::moverCola()
{
    cout << "Moviendo Cola...";
}

Gato::Gato(char * nombre):Animal(nombre)
{

}

void Gato::jugarConLaser()
{
    cout << "Mi nombre es" << this->_nombre << " y juego con un laser\n";
}

