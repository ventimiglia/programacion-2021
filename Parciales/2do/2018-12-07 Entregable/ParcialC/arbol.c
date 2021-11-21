#include <tipos.h>
#include <stdio.h>
#include <stdlib.h>
#include <arbol.h>

t_reg_ind cargar_datos(void* arch, int pos); ///propia para cargar_arbol_de_archivo_ordenado
int cargar_arbol_de_archivo_ordenado_recur(t_arbol*, void* dato, int li, int ls, t_info(*obtener_datos)(void*,int));
int comparacion(const t_info* dato1, const t_info* dato2);

int comparacion(const t_info* dato1, const t_info* dato2)
{
    return dato1->dni-dato2->dni;
}

int cargar_arbol_de_archivo_ordenado(t_arbol* pa, const char* path) ///Retorna TODO_OK, ERROR_ARCHIVO o SIN_MEM
{
    int fin, res;
    FILE* pf;
    pf=fopen(path,"rb");
    if(!pf)
        return ERROR_ARCHIVO;
    fseek(pf,0L,SEEK_END);
    fin=(ftell(pf)/sizeof(t_reg_ind));
    res=cargar_arbol_de_archivo_ordenado_recur(pa,pf,0,fin-1,cargar_datos);
    fclose(pf);
    return res;
}

int cargar_arbol_de_archivo_ordenado_recur(t_arbol* pa, void* dato, int li, int ls, t_reg_ind(*cargar_datos)(void*,int))
{
    int medio=(li+ls)/2;
    int result;
    if(li<=ls)
    {
        *pa=(t_nodo_arbol*)malloc(sizeof(t_nodo_arbol));
        if(!*pa)
            return SIN_MEM;
        (*pa)->pder=NULL;
        (*pa)->pizq=NULL;
        (*pa)->info=cargar_datos(dato,medio);
        return TODO_OK;
    }
    result=cargar_arbol_de_archivo_ordenado_recur(&(*pa)->pizq,dato,li,medio-1,cargar_datos);
    if(!result)
        return result;
    return cargar_arbol_de_archivo_ordenado_recur(&(*pa)->pder,dato,medio+1,ls,cargar_datos);
}

t_reg_ind cargar_datos(void* arch, int pos)
{
    t_reg_ind info;
    FILE* pf=(FILE*)arch;
    fseek(pf,sizeof(t_reg_ind)*pos,SEEK_SET);
    fread(&info,sizeof(t_reg_ind),1,pf);
    return info;
}

int insertar_en_arbol_bin_busq(t_arbol* pa, const t_info* pd, int (*cmp)(const t_info*, const t_info*) ) ///Retorna TODO_OK o DUPLICADO o SIN_MEM
{
    int result;
    if(!*pa)
    {
        *pa=(t_nodo_arbol*)malloc(sizeof(t_nodo_arbol));
        if(!*pa)
            return SIN_MEM;
        (*pa)->pder=NULL;
        (*pa)->pizq=NULL;
        (*pa)->info=*pd;
        return TODO_OK;
    }
    if((result=comparacion(pd,&(*pa)->info))>0)
        return insertar_en_arbol_bin_busq(&(*pa)->pder,pd,comparacion);
    if(result<0)
        return insertar_en_arbol_bin_busq(&(*pa)->pizq,pd,comparacion);
    else
        return DUPLICADO;
}

int buscar_en_arbol_bin_busq(const t_arbol* pa, t_info* pd, int (*cmp)(const t_info*, const t_info*) ) ///Retorna VERDADERO o FALSO
{
    int result;
    if(!*pa)
        return VERDADERO;
    if((result=comparacion(pd,&(*pa)->info))>0)
        return buscar_en_arbol_bin_busq(&(*pa)->pder,pd,comparacion);
    if(result<0)
        return buscar_en_arbol_bin_busq(&(*pa)->pizq,pd,comparacion);
    else
        return FALSO;
}
