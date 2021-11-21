#include <stdio.h>
#include <stdlib.h>
#include <utilitarias.h>
#include <varias.h>
#include <arbol.h>

#define PATH_ARCH_ALUMNOS "../archivos/alumnos.dat"
#define PATH_ARCH_INDICE "../archivos/alumnos.idx"

void imprimir_mensaje(int res);
void op_alta(FILE * arch, t_arbol * pindice);
void op_baja(FILE * arch, t_arbol * pindice);
void op_agregar_materia(FILE * arch, t_arbol * pindice);
void op_listar_indice(t_arbol * pindice);
void op_listar_alumnos(FILE * arch);
void op_listar_alumnos_ordenado(FILE * arch, t_arbol * pindice);
void op_eliminar_ultimo_ingresado(FILE * arch, t_arbol * pindice);
void op_compactar_y_reindexar(FILE ** arch, t_arbol * pindice, const char * path);

int main()
{
    FILE * arch = fopen(PATH_ARCH_ALUMNOS, "r+b");
    const char opciones [][TAM_MENU] = {"ABEILMUCS",
                                        "Alta",
                                        "Baja",
                                        "Agregar Materia",
                                        "Listar Indice",
                                        "Listar Alumnos",
                                        "Listar Alumnos Ordenado por DNI",
                                        "Eliminar el ultimo ingresado",
                                        "Compactar Archivo y Reindexar",
                                        "Salir"};
    char op;
    if (!arch)
        exit(1);
    t_arbol indice;
    crear_arbol_res(&indice);

    if(cargar_arbol_de_archivo_ordenado(&indice, PATH_ARCH_INDICE)==ERROR_ARCHIVO) ///HECHA POR MI, FUNCIONA SI SE COMPACTA
        exit(1);
    do{
        op=menu(opciones, "Menu Principal");
        switch (op)
        {
            case 'A':
                op_alta(arch, &indice);
                break;
            case 'B':
                op_baja(arch, &indice);
                break;
            case 'E':
                op_agregar_materia(arch, &indice);
                break;
            case 'I':
                op_listar_indice(&indice);
                break;
            case 'L':
                op_listar_alumnos(arch);
                break;
            case 'M':
                op_listar_alumnos_ordenado(arch, &indice);
                break;
            case 'U':
                op_eliminar_ultimo_ingresado(arch, &indice);
                break;
            case 'C':
                op_compactar_y_reindexar(&arch, &indice, PATH_ARCH_ALUMNOS);
                break;
        }
    }while(op!='S');
    grabar_arbol_en_archivo_ordenado_res(&indice, PATH_ARCH_INDICE);
    vaciar_arbol_res(&indice);
    fclose(arch);
    return 0;
}

void op_alta(FILE * arch, t_arbol * pindice)
{
    int res;
    t_alumno alu;
    ingresar_alumno_res(&alu);
    res= alta(&alu, arch, pindice);
    imprimir_mensaje(res);
}

void op_baja(FILE * arch, t_arbol * pindice)
{
    int res;
    t_alumno alu;
    ingresar_dni_alumno_res(&alu);
    res= baja_res(&alu, arch, pindice);
    imprimir_mensaje(res);
}

void op_agregar_materia(FILE * arch, t_arbol * pindice)
{
    int res;
    res= agregar_materia_res(arch, pindice);
    imprimir_mensaje(res);
}

void op_listar_indice(t_arbol * pindice)
{
    printf("\n\n");
    arbol_grafico_res(pindice, mostrar_dni_res);
    pausa("\n\n");
}

void op_listar_alumnos(FILE * arch)
{
    printf("\n\n");
    imprimir_archivo_res(arch);
    pausa("\n\n");
}

void op_listar_alumnos_ordenado(FILE * arch, t_arbol * pindice)
{
    printf("\n\n");
    imprimir_archivo_ordenado_res(arch, pindice);
    pausa("\n\n");
}

void op_eliminar_ultimo_ingresado(FILE * arch, t_arbol * pindice)
{
    int res;
    res= baja_ultimo_res(arch, pindice);
    imprimir_mensaje(res);
}

void op_compactar_y_reindexar(FILE ** arch, t_arbol * pindice, const char * path)
{
    int res;
    res= compactar_y_reindexar_res(arch, pindice, path);
    imprimir_mensaje(res);
}

void imprimir_mensaje(int res)
{
    switch(res)
    {
        case TODO_OK: pausa("Operacion realizada correctamente.");
                break;
        case SIN_MEM: pausa("Error de memoria.");
                break;
        case ERROR_ARCHIVO: pausa("Error en el archivo.");
                break;
        case DUPLICADO: pausa("Resgistro duplicado.");
                break;
        case NO_EXISTE: pausa("Resgistro inexistente.");
                break;
    }
}