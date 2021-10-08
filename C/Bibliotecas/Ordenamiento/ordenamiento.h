#ifndef ORDENAMIENTO_H_INCLUDED
#define ORDENAMIENTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void ordenarSeleccion(void * vec, size_t ce, size_t tam, int (*cmp)(const void *, const void *));
void * buscarMenor(const void * vec, const void * fin, size_t tam, int (*cmp)(const void *, const void *));


#endif // ORDENAMIENTO_H_INCLUDED
