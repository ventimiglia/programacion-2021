#include <iostream>
#include "../../Bibliotecas/Fecha/Fecha.h"
#include <time.h>
#include <chrono>

using namespace std;
/**
int main()
Ejercicio:

Desarrollar una clase Fecha, que permita visualizar el día, el mes, y el año de la misma,
así como además realizar operaciones de suma, resta y comparaciones entre diferentes objetos de la clase.
Cree las clases y funciones necesarias para que el siguiente main pueda resolver las siguientes operaciones.

La misma se debe poder utilizar con el siguiente main:

using namespace std;
**/

int main()
{

//    Fecha fechaActual;
    Fecha fecha1(15, 7, 2021);
    Fecha fecha2(30, 2, 2021); // Fecha inválida
    Fecha fecha3(30, 4, 2021);
    Fecha fecha4(31, 12, 2021);
    Fecha fecha5(1, 1, 2022);

    fecha1++; // 16, 7, 2021
    fecha3++; // 1,5,2021
    fecha4++; // 1,1,2022


    bool comparacion1 = fecha1 == fecha3;
    bool comparacion2 = fecha4 == fecha5;

    fecha1 += 4;

    --fecha5;

    cout << fecha1;
    cout << fecha3;
    cout << fecha4;
    cout << fecha5;

    cin >> fecha5;
    cout << fecha5;

    time_t x = time(0);

    struct tm y;

    y = *localtime(&x);

    int d,m,a;

    d = y.tm_mday;
    m = y.tm_mon + 1;
    a = y.tm_year + 1900;





    return 0;
}
