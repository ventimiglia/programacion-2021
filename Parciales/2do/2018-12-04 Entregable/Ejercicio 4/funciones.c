#include "funciones.h"

char *mi_strcat_reverso(char* s1, const char *s2)
{
    int len2=my_strlen(s2);
    char* inicio = s1, *fin = my_strlen(s1)+inicio;
    while(fin>=inicio)
    {
        s1=len2+fin;
        *s1=*fin;
        fin--;
    }
    s1=inicio;
    while(*s2)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    return inicio;
}

size_t my_strlen(const char* s)
{
    int cont=0;
    while(*s)
    {
        s++;
        cont++;
    }
    return cont;
}
