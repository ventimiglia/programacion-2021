#include <stdio.h>
#include <stdlib.h>
#include "TuPlataMiPlata.h"

void cargarCuenta(FILE * fCuenta);
void cargarMovimiento(FILE * fMov);

void prepararArchivos(void)
{
    FILE * fCuenta = fopen(ARCHIVO_CUENTAS, "wb");
    FILE * fMov = fopen("movimientos.txt", "wt");

    if(!fCuenta)
    {
        printf("No se pudo abrir el archivo");
    }

    if(!fMov)
    {
        printf("No se pudo abrir archivo de texto");
        fclose(fCuenta);
    }

    cargarCuenta(fCuenta);

    cargarMovimiento(fMov);

    fclose(fCuenta);
    fclose(fMov);
}

void cargarCuenta(FILE * fCuenta)
{
    tCuenta cuenta[] = { {"637043/2", 10.40},{"637044/0", 20.45},{"637045/9", 22.34} };

    int longitud = sizeof(cuenta) / sizeof(tCuenta);

    for(int i = 0; i < longitud; i++)
    {
        fwrite(cuenta, sizeof(cuenta), 1, fCuenta);
    }
}


void cargarMovimiento(FILE * fMov)
{
    tMovimiento movimiento[] = { {"637043/2", 8.40, 'D'},{"637044/0", 10.45, 'C'},{"637045/9", 22.34, 'C'} };

    int longitud = sizeof(movimiento) / sizeof(tMovimiento);

    for(int i = 0; i < longitud; i++)
    {
        fprintf(fMov,"%s|%4.2f|%c\n", movimiento[i].numeroCuenta, movimiento[i].monto, movimiento[i].tipo);
    }
}

