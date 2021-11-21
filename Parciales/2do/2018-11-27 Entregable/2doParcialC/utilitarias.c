#include<utilitarias.h>
#include<string.h>
#include<varias.h>

void mostrar_dni(const t_reg_ind* r)
{
    printf("%d",r->dni);
}

int compactar_y_reindexar(FILE ** arch, t_arbol *pindice, const char * path)
{
    FILE *pf;
    t_alumno alumno;
    t_info info;
    int nro_reg=0;
    fclose(*arch);
    rename(path,"../archivos/alumnos_viejo.dat");
    *arch=fopen(path,"w+b");
    if(!*arch)
        return ERROR_ARCHIVO;
    pf=fopen("../archivos/alumnos_viejo.dat","rb");
    if(!pf)
        return ERROR_ARCHIVO;
    vaciar_arbol(pindice);
   fread(&alumno,sizeof(alumno),1,pf);
   while (!feof(pf))
   {
       if(alumno.estado=='A')
       {
            fwrite(&alumno,sizeof(t_alumno),1,*arch);
            info.dni=alumno.dni;
            info.nro_reg=nro_reg;
            insertar_en_arbol_bin_busq(pindice,&info,comparacion_dni);
       }
        nro_reg++;
        fread(&alumno,sizeof(alumno),1,pf);
    }
    fclose(pf);
    remove("../archivos/alumnos_viejo.dat");
    return TODO_OK;
}




