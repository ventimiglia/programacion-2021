#include <stdio.h>
#include <stdlib.h>

void ordenarSeleccion(void * vec, size_t ce, size_t tam, int (*cmp)(const void *, const void *));

int main()
{
    printf("Hello world!\n");
    return 0;
}

void ordenarSeleccion(void * vec, size_t ce, size_t tam, int (*cmp)(const void *, const void *))
{
    void * fin = vec + (ce-1 * tam),
        * men;

    while(vec<fin)
    {
        men = buscarMenor(vec, fin);
        if(vec!=men)
        {
            intercambiar(vec,man);
        }
        vec += tam;
    }
}

int * buscarMenor(const void * vec, const void * fin, size_t tam, int (*cmp)(const void *, const void *))
{
    const void * men = vec;
    vec+ = tam;
    while(vec <= fin)
    {
        if(cmp(vec,men) < 0)
        {
            men = vec;
        }
        vec+=tam;
    }
    return (void *) men;
}

void intercambiar(void * e1, void * e2, size_t tam)
{
    ///defino un espacio de memoria generico x;
    char aux[1000];
    memcpy(aux, *e1, tam); ///copia memoria
    memcpy(*e1, *e2, tam); ///copia memoria
    memcpy(*e2, aux, tam); ///copia memoria

    ///con memoria dinamica

    void * aux = malloc(tam);

    if(!aux)
        return;
    memcpy(aux, *e1, tam); ///copia memoria
    memcpy(*e1, *e2, tam); ///copia memoria
    memcpy(*e2, aux, tam); ///copia memoria

    free(aux);
}
