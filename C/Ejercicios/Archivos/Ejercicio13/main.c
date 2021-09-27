#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./includes/ejercicio13.h"
int main()
{
    FILE * fpEstudiante, *fpEmpleado, *pfr;
    int comparacion;
    t_empleado empleado;
    t_estudiante estudiante;
//
//    if(!cargarArchivoEstudiante("estudiantes.dat"))
//    {
//        return 0;
//    }
//
//    if(!cargarArchivoEmpleado("empleados.dat"))
//    {
//        fclose
//    }

    cargarArchivoEstudiante(ESTUDIANTES);
    cargarArchivoEmpleado(EMPLEADOS);

    fpEstudiante = fopen(ESTUDIANTES, "rb");

    if(!fpEstudiante)
    {
        return 1;
    }
    fpEmpleado = fopen(EMPLEADOS, "r+b");

    if(!fpEmpleado)
    {
        fclose(fpEstudiante);
        return 2;
    }

    fread(&empleado,sizeof(t_empleado), 1, fpEmpleado);
    fread(&estudiante,sizeof(t_estudiante), 1, fpEstudiante);

    while(!feof(fpEmpleado)&&!feof(fpEstudiante))
    {
        comparacion = strcmpi(empleado.apellido, estudiante.apellido);
        if(comparacion == 0 && estudiante.promedio > 7)
        {
            empleado.sueldo = empleado.sueldo * AUMENTO;
            fseek(fpEmpleado, (long)-(sizeof(t_empleado)), SEEK_CUR);
            fwrite(&empleado, sizeof(t_empleado), 1, fpEmpleado);
            fseek(fpEmpleado, 0, SEEK_CUR);
            fread(&empleado,sizeof(t_empleado), 1, fpEmpleado);
            fread(&estudiante,sizeof(t_estudiante), 1, fpEstudiante);
        }
        else if (comparacion < 0)
        {
            fread(&empleado,sizeof(t_empleado), 1, fpEmpleado);
        }
        else
        {
            fread(&estudiante,sizeof(t_estudiante), 1, fpEstudiante);
        }

    }
    fclose(fpEmpleado);
    fclose(fpEstudiante);

    pfr = fopen(EMPLEADOS, "rb");
    if (!pfr)
    {
        return 1;
    }
    fread(&empleado, sizeof(t_empleado), 1, pfr);
    while (!feof(pfr))
    {
        printf("\nDNI %d, %s, %s, Sueldo %f", empleado.dni, empleado.apellido, empleado.nombre, empleado.sueldo);
        fread(&empleado, sizeof(t_empleado), 1, pfr);
    }
    fclose(pfr);

    return 0;
}
