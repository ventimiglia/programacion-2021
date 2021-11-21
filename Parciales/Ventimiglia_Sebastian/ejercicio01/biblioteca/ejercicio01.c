#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ejercicio01.h"


void cargarArchivoStock(FILE * fStock);
void cargarArchivoPedido(FILE * fPedido);
int lecturaPedido(tPedido * pedido, FILE * fPedido);

int cargarArchivos()
{
    FILE * fStock = fopen(ARCHIVO_STOCK, "wb");

    if(!fStock)
    {
        printf("Hubo un problema al abrir el archivo de stocks.\n");
        return 0;
    }
    FILE * fPedidos = fopen(ARCHIVO_PEDIDOS, "wt");
    if(!fPedidos)
    {
        printf("Hubo un problema al abrir el archivo de pedidos.\n");
        fclose(fStock);
        return 0;
    }

    cargarArchivoStock(fStock);

    cargarArchivoPedido(fPedidos);

    fclose(fStock);
    fclose(fPedidos);

    return 1;

}

void cargarArchivoStock(FILE * fStock)
{
    tStock stock[] =
    {
        {"20201", "Barra de Cereal", 20},
        {"20202", "Chocolate", 10},
        {"20203", "Leche", 5},
        {"20204", "Arroz", 1}
    };

    fwrite(stock, sizeof(stock), 1, fStock);

}


void cargarArchivoPedido(FILE * fPedido)
{
    tPedido pedido[] =
    {
        {"20200","00008", 2},
        {"20200","00008", 5},
        {"20200","00008", 1},
        {"20201","00002", 10},
        {"20202","00004", 1},
        {"20203","00003", 20},
        {"20204","00003", 2},
        {"20205","00005", 10},
    };

    int longitud = sizeof(pedido) / sizeof(tPedido);

    for(int i = 0; i < longitud; i++)
    {
        fprintf(fPedido,"%5s%5s%03d\n", pedido[i].codProd, pedido[i].nroPedido, pedido[i].cantPed);
    }
}

int actualizarStock(FILE * fStock, FILE * fPedido)
{
    tStock stock;
    tPedido pedido, pedidoRechazado;
    tCola colaPedidosRechazados;
    char * pedidoAnterior;
    int estadoLecturaTexto;
    char nombreArchivo[20];
    char pathArchivo[] = "./archivos/";

    crear_cola(&colaPedidosRechazados);

    fread(&stock, sizeof(stock),1,fStock);
    estadoLecturaTexto = lecturaPedido(&pedido, fPedido);

    while(!feof(fStock) && estadoLecturaTexto)
    {
        if(strcmp(pedido.codProd, stock.codProd) < 0)
        {
            estadoLecturaTexto = lecturaPedido(&pedido, fPedido);
        }
        else if (strcmp(pedido.codProd, stock.codProd) > 0)
        {
            fread(&stock, sizeof(stock),1,fStock);
        }
        else if (strcmp(pedido.codProd, stock.codProd) == 0)
        {
            while(strcmp(pedido.codProd, stock.codProd) == 0 && estadoLecturaTexto)
            {
                if(stock.stock - pedido.cantPed <= 0)
                {
                    poner_en_cola(&colaPedidosRechazados, &pedido, sizeof(tPedido));
                }
                else
                {
                    stock.stock = stock.stock - pedido.cantPed;
                }
                estadoLecturaTexto = lecturaPedido(&pedido, fPedido);
            }

            fseek(fStock, - (int)sizeof(tStock),SEEK_CUR);
            fwrite(&stock, sizeof(tStock), 1, fStock);
            fseek(fStock, 0L, SEEK_CUR);
        }
        else
        {
            poner_en_cola(&colaPedidosRechazados, &pedido, sizeof(tPedido));
//            pedidoAnterior = pedido.codProd;
//            while(estadoLecturaTexto && pedidoAnterior == pedido.codProd)
//            {
//                estadoLecturaTexto = lecturaPedido(&pedido, fPedido);
//            }
        }
    }

    if(!cola_vacia(&colaPedidosRechazados))
    {

        printf("Hay pedidos que no pudieron saldarse debido a falta de stock\n");
        printf("Los pedidos se almacenarán en un archivo de texto\n");
        printf("Para ver dichos pedidos por favor ingresar el nombre del archivo donde se almacenarán\n");
        printf("El nombre no debe tener caracteres especiales\n");

        gets(nombreArchivo);

        strcat(pathArchivo, nombreArchivo);

        strcat(pathArchivo, ".txt");

        if(strstr(pathArchivo, ".txt"))
        {
            FILE * fPedidoRechazado = fopen(pathArchivo,"wt");


            while(sacar_de_cola(&colaPedidosRechazados, &pedidoRechazado, sizeof(tPedido)))
            {
                fprintf(fPedidoRechazado,"%5s%5s%03d\n",
                        pedidoRechazado.codProd,
                        pedidoRechazado.nroPedido,
                        pedidoRechazado.cantPed);
            }

            fclose(fPedidoRechazado);
        }

    }

    return 1;
}

int lecturaPedido(tPedido * pedido, FILE * fPedido)
{
    return fscanf(fPedido, "%5s%5s%3d", pedido->codProd, pedido->nroPedido, &pedido->cantPed) == 3;
}



