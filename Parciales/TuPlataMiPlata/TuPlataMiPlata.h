#ifndef TUPLATAMIPLATA_H_INCLUDED
#define TUPLATAMIPLATA_H_INCLUDED

#define ARCHIVO_MOVIMIENTOS "movimientos.txt"
#define ARCHIVO_CUENTAS     "cuentas.dat"

typedef struct
{
    char numeroCuenta[9];
    float saldo;
} tCuenta;

typedef struct
{
    char numeroCuenta[9];
    float monto;
    char tipo;
} tMovimiento;

void prepararArchivos(void);



#endif // TUPLATAMIPLATA_H_INCLUDED
