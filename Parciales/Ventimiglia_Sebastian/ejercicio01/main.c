#include <stdio.h>
#include <stdlib.h>

#include "./biblioteca/ejercicio01.h"
#include "./biblioteca/utilitarias.h"


int main()
{
    /**
    Función utilizada para crear y cargar los archivos
    **/
    cargarArchivos();

    printf("\n\n*********STOCK***********\n");
    mostrarArchivoStock(ARCHIVO_STOCK);
    printf("\n*********FIN STOCK***********\n\n");
    printf("\n\n*********PEDIDOS***********\n");
    mostrarArchivoPedidos(ARCHIVO_PEDIDOS);
    printf("\n*********FIN PEDIDOS***********\n\n");

    FILE * fStock = fopen(ARCHIVO_STOCK, "r+b");

    if(!fStock)
    {
        mostrarMensajeError(ARCHIVO_STOCK);
    }

    FILE * fPedido = fopen(ARCHIVO_PEDIDOS, "rt");

    if(!fPedido)
    {
        mostrarMensajeError(ARCHIVO_PEDIDOS);
        fclose(fStock);
    }

    actualizarStock(fStock, fPedido);


    fclose(fStock);
    fclose(fPedido);

    return 0;
}
