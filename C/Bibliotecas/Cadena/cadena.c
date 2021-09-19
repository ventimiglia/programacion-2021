#include <stddef.h>
#include "cadena.h"

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

char* _strrev(char *s)
{
    int len, i;
    char *start, *end, temp;

    len = _strlen (s);
    start = s;
    end = s + len;

    for (i = 0; i < len - 1; i++)
    {
        temp = *end;
        *end = *start;
        *start = temp;

        start++;
        end--;
    }
    return (char *)end;
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
    char* r = (char *)NULL;
    while(*s)
    {
        if(*s == c)
            r = (char *)s;
        s++;
    }
    return (char *)r;
}

char* _removeDoubleSpaces(char *s)
{
    char * aux = _strstr(s, "  ");
    while(aux)
    {
        _strcpy(aux, aux + 1);
        aux = _strstr(s, "  ");
    }
    return s;
}

char * _trim(char * s)
{
    if(*s == ' ')
    {
        _strcpy(s,s + 1);
    }
    if(*(s + _strlen(s)-1) == ' ')
    {
        *(s + _strlen(s)-1) = '\0';
    }

    return s;
}


char* _capitalize(char *s)
{
    int esPrincipio = 1;
    while(*s)
    {
        if(esPrincipio || *(s - 1) == ' ')
        {
            *s = TO_UPPER(*s);
            esPrincipio = 0;
        }
        else if(ES_LETRA(*s))
        {
            *s = TO_LOWER(*s);
        }
        s++;
    }
    return s;
}

int _strncmp(const char *s1, const char *s2, int n)
{
    while((*s1 == *s2) && (n > 0) && *s1 && *s2)
    {
        s1++;
        s2++;
        n--;
    }
    if(!n)
        return 0;
    if(*s1 < *s2)
        return -1;
    return 1;
}

char* _strstr(const char *s1, const char *s2)
{
    int tam_sub = _strlen(s2);

    if (!tam_sub)
        return (char*)s1;

    while (*s1 && _strncmp(s1,s2,tam_sub))
    {
        s1++;
    }
    return *s1 ? (char*)s1:NULL;
}

char* _strcpy(char *s1, const char *s2)
{
    char * origen = s1;
    while(*s2 && *s1)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return origen;
}


