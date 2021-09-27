#include <stdio.h>

#include "../../../../Bibliotecas/Archivos/Archivos.h"
#include "./ejercicio13.h"

/*
{
    int dni;
    char apellido[30];
    char nombre[30];
    double sueldo;
} t_empleado;
*/

int cargarArchivoEmpleado(char* nombreArchivo)
{
    t_empleado vectorEmpleados[] =
    {
        {
            39066947, "Bianco", "Carlos", 80000
        },
        {
            39066948, "Perez", "Raul", 90000
        },
        {
            39066949, "Zidane", "Brian", 85000
        },
    };

    FILE *fp = fopen(nombreArchivo, "wb");

    if(fp)
    {
        fwrite(vectorEmpleados, sizeof(vectorEmpleados), 1, fp);
        fclose(fp);
        return 1;
    }
    return 0;
}

/*
typedef struct
{
    int dni;
    char apellido[30];
    char nombre[30];
    float promedio;
} t_estudiante;
*/
int cargarArchivoEstudiante(char* nombreArchivo)
{
    t_estudiante vectorEstudiantes[] =
    {
        {
            48500201, "Apple", "Cristiano", 4.5
        },
        {
            39066947, "Bianco", "Carlos", 8.5
        },
        {
            39066948, "Perez", "Raul", 5
        }
    };

    FILE *fp = fopen(nombreArchivo, "wb");

    if(fp)
    {
        fwrite(vectorEstudiantes, sizeof(vectorEstudiantes), 1, fp);
        fclose(fp);
        return 1;
    }
    return 0;
}
