#include <stdio.h>
#include <stdlib.h>
#include "../../Bibliotecas/PilaDinamica/PilaDinamica.h"

#define TAM 20

void llenar_pila(FILE * arch, tPila * pila);
void sumar_pilas(tPila * pila1, tPila * pila2, tPila * pila3);

int main()
{
    FILE * arch = fopen("ARCHIVO_NUMEROS.txt", "r+");
    tPila pila1, pila2, pila_res;

    if(!arch)
    {
        printf("Error de apertura de archivo");
        return 1;
    }

    crear_pila(&pila1);
    crear_pila(&pila2);
    crear_pila(&pila_res);

    llenar_pila(arch, &pila1);
    llenar_pila(arch, &pila2);

    return 0;
}


void llenar_pila(FILE * arch, tPila * pila)
{
    char registro[TAM];

    fgets(registro, TAM, arch);

    preg = strchr(registro, '\n');
    *preg = '\0';

    for(int i = 0; i < strlen(registro); i++)
    {
        dato = registro[i] - '0';
    }
}

void sumar_pilas(tPila * pila1, tPila * pila2, tPila * pila3)
{
    int dato1, dato2, dato3, acarreo;

    while(!pi)
}

void grabar_resultado(FILE * arch, tPila * pila_res)
{
    int dato;

//    fprintf(arch, "%d", dato);
    fseek(arch, 0L, 1);///Las funciones de c fseek o fread, funciones que escriben el archivo, no avisen si lo que chieron fue escribir o leer
    ///El SO quiere que se vacien los buffers,
    ///HAGO UN FSEEK ENTRE UNA OPERACIÓN DE LECTURA Y ESCRITURA.
    ///EN ESTE CASO EL FSEEK VA PORQUE EN GRABAR_RESULTADO VIENE LUEGO DE UNA ESCRITURA
    while(!pila_vacia(pila_res))
    {
        sacar_de_pila(pila_res, &dato, sizeof(dato));
        fputc(dato + '0', arch);
    }
}
