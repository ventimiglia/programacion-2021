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
    mostrar(1);
    mostrar(1, 2);
    mostrar(1, 2, 3);
    cout << "Hello world!" << endl;
    return 0;
}
