#include "Empleado.h"
#include "Persona.h"

using namespace std;

Empleado::Empleado(float sueldo, char* cargo, Persona& gente)
{
    this->sueldo=sueldo;
    this->cargo=new char[strlen(cargo)+1];
    if(!this->cargo)
        throw bad_alloc();
    strcpy(this->cargo,cargo);
}

Empleado::Empleado()
{
    this->sueldo=0;
    this->cargo=new char[1];
    if(!this->cargo)
        throw bad_alloc();
    this->cargo='\0';
}

Empleado::~Empleado()
{
    delete[]this->cargo;
}

Empleado::Empleado(const Empleado& other)
{
    this->sueldo=other.sueldo;
    this->cargo=new char[strlen(other.cargo)+1];
    if(!this->cargo)
        throw bad_alloc();
    strcpy(this->cargo,other.cargo);
}

ostream& operator <<(ostream& os, const Empleado& emp)
{
    Persona per;
    os<<"(";
    os<<emp.sueldo<<","<<per.dni<<"|"<<per.apyn<<"|"<<per.sex;
    os<<((emp.cargo=='\0')?"Sin Cargo":emp.cargo)<<")";
    return os;
}

//istream& operator>>(istream& is, Empleado& emp)
//{
//    Empleado vec[1000];
//    is.getline(vec,1000);
//    delete[]vec.cargo;
//    vec.cargo=new char[strlen(emp.cargo)];
//    if(!vec.cargo)
//        throw bad_alloc();
//    vec.cargo=emp.cargo;
//    vec.sueldo=atoi(emp.sueldo);
//    is>>vec.sueldo;
//    return is;
//}

Empleado& Empleado::operator+(int num)
{
    this->cargo+=num;
    return *this;
}

