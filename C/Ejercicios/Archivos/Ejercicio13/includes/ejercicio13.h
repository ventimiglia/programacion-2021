#ifndef EJERCICIO13_H_INCLUDED
#define EJERCICIO13_H_INCLUDED

#define EMPLEADOS   "empleados.dat"
#define ESTUDIANTES "estudiantes.dat"
#define AUMENTO     1.0728

typedef struct
{
    int dni;
    char apellido[30];
    char nombre[30];
    double sueldo;
} t_empleado;

typedef struct
{
    int dni;
    char apellido[30];
    char nombre[30];
    float promedio;
} t_estudiante;

int cargarArchivoEstudiante(char* nombreArchivo);
int cargarArchivoEmpleado(char* nombreArchivo);

#endif // EJERCICIO13_H_INCLUDED
