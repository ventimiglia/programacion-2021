#include <iostream>

#include "..\..\Bibliotecas\Figura\Triangulo.h"
#include "..\..\Bibliotecas\Figura\Punto.h"
#include "..\..\Bibliotecas\Figura\FiguraException.h"
using namespace std;

int main()
{
    Punto p1(2,2);
    Punto p2(2,2);
    Punto p3(2,2);
    try
    {
        Triangulo triang(p1, p2, p3);
    cout << "\nEl perimetro es: "<< triang.perimetro() << endl;
    } catch (FiguraException* error)
    {
        cout << error->what() << endl;
    }
//    cout << "\nEl area es:" << triang.area()<<endl;
    return 0;
}
