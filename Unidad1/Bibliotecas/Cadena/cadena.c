char* _strstr(const char *s1, const char *s2);

int cuantas_veces_aparece(const char *texto, const char *palabra)
{
    char aux[TAM], *paux=aux;
    int i;

    while(*texto != '.' && *texto != ' ')
    {
        *paux = *texto;
        paux++;
        texto++;
        i++;
    }
    *paux='\0';
    paux -= i*sizeof(char);

    texto++;
}
