#include <iostream>
#include "../../Bibliotecas/Fecha/fecha.h"
#include "../../Bibliotecas/Boolean/Boolean.h"

/*
Ejercicio:

Desarrollar una clase que simule el comportamiento de tipo de dato bool (el cual tiene 2 valores (true y false), sin utilizar el tipo bool de C++

La misma se debe poder utilizar con el siguiente main:

using namespace std;

int main()
{

    Boolean falseBoolean,
            trueBoolean(1); //true

    Boolean resultFalseAndTrue = falseBoolean._and(trueBoolean);
    Boolean resultTrueOrTrue = trueBoolean._or(trueBoolean);
    Boolean resultNotFalse = falseBoolean._not();

    cout << "resultFalseAndTrue:" << resultFalseAndTrue.getValue() << endl;
    cout << "resultTrueOrTrue :" << resultTrueOrTrue.getValue() << endl;
    cout << "resultNotFalse    :" << resultNotFalse.getValue() << endl;
    return 0;
}
*/

using namespace std;

int main()
{
    Boolean falseBoolean;
    Boolean trueBoolean(1); //true

    Boolean resultFalseAndTrue = falseBoolean._and(trueBoolean);
    Boolean resultTrueOrTrue = trueBoolean._or(trueBoolean);
    Boolean resultNotFalse = falseBoolean._not();


    cout << "resultFalseAndTrue:" << resultFalseAndTrue.getValue() << endl;
    cout << "resultTrueOrTrue :" << resultTrueOrTrue.getValue() << endl;
    cout << "resultNotFalse    :" << resultNotFalse.getValue() << endl;
    return 0;
}
