#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
//#include "../Bibliotecas/Matematica/matematica.h"
//#include "../Bibliotecas/Vectores/vectores.h"
#include "../Bibliotecas/Fecha/fecha.h"
//#define TAM 10

int main()
{
//    int vec[] = {1,2,3,4,5,6,7,8};
//    int posicion = 2;
//    int valor = 99;

//    mostrarVector(vec, 10);

//    insertarEnVectorDadaPosicion(vectorcito, posicion, valor);

    //Variables definidas como estructuras
//    tFecha f1 = {8,9,2002};
//    tFecha f2 = {1,2,2012};

    //Punteros a estructuras

//    tFecha *pf;

//    pf = &f1;
    //pf almacena la dirección de memoria de f1


    //Como imprimir en pantalla
//    printf("\n%d/%d/%d -- %d/%d/%d", f1.d, f1.m, f1.a, pf->d, pf->m, pf->a);
    //Con la flecha no es necesario poner el asterisco.
    //El punto lo uso cuando quiero acceder a un elemento de la variable struct
    //La flecha la uso cuando quiero acceder a un elemento de un puntero que apunte a una struct


//    tFecha vf1[] = {{9,2,2123},{10,2,2020}};
    //Las variables de estructura se definen como variables
//    f1 = f2;
    //Esto es posible realizarlo.

    //Debo validar que sea un año valido que de 1600 hacia aca sea valido

//    int valida = esFechaValida(const tFecha *f);

int mat [3][50] = {{1,2,3},{4,5,6},{7,8,9}};

//debajo_diag_ppal(mat2,7);
    return 0;
}


void debajo_diag_ppal(int mat[][50], int ord)
{
    int i, j;
    for(i = 1; i < ord; i++) ///porque la primera no se imprime el i = 1
    {
        for(j=0 ; j<i; j++)///el ciclo de la J debe llegar a la diagonal principal
        {

        }
    }
}
