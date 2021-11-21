#include<utilitarias.h>
#include<string.h>
#include<varias.h>
#include<ctype.h>

int comparar(const t_info*d1,const t_info*d2)
{
    return d1->dni-d2->dni;
}

int cargar_bajas_masiva (t_cola* pc)
{
    t_info_cola tcola;
    t_alumno alu;
    printf("\n ELIJA EL DNI QUE QUIERA ELIMINAR, 0 PARA SALIR");
    ingresar_dni_alumno_res(&alu);
    while(alu.dni!=0)
    {
        tcola=alu.dni;
        printf("\n ELIJA EL DNI QUE QUIERA ELIMINAR, 0 PARA SALIR");
        ingresar_dni_alumno_res(&alu);
        poner_en_cola_res(pc,&tcola);
    }
    return TODO_OK;
}

int baja_masiva (t_arbol* pa, t_cola *pc)
{
    char opc;
    t_info tarbol;
    t_info_cola tcola;
    t_alumno alu;
    while(!cola_vacia_res(pc))
    {
        sacar_de_cola_res(pc,&tcola);
        printf("\n QUIERE ELIMINAR EL DNI %d? S/N: ",tcola);
        scanf("%s",&opc);
        alu.dni=tcola;
        tarbol.dni=tcola;
        if(opc=='S' || opc=='s')
        {
            if(buscar_en_arbol_bin_busq_res(pa,&tarbol,comparar)==FALSO)
            {
                printf("\nAlUMNO NO ENCONTRADO\n");
            }
            else
            {
                eliminar_de_arbol_res(pa,&tarbol,comparar);
                printf("\nALUMNO ELIMINADO\n");
                imprimir_alumno_res(&alu,(void*)&tarbol); ///IMPRIME MAL
            }
        }
        else if(opc=='N' || opc=='n')
        {
            if(!buscar_en_arbol_bin_busq_res(pa,&tarbol,comparar))
            {
                printf("\nAlUMNO NO ENCONTRADO\n");
            }
            else
            {
                printf("\nALUMNO NO ELIMINADO\n");
                imprimir_alumno_res(&alu,(void*)&tarbol); ///COMO HAGO PARA QUE IMPRIMA TODO BIEN?
            }
        }
    }
    return TODO_OK;
}

void imprimir_listado (const t_arbol * pa)
{
    if(*pa==NULL)
        return;
    imprimir_listado(&(*pa)->pizq);
    mostrar_alumno(pa);
    imprimir_listado(&(*pa)->pder);
}

void mostrar_alumno(const t_arbol*pa)
{
    float promedio,notastotal=0;
    int i;
    printf("DNI: %d\n",(*pa)->info.dni);
    printf("Apellido y Nombre: %s\n",(*pa)->info.apyn);
    printf("Notas: ");
    for(i=0; i<(*pa)->info.cant_materias; i++)
    {
        printf("%d\t",(*pa)->info.notas[i]);
        notastotal+=(*pa)->info.notas[i];
    }
    promedio=notastotal/(*pa)->info.cant_materias;
    printf("\nPromedio: %.2f\n",promedio);
}
