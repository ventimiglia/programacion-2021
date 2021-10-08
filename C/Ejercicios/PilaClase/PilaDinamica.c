void crear_pila (tPila * pp)
{
    * pp = NULL;
}

int poner_en_pila(tPila * pp, const void * pd, unsigned tam)
{
    tNodo * nue = (tNodo*) malloc(sizeof(tNodo));

    if(!nue)
    {
        return 0; //PILA LLENA
    }

    if(!nue->info)
    {
        free(nue);
        return 0; //PILA LLENA
    }

    nue->tamInfo = tam;
    nue->sig = *pp;
    memcpy(nue->info, pd, tam);

    *pp = nue;
    return 1;
}

int sacar_de_pila(tPila * pp, void * pd, unsigned tam)
{
    tNodo * elim = *pp;
    if(!*pp)
    {
        return 0;
    }

    memcpy(pd, elim->info, MINIMO(elim->tamInfo, tam));

    *pp = elim->sig;

    free(elim->info);
    free(elim);
    return 1;
}

