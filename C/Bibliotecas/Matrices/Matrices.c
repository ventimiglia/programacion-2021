#include <stdio.h>
#include "Matrices.h"

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

void triangulo_sup(int mat[][TAM], int ord)
{
    int i,j;
    for(i = 0; i<(ord / 2); i ++)
    {
        printf("%*s",3*i, "");
        for(j = i + 1; j < ord - 1 - i; j++)
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}

void debajo_diag_ppal(int mat[][TAM], int ord)
{
    int i, j;
    for(i = 1; i<ord; i++)
    {
        for(j = 0; j < i; j++ )
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}

void debajo_diag_sdria(int mat[][TAM], int ord)
{
    int i,j;
    for(i = 1; i< ord; i++)
    {
        printf("%*s",3*(ord - i), "");

        for(j = ord - i; j<ord ; j++)
        {
            printf("%3d", mat[i][j]);
        }
            printf("\n");
    }
}

void arriba_diag_sdria(int mat[][TAM], int ord)
{
    int i,j;
    for(i = 0; i< ord; i++)
    {
        for(j = 0; j<ord - i - 1 ; j++)
        {
            printf("%3d", mat[i][j]);
        }
            printf("\n");
    }
}

void arriba_diag_ppal(int mat[][TAM], int ord)
{
    int i,j;
    for(i = 0; i< ord; i++)
    {
        printf("%*s",3*i,"");
        for(j = i + 1; j<ord; j++)
        {
            printf("%3d", mat[i][j]);
        }
            printf("\n");
    }
}

void transpuesta(int mat[][TAM], int ord)
{
    int i,j;
    for(j = 0; j<ord; j++)
    {
        for(i = 0; i<ord; i++)
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}

void transpuesta_centro(int mat[][TAM], int ord)
{
    int i,j;
    for(i = ord - 1; i >= 0; i--)
    {
        for(j = ord - 1; j>=0; j--)
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}

//void triangulo_inf(int mat[][TAM], int ord)
//{
//    int i,j, inicioj=0;
//    for(i = ord /2 + 1; i < ord; i++)
//    {
//        printf("%*s",3*(ord - i - 1),"");
//        for(j = ord/2 - inicioj; j<i; j++)
//        {
//            printf("%3d",mat[i][j]);
//        }
//        inicioj++;
//        printf("\n");
//    }
//}

void triangulo_izq(int mat[][TAM], int ord)
{
    int i,j, inicioj;
    for(i=1; i<ord-1; i++)
    {
        inicioj = MENOR(i,ord-i-1);
        for(j=0; j<inicioj; j++)
        {
            printf("%3d",mat[i][j]);
        }
        printf("\n");
    }

}

void triangulo_inf(int mat[][TAM], int ord)
{
    int i,j;
    for(i = (ord / 2) + 1; i<ord; i ++)
    {
        printf("%*s",3*(ord - i - 1),"");
        for(j = ord - i; j < i; j++)
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}

void primer_cuadrante(int mat[][TAM], int ord)
{
    int i,j;
    for(i = 0; i < ord / 2; i++)
    {
        for(j = ord / 2; j < ord; j++)
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}
