#include <tipos.h>
#include <stdio.h>
#include <stdlib.h>
#include <arbol.h>

void arbol_grafico(const t_arbol *pa,t_mostrar_clave fun)
{
    arbol_grafico_recur(pa,fun,0);
}

void arbol_grafico_recur(const t_arbol *pa,t_mostrar_clave fun,int cant)
{
    int i;
    if(!*pa)
        return;
    arbol_grafico_recur(&(*pa)->pder,fun,cant+1);
    for(i=0;i<cant;i++)
        printf("\t");
    fun(&(*pa)->info);
    printf("\n");
    arbol_grafico_recur(&(*pa)->pizq,fun,cant+1);
}

void vaciar_arbol(t_arbol* pa)
{
    if(!*pa)
        return;
    vaciar_arbol(&(*pa)->pizq);
    vaciar_arbol(&(*pa)->pder);
    free(*pa);
    *pa=NULL;
}

int comparacion_dni (const t_info *pd1,const t_info *pd2)
{
    return pd1->dni-pd2->dni;
}

int insertar_en_arbol_bin_busq(t_arbol* pa, const t_info* pd,t_cmp cmp)
{
    int res;
    if(!*pa)
    {
        *pa=(t_nodo_arbol*)malloc(sizeof(t_nodo_arbol));
        if(!*pa)
            return SIN_MEM;
        (*pa)->info=*pd;
        (*pa)->pder=NULL;
        (*pa)->pizq=NULL;
        return TODO_OK;
    }
    if((res=cmp(pd,&(*pa)->info))>0)
        return insertar_en_arbol_bin_busq(&(*pa)->pder,pd,cmp);
    if(res<0)
        return insertar_en_arbol_bin_busq(&(*pa)->pizq,pd,cmp);
    return DUPLICADO;
}



