#include <iostream>

using namespace std;

int main()
{
    Fecha valida(19, 06, 2021);
    Fecha otraFechaValida(15, 10, 2015);

    try
    {
        Fecha invalida(31, 02, 2021);
    }
    catch (FechaInvalidaException &error)
    {
        cout << "Fecha inv�lida" << endl;
    }

//    cout << (valida.antes(otraFechaValida)? "Antes" : "Despues") << endl;
//    cout << (valida.despues(otraFechaValida)? "Despues" : "Antes") << endl;
//    cout << valida << (valida.esBisiesto()? " pertenece a un a�o bisiesto" : " no pertenece a un a�o bisiesto") << endl;
//    cout << valida << (valida.pasoUnAnio(otraFechaValida)? " hace menos de un a�o." : " hace m�s de un a�o.") << endl;
//    cout << "Pasaron " << valida.cantidadDias(otraFechaValida) << "dias entre las fechas." << endl;
//
//    cout << "Le agrego 5 dias a una fecha.";
//    valida += 5;
//    cout << valida

    return 0;
}
