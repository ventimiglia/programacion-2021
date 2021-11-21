#include "FVector.h"

using namespace std;

FVector::FVector(float* flo, int cant)
{
    int i;
    this->cant=cant;
    this->flot=new float[cant];
    if(!this->flot)
        throw bad_alloc();
    for(i=0; i<cant; i++)
        this->flot[i]=flo[i];

}

FVector::~FVector()
{
    delete[]this->flot;
}

FVector::FVector(const FVector& other)
{
    int i;
    this->flot=new float[other.cant];
    if(!this->flot)
        throw bad_alloc();
    for(i=0; i<other.cant; i++)
        other.flot[i]=this->flot[i];
}

FVector::FVector()
{
    this->flot=new float[1];
    if(!this->flot)
        throw bad_alloc();
    this->flot[0]=0;
}

ostream& operator<<(ostream& os,const FVector& vec)
{
    int i;
    os<<"{";
    for(i=0; i<vec.cant-1; i++)
        os<<vec.flot[i]<<",";
    os<<vec.flot[vec.cant-1]<<"}";
    return os;
}

FVector& FVector::operator+=(int num)
{
    int i;
    for(i=0; i<this->cant; i++)
        this->flot[i]+=num;
    return *this;
}

bool FVector::operator==(const FVector& other)
{
    if(other.flot - this->flot)
        return true;
    return false;
}

FVector FVector::operator--(int)
{
    FVector result;
    int i;
    result.cant=this->cant;
    delete[]result.flot;

    return result;
}

FVector FVector::operator/(const FVector& other)
{
    int i;

}
