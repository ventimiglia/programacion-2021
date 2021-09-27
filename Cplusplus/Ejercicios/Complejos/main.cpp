#include <iostream>
#include "../../Bibliotecas/Complejo/Complejo.h"

using namespace std;

//void mostrar (int a) ///No deberia ir acá
//{
//    cout << "a:" << a << endl;
//}
//
//void mostrar (int a, int b) ///No deberia ir acá
//{
//    cout << "a:" << a << " b:" << b << endl;
//}
//
//void mostrar (int a, int b, int c) ///No deberia ir acá
//{
//    cout << "a:" << a << " b:" << b << " c:" << c << endl;
//}

void mostrar (int a, int b = 0, int c = 0) ///No deberia ir acá
{
    cout << "a:" << a << " b:" << b << " c:" << c << endl;
}

int main()
{
    ///Ejemplo de como utilizar parametros por default
    ///mostrar(1);
    ///mostrar(1, 2);
    ///mostrar(1, 2, 3);

    Complejo n0(2,3);
    Complejo n1(2,3);
    Complejo n2(5,1);

    int sonIguales = n0 == n1;
    Complejo n3 = n1 + n2;

    cout << "Son iguales ? " << sonIguales << "\n" << endl;
    cout << "Real: " << n3.getReal() << "\n" << "Imaginario: j" << n3.getIma() << endl;

    cout << n2;
    return 0;
}
