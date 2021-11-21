#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#define MAYOR(X,Y)  ((X)>(Y) ? (X) : (Y))
#define MENOR(X,Y)  ((X)<(Y) ? (X) : (Y))
#define TAM     50

void triangulo_der(int mat[][TAM], int ord); ///
void triangulo_sup(int mat[][TAM], int ord); ///
void triangulo_inf(int mat[][TAM], int ord); ///
void triangulo_izq(int mat[][TAM], int ord); ///
void transpuesta(int mat[][TAM], int ord);  ///
void transpuesta_centro(int mat[][TAM], int ord); ///
void multiplicacion(int mat1[][TAM], int ord1, int mat2[][TAM], int ord2);
void suma(int mat1[][TAM], int ord1, int mat2[][TAM], int ord2);
void debajo_diag_ppal(int mat[][TAM], int ord); ///
void debajo_diag_sdria(int mat[][TAM], int ord); ///
void arriba_diag_ppal(int mat[][TAM], int ord); ///
void arriba_diag_sdria(int mat[][TAM], int ord); ///
void primer_cuadrante(int mat[][TAM], int ord);
void segundo_cuadrante(int mat[][TAM], int ord);
void tercer_cuadrante(int mat[][TAM], int ord);
void cuarto_cuadrante(int mat[][TAM], int ord);


#endif // MATRICES_H_INCLUDED
