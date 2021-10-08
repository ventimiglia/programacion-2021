#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

void triangulo_der(int mat[][TAM], int ord)
{
    int i, j, inij;
    for(i = 0; i < ord; i++)
    {
        inij = MAYOR(ord-i-1, i);
        printf("\n%*s", (5*inij), "");
        for(j = inij; j < ord; j++)
        {
            printf("%5d", mat[i][j]);
        }
    }
}

void debajo_diag_ppal(int mat[][TAM], int ord)
{
    int i, j;
    for(i = 1; i<ord, i++)
    {
        for(j = 0; j < )
    }
}

#endif // MATRICES_H_INCLUDED
