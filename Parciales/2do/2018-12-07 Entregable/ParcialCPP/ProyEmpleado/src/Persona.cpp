#include "Persona.h"

using namespace std;

Persona::Persona(int dni, char* apyn, char sex)
{
    this->dni=dni;
    this->sex=sex;
    this->apyn=new char[strlen(apyn)];
    if(!this->apyn)
        throw bad_alloc();
    strcpy(this->apyn,apyn);
}

Persona::~Persona()
{
    delete[]this->apyn;
}

Persona::Persona(const Persona& other)
{
    this->dni=other.dni;
    this->sex=other.sex;
    this->apyn=new char[strlen(other.apyn)];
    if(!this->apyn)
        throw bad_alloc();
    strcpy(this->apyn,other.apyn);
}

Persona::Persona()
{
    this->dni=0;
    this->sex='\0';
    this->apyn=new char[1];
    if(!this->apyn)
        throw bad_alloc();
    this->apyn='\0';
}

bool Persona::operator ==(const Persona& other)
{
    if(this->dni!=other.dni)
        return false;
    if ((this->dni-other.dni)==0 && this->apyn!=other.apyn)
        return false;
    if((this->dni-other.dni)==0 && (this->apyn-other.apyn==0) && this->sex!=other.sex)
        return false;
    else
        return true;
}

