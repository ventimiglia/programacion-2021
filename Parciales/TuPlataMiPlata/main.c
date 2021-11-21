#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TuPlataMiPlata.h"
#include "../../C/Bibliotecas/PilaEstatica/PilaEstatica.h"

///cuentas.dat tiene el estado de las cuentas y es actualizado por movimientos
///No tiene cuentas invalidas

///movimientos.txt tiene los movimientos
///D => restar saldo
///C => sumar el saldo
///Pueden venir numeros de cuenta invalidos que se deben almacenar en "error_nro_cta.txt" se ordena por NUM DE CUENTA descendente
///Se debe almacenar como numero de cuenta erroneo, tabulación, numero correcto



///Ambos archivos ordenados por NUMERO DE CUENTA de manera ascendente

///NUMERO DE CUENTA : SECUENCIAL 6 DIGITOS
///AL FINAL TIENE UN DIGITO VERIFICADOR PRECEDIDO POR UNA BARRA

///VERIFICACIÓN
///NUMERO 637043
///SE DEBEN JUNTAR LOS NUMEROS QUE ESTEN EN LA POSIÓN PAR Y LOS IMPARES PARAR RESTARLOS
/// 674 - 303 = 371
/// Y A LA RESPUESTA SUMAR CADA DIGITO Y ASI SUCESIVAMENTRE HASTA QUE QUEDE SOLO UN DIGITO
/// 3 + 7 + 1 = 11
/// 1 + 1 = 2
///2 SERIA EL VERIFICADOR
///637043/2



int main()
{

    prepararArchivos();

    FILE * fmov = fopen(ARCHIVO_MOVIMIENTOS, "rt");
    FILE * fcuentas = fopen(ARCHIVO_CUENTAS, "r+b");

    tMovimiento movimiento;
    tCuenta cuentas;

    fread(&cuentas, sizeof(cuentas),1,fcuentas);


    while(leerMovimiento(fmov, &movimiento))
    {
        if(validarNumCuenta(movimiento.numeroCuenta))
        {

            if(strcmp(movimiento.numeroCuenta, cuentas.numeroCuenta) == 0)
            {
                cuentas.saldo = movimiento.tipo == 'D' ? cuentas.saldo - movimiento.monto : cuentas.saldo + movimiento.monto;
                fseek(fcuentas, -1L*(sizeof(tCuenta)), SEEK_CUR);
                fwrite(&cuentas, sizeof(tCuenta), 1, fcuentas);
                fseek(fcuentas, 0, SEEK_CUR);
            }

            if(strcmp(movimiento.numeroCuenta, cuentas.numeroCuenta) < 0)
            {
                fread()
            }


        }
        else
        {
            /// guardar en pila la info
            /// guardar en el archivo
        }
        fread(&cuentas, sizeof(cuentas),1,fcuentas);
    }

    fclose(fmov);
    fclose(fcuentas);

    return 0;
}

int leerMovimiento(FILE * fmov, tMovimiento * mov)
{
    return fscanf(fmov, "%[^|\n]|%f|%c",
                  mov->numeroCuenta,
                  &mov->monto,
                  &mov->tipo) == 3;
}

int validarNumCuenta(char * numCuenta)
{
    int i = 0;

    char * codigoVerificador = strrchr(numCuenta, '/') + 1;

    tPila pilaPar, pilaImpar;

    crear_pila(&pilaPar);
    crear_pila(&pilaImpar);



    while(*numCuenta != '/')
    {
        if(i % 2 == 0)
        {
            poner_en_pila(&pilaPar, numCuenta, sizeof(char));
        }
        else
        {
            poner_en_pila(&pilaImpar, numCuenta, sizeof(char));
        }
        i++;
        numCuenta++;
    }


    int calculoCodVer = obtenerCodigoValidacion(&pilaPar, &pilaImpar);

    return calculoCodVer == (*codigoVerificador - '0');
}

int obtenerCodigoValidacion(tPila * pilaPar, tPila * pilaImpar)
{
    char minuendo, sustraendo;
    int minuendoNumero,sustraendoNumero, resultado = 0, borrow = 0;

    while(!pila_vacia(pilaPar) && !pila_vacia(pilaImpar))
    {
        sacar_de_pila(pilaPar, &minuendo, sizeof(char));
        sacar_de_pila(pilaImpar, &sustraendo, sizeof(char));

        minuendoNumero = minuendo - '0';
        sustraendoNumero = sustraendo - '0';

        minuendoNumero = minuendoNumero - borrow;

        borrow = minuendoNumero < sustraendoNumero ? 1 : 0;

        minuendoNumero = borrow ? minuendoNumero * 10 : minuendoNumero;

        resultado = resultado + (minuendoNumero - sustraendoNumero);
    }

    return (resultado / 10 + resultado % 10);
}
