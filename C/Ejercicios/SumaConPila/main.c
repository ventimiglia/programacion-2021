#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Bibliotecas/PilaDinamica/PilaDinamica.h"

int cargar_pila(const char * num, tPila * pp, int cantCeros);
void cargar_vector (tPila * pp, char * suma);
char intAChar (int num);
int charAInt (char c);

int main()
{
    char num1[] = {'1','2','3','4','5','6'};
    char num2[] = {'6','5','4','3','2','1'};
    char suma[7] = {0};
    char digito1, digito2, digitoSuma;
    int digNumCarry = 0, digSuma;
    tPila pila1, pila2, pilares;

    int cantCeros = strlen(num1) - strlen(num2);

//    int cantCerosP1 = 0;
//    int cantCerosP2 = 0;
//
//    cantCeros > 0 ? cantCerosP2 = cantCeros : cantCerosP1 = -cantCeros;


    int cantCerosP1 = cantCeros < 0 ? -cantCeros : 0;
    int cantCerosP2 = cantCeros > 0 ? cantCeros : 0;;


    crear_pila(&pila1);
    crear_pila(&pila2);
    crear_pila(&pilares);

    cargar_pila(num1, &pila1, cantCerosP1);
    cargar_pila(num2, &pila2, cantCerosP2);

    while(!pila_vacia(&pila1))
    {
        sacar_de_pila(&pila1, &digito1, sizeof(char));
        sacar_de_pila(&pila2, &digito2, sizeof(char));

        digSuma = charAInt(digito1) + charAInt(digito2) + digNumCarry;

        digNumCarry = digSuma / 10;

        digSuma %= 10;

        digitoSuma = intAChar(digSuma);

        poner_en_pila(&pilares, &digitoSuma, sizeof(char));

    }

    if(digNumCarry == 1)
    {
        char acarreo = 1;
        poner_en_pila(&pilares, &acarreo, sizeof(char));
    }

    cargar_vector(&pilares, suma); ///agarra la pila y las guarda en el vector

    return 0;
}

int cargar_pila(const char * num, tPila * pp, int cantCeros)
{
    char cero = '0';

    for(int i = 0; i < cantCeros; i++)
    {
        if(!poner_en_pila(pp, &cero, sizeof(char)))
            return 0;
    }

    const char * act = num;

    while(act)
    {
        if(!poner_en_pila(pp, act, sizeof(char)))
            return 0;

        act++;
    }

    return 1;
}

void cargar_vector (tPila * pp, char * suma)
{
    char * act = suma;

    while(!pila_vacia(pp))
    {
        sacar_de_pila(pp, act, sizeof(char));
        act++;
    }
}
char intAChar (int num)
{
     return num + '0';
}
int charAInt (char c)
{
    return c - '0';
}
