#include<stdlib.h>
#include<cola.h>

int sacar_de_cola(t_cola*pc,t_info_cola*d)
{
    if(*pc==NULL)
        return 0;
    t_nodo*sacar_nodo=(*pc)->psig;
    *d=sacar_nodo->info;
    if((*pc)==sacar_nodo)
        *pc=NULL;
    else
        (*pc)->psig=sacar_nodo->psig;
    free(sacar_nodo);
    return TODO_OK;
}
