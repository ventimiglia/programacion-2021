//#include "../../Bibliotecas/Matematica/matematica.h"
//double factorial(double number)
//{
//    if(number == 0 || number == 1)
//    {
//        return 1;
//    }
//    return number * factorial(number - 1);
//}
//
//double potencia (int base, int exponente)
//{
//    int i;
//    double respuesta=1;
//    if(exponente < 0)
//    {
//        printf("No se aceptan valores negativos");
//        return -1;
//    }
//    if(exponente == 0)
//    {
//        return 1;
//    }
//
//    for(i = 1; i<=exponente; i++)
//    {
//        respuesta*=base;
//    }
//    return respuesta;
//}
//
//double exponencial_e (int n, float TOL)
//{
//    int i;
//    double resultado_e = 1, resultado_anterior=0;
//
//
//    for(i = 0; resultado_e - resultado_anterior >= TOL; i++)
//    {
//        resultado_anterior=resultado_e;
//        resultado_e += potencia(n,i) / factorial(i);
//    }
//}
//
//double raiz_cuadrada(int n, float TOL)
//{
//    double rest=1, rest_ant=0;
//
//    while(fabs(rest - rest_ant) > TOL)
//    {
//        rest_ant=rest;
//        rest = (float)1/2*(rest_ant+(n/rest_ant));
//    }
//    return rest;
//}
//
//int fibonacci (int num)
//{
//    int num1 = 1, num2= 1;
//    int aux=1;
//    int n;
//
//    while(aux =! num || aux < num)
//    {
//        aux = num1 + num2;
//        num2 = num1;
//        num1 = aux;
//    }
//    if(num1 == num)
//    {
//        return 1;
//    }
//    return 0;
//}
//
//float seno (int x, float TOL)
//{
//    float rest=1, rest_ant=0;
//    int i;
//
//    for(i=0; fabs(rest- rest_ant > TOL); i++)
//    {
//        rest = potencia(x,2*i+1) / factorial(2*i+1);
//
//        if(i%2 == 0)
//        {
//            rest_ant+=rest;
//        }
//        else
//        {
//            rest_ant-=rest;
//        }
//    }
//    return rest;
//}
