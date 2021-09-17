#include <stddef.h>
#include <string.h>
#include "cadena.h"

//char* _strstr(const char *s1, const char *s2);
//
//int cuantas_veces_aparece(const char *texto, const char *palabra)
//{
//    char aux[TAM], *paux=aux;
//    int i;
//
//    while(*texto != '.' && *texto != ' ')
//    {
//        *paux = *texto;
//        paux++;
//        texto++;
//        i++;
//    }
//    *paux='\0';
//    paux -= i*sizeof(char);
//
//    texto++;
//}

int _strlen(const char *s)
{
    int count = 0;

    while(*s)
    {
        count++;
        s++;
    }
    return count;
}

char* _strrev(char *cadena)
{
    int len, i;
    char *start, *end, temp;

    len = _strlen (cadena);
    start = cadena;
    end = cadena + len;

    for (i = 0; i < len - 1; i++)
    {
        temp = *end;
        *end = *start;
        *start = temp;

        start++;
        end--;
    }
    return end;
}

char* _strchr(const char *cadena, int c)
{
    while(*cadena && *cadena != c)
    {
        cadena++;
    }
    return (char*) (*cadena ? cadena : NULL);
    ///Lo castea, esto intenta convertirlo a otro tipo de dato, lo
    ///lo convierte de constante a no constante.
}

char* _strrchr(const char *s, int c)
{
    char* r = NULL;
    while(*s)
    {
        if(*s == c)
            r = s;
        s++;
    }
    return (char *)r;
}

char* _removeDoubleSpaces(char *s)
{
    char * aux = strstr(s, "  ");
    while(aux)
    {
        strcpy(aux, aux + 1);
        aux = strstr(s, "  ");
    }
    return s;
}

char * _trim(char * s)
{
    if(*s == ' ')
    {
        strcpy(s,s + 1);
    }
    if(*(s + strlen(s)-1) == ' ')
    {
        *(s + strlen(s)-1) = '\0';
    }

    return s;
}

char* _capitalize(char *s)
{
    while(*s)
    {
        *s = TO_UPPER(*s);
        s++;
        while(*s != ' ')
        {
            *s = TO_LOWER(*s);
            s++;
        }
    }
    return s;
}

