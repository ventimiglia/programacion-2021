#include "funciones.h"

char* reemplazarUnacadena(char* cad,char*reemplazo,char*buscar)
{
    char*p_buscar=buscar,*p_reemplazo=reemplazo;
    char*p_cad1=cad,*auxcad=cad;
    char*p_ver=cad;
    int band=0;
    while(*cad)
    {
        p_cad1=cad;
        while(*cad==*p_buscar && *cad!='\0')
        {
            cad++;
            p_buscar++;
        }
        if(*p_buscar=='\0')
        {
            auxcad=p_cad1;
            while(*p_reemplazo)
            {
                *p_cad1=*p_reemplazo;
                p_reemplazo++;
                if(band==1 && p_cad1==cad)
                {
                cad++;
                p_cad1++;
                }else
                    p_cad1++;
                if(band==0 && p_cad1==cad && *p_reemplazo!='\0')
                {
                    band=1;
                    while(*p_cad1)
                    {
                        p_cad1++;
                        cad++;
                    }
                    while(*p_reemplazo)
                    {
                        cad++;
                        p_reemplazo++;
                    }
                    p_reemplazo=reemplazo;
                    while(p_cad1!=auxcad)
                    {
                        *cad=*p_cad1;
                        p_cad1--;
                        cad--;
                    }
                }
            }
            band=0;
            p_reemplazo=reemplazo;
            if(p_cad1!=cad)
            {
                auxcad=cad;
                while(*p_cad1)
                {
                    *p_cad1=*cad;
                    p_cad1++;
                    cad++;
                }
                cad=auxcad;
            }
        }
        cad++;
        p_buscar=buscar;
    }
    *cad='\0';
    return p_ver;
}
