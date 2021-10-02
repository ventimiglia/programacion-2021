#include <stdio.h>
#include <stdlib.h>

#define TAM 100
#define PATHTXT         "alumnos.txt"
#define PATHTXTVAR      "alumnosVariable.txt"
#define PATHTXTFIJO     "alumnosFijo.txt"
#define PATHBI          "alumnosBinario.dat"

///Escribir archivo texto longitud variable.

///Leerlo
///Crear archivo binario
///Escribir archivo binario
///Leer el archivo binario
///Crear archivo texto longitud fija
///Escribirlo

typedef struct
{
    int d, m, a;
} t_fecha;


typedef struct
{
    int dni;
    char apyn[30];
    char sexo;
    float promedio;
    t_fecha f_ing;
    char estado;
} t_alumno;

int cargarArchivoTextoVariable(char * path);
int leerArchivoTextoVariable(FILE * fp, t_alumno * alumno);
int mostrarArchivoBinario(char * path);

int convertirTxtABin(const char * nombreTexto, const char * nombreBinario, char formato);
int convertirBinATxt(const char * nombreBinario, const char * nombreTexto, char formato);


int main()
{
    cargarArchivoTextoVariable(PATHTXT);

    t_alumno alumno;

    FILE * fpTxtVar = fopen(PATHTXT, "rt");
    FILE * fpBi = fopen(PATHBI, "wb");

    if(!fpTxtVar)
    {
        return 1;
    }

    if(!fpBi)
    {
        fclose(fpTxtVar);
        return 1;
    }


    while(leerArchivoTextoVariable(fpTxtVar, &alumno))
    {

        fwrite(&alumno,sizeof(t_alumno), 1, fpBi);
    }

    fclose(fpTxtVar);
    fclose(fpBi);

    convertirBinATxt(PATHBI, PATHTXTFIJO, 'F');

    convertirTxtABin(PATHTXTFIJO, PATHBI, 'F');
//
//    mostrarArchivoBinario(PATHBI);
    convertirBinATxt(PATHBI, PATHTXTVAR, 'V');

    return 0;
}

int cargarArchivoTextoVariable(char * path)
{
    int i;
    t_alumno alu_vec[] =
    {
        {90, "Sa, Lia", 'F', 7.5,{1,2,2005}, 'A'},
        {98, "Jose Perez", 'M', 8, {1,2,1999}, 'A'},
        {110, "Alumno uno", 'F', 7.5, {1,2,2005}, 'I'},
        {120, "Alumno dos", 'M', 7.5, {1,2,2015}, 'A'},
        {130, "Alumno tres", 'M', 8, {1,2,2000}, 'A'},
        {140, "Alumno cuatro", 'F', 7.5, {1,2,1998}, 'A'},
        {150, "Alumno cinco", 'F', 4, {1,2,1997}, 'A'},
    };
    FILE * fp = fopen(path, "wt");
    if(!fp)
        return 1;

    for(i = 0; i < 7; i++)
    {
        fprintf(fp, "%d|%s|%c|%.2f|%02d/%02d/%4d|%c\n",
                alu_vec[i].dni,
                alu_vec[i].apyn,
                alu_vec[i].sexo,
                alu_vec[i].promedio,
                alu_vec[i].f_ing.d,
                alu_vec[i].f_ing.m,
                alu_vec[i].f_ing.a,
                alu_vec[i].estado);
    }
    fclose(fp);
    return 0;
}

int leerArchivoTextoVariable(FILE * fp, t_alumno * alumno)
{
    return fscanf(fp, "%d|%[^|\n]|%c|%f|%d/%d/%d|%c",
                  &alumno->dni,
                  alumno->apyn,
                  &alumno->sexo,
                  &alumno->promedio,
                  &alumno->f_ing.d,
                  &alumno->f_ing.m,
                  &alumno->f_ing.a,
                  &alumno->estado) == 8;
}

int mostrarArchivoBinario(char * path)
{
    t_alumno alumnito;
    FILE * fp = fopen(path, "rb");

    if(!fp)
        return -2;

    fread(&alumnito, sizeof(t_alumno), 1, fp);

    while(!feof(fp))
    {
        printf("%d|%s|%c|%.2f|%02d/%02d/%4d|%c\n",
               alumnito.dni,
               alumnito.apyn,
               alumnito.sexo,
               alumnito.promedio,
               alumnito.f_ing.d,
               alumnito.f_ing.m,
               alumnito.f_ing.a,
               alumnito.estado);
        fread(&alumnito, sizeof(t_alumno), 1, fp);
    }
    fclose(fp);

    return 1;
}

int convertirBinATxt(const char * nombreBinario, const char * nombreTexto, char formato)
{
    FILE * fpBin = fopen(nombreBinario, "rb");
    FILE * fpTxt = fopen(nombreTexto, "wt");

    if(!fpBin || !fpTxt)
    {
        return -1;
    }

    const char* formatoPrint = formato == 'F' ?
                               "%08d%-29s%c%04.2f%02d%02d%4d%c\n" : "%d|%s|%c|%.2f|%02d/%02d/%4d|%c\n";

    t_alumno alumno;

    fread(&alumno, sizeof(t_alumno), 1, fpBin);

    while(!feof(fpBin))
    {
        fprintf(fpTxt, formatoPrint,
                alumno.dni,
                alumno.apyn,
                alumno.sexo,
                alumno.promedio,
                alumno.f_ing.d,
                alumno.f_ing.m,
                alumno.f_ing.a,
                alumno.estado);
        fread(&alumno, sizeof(t_alumno), 1, fpBin);
    }
    fclose(fpTxt);
    fclose(fpBin);

    return 0;
}

int convertirTxtABin(const char * nombreTexto, const char * nombreBinario, char formato)
{
    FILE * fpTxt = fopen(nombreTexto, "rt");
    FILE * fpBin = fopen(nombreBinario, "wb");

    if(!fpTxt || !fpBin)
    {
        return -1;
    }

    const char* formatoPrint = formato == 'F' ?
                               "%8d%29[^\n]%c%4f%2d%2d%4d%c\n" : "%d|%[^|\n]|%c|%f|%d/%d/%d|%c\n";

    t_alumno alumno;

    fscanf(fpTxt,formatoPrint,
           &alumno.dni,
           alumno.apyn,
           &alumno.sexo,
           &alumno.promedio,
            &alumno.f_ing.d,
           &alumno.f_ing.m,
           &alumno.f_ing.a,
           &alumno.estado);

    while(!feof(fpTxt))
    {
        fwrite(&alumno, sizeof(t_alumno), 1, fpBin);
        fscanf(fpTxt,formatoPrint,
               &alumno.dni,
               alumno.apyn,
               &alumno.sexo,
               &alumno.promedio,
               &alumno.f_ing.d,
               &alumno.f_ing.m,
               &alumno.f_ing.a,
               &alumno.estado);
    }

    fclose(fpTxt);
    fclose(fpBin);

    return 0;
}


