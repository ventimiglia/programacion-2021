#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void mostrarCadena(const string &s);

int main()
{

    int vec[10];

    int *p;
    p = (int*) malloc(sizeof(int)* 10);

    cout << sizeof(vec) << endl;
    cout << sizeof(p) << endl;

    free(p);

    int *q = new int[10];

    cout << sizeof(q) << endl;

    delete [] q; ///indicacion de que estoy eliminando un array

    int cant = 25;

    int * r = new int[cant];

    ///new ya es parte del lenguaje, en c++ usaremos solo new malloc ya no lo usaremos aca.
    ///new si no puede reservar memoria, aroja una excepcion.


    string s1 ("Holaa Mundo");

    string s3;

    s1.push_back('!');

    mostrarCadena(s1);
    return 0;
}



void mostrarCadena(const string &s)
{
    for(int i=0; i<s.length(); i++)
    {
        cout << s[i] << "-";
    }

    cout << endl;
}
