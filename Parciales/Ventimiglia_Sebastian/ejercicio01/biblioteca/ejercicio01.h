#ifndef EJERCICIO01_H_INCLUDED
#define EJERCICIO01_H_INCLUDED

#define ARCHIVO_STOCK       "./archivos/stock.dat"
#define ARCHIVO_PEDIDOS     "./archivos/pedidos.txt"

#include "../cola/ColaDinamica.h"

typedef struct
{
    char codProd[6];
    char descripcion[21];
    int stock;
} tStock;

typedef struct
{
    char codProd[6];
    char nroPedido[6];
    int cantPed;
} tPedido;

int cargarArchivos(void);

int actualizarStock(FILE * fStock, FILE * fPedido);
void mostrarArchivoStock(const char * path);
void mostrarArchivoPedidos(const char * path);


#endif // EJERCICIO01_H_INCLUDED
