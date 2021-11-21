#include <stdio.h>
#include <stdlib.h>

#include "utilitarias.h"
#include "ejercicio01.h"
void mostrarMensajeError(const char * mensaje)
{
    printf("Hubo un error al intentar abrir el archivo %s", mensaje);
}

void mostrarArchivoStock(const char * path)
{
    tStock stock;
    FILE * fStock = fopen(path, "rb");

    if(!fStock)
    {
        mostrarMensajeError(path);
    }

    fread(&stock, sizeof(tStock), 1, fStock);
    printf("COD PROD - DESCR - STOCK\n");
    while(!feof(fStock))
    {
        printf("%5s%5s%03d\n", stock.codProd, stock.descripcion, stock.stock);
        fread(&stock, sizeof(tStock), 1, fStock);
    }

    fclose(fStock);

}
void mostrarArchivoPedidos(const char * path)
{
    char linea[16];
    FILE * fPedido = fopen(path, "rt");

    if(!fPedido)
    {
        mostrarMensajeError(path);
    }

    printf("COD PROD - N PEDI - CANTI\n");
    while(fgets(linea, sizeof(linea), fPedido))
    {
        printf("%s\n", linea);
    }

    fclose(fPedido);
}
