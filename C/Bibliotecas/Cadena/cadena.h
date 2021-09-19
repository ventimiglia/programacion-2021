#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#define ES_DIGITO( X ) ((X) >= '0' && (X)<= '9')
#define ES_MAYUSC( X ) ( ( X ) >= 'A' && ( X ) <= 'Z' )
#define ES_MINUSC( X ) ( ( X ) >= 'a' && ( X ) <= 'z' )
#define TO_UPPER( X ) ( ES_MINUSC( X ) ? ( X ) - ('a' - 'A') : (X) )
#define TO_LOWER( X ) ( ES_MAYUSC( X ) ? ( X ) + ('a' - 'A') : (X) )
#define ES_LETRA( X ) ( ES_MAYUSC( X ) || ES_MINUSC( X ) )


//char* _strstr(const char *s1, const char *s2);

int     _strlen     (const char *s);
int     _strncmp    (const char *s1, const char *s2, int n);
char*   _strrev     (char *s);
char*   strchr      (const char *cadena, int c);
char*   _strrchr    (const char *s, int c);
char*   _removeDoubleSpaces (char *s);
char*   _trim       (char *s);
char*   _capitalize (char *s);
char*   _strstr     (const char *s1, const char *s2);
char*   _strcpy(char *s1, const char *s2);

#endif // CADENA_H_INCLUDED
