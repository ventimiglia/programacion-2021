#include<utilitarias.h>
#include<string.h>
#include<varias.h>

int comparacion(const t_info* dato1, const t_info* dato2);

int alta (t_alumno * alu, FILE * arch, t_arbol* pa)
{
    t_reg_ind dato;
    fseek(arch,0L,SEEK_END);
    dato.nro_reg=(ftell(arch)/sizeof(t_alumno))-1;
    dato.dni=alu->dni;
    if((insertar_en_arbol_bin_busq(pa,&dato,comparacion))!=TODO_OK)
        return DUPLICADO;
    fwrite(alu,sizeof(t_alumno),1,arch);
    return TODO_OK;
}
