#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <Tipos.h>


typedef struct s_nodo_arbol
{
	t_info info; /** El tipo definido en Dato.h **/
	struct s_nodo_arbol* pizq;
	struct s_nodo_arbol* pder;
}
t_nodo_arbol;


typedef t_nodo_arbol* t_arbol;

typedef int (*t_cmp)(const t_info*, const t_info*);

typedef void (*t_accion)(t_info* pinfo, void* datos_accion);

typedef void (*t_mostrar_clave)(const t_info *);


void crear_arbol(t_arbol* pa);
void crear_arbol_res(t_arbol* pa);
int insertar_en_arbol_bin_busq(t_arbol* pa, const t_info* pd, int (*cmp)(const t_info*, const t_info*) ); ///Retorna TODO_OK o DUPLICADO o SIN_MEM
int insertar_en_arbol_bin_busq_res(t_arbol* pa, const t_info* pd, int (*cmp)(const t_info*, const t_info*) ); ///Retorna TODO_OK o DUPLICADO o SIN_MEM
int buscar_en_arbol_bin_busq(const t_arbol* pa, t_info* pd, int (*cmp)(const t_info*, const t_info*) ); ///Retorna VERDADERO o FALSO
int buscar_en_arbol_bin_busq_res(const t_arbol* pa, t_info* pd, int (*cmp)(const t_info*, const t_info*) ); ///Retorna VERDADERO o FALSO
int eliminar_de_arbol(t_arbol* pa, t_info* pd, int (*cmp)(const t_info*, const t_info*) ); ///Retorna TODO_OK o NO_EXISTE
int eliminar_de_arbol_res(t_arbol* pa, t_info* pd, int (*cmp)(const t_info*, const t_info*) ); ///Retorna TODO_OK o NO_EXISTE
void eliminar_raiz(t_arbol* pa);
void eliminar_raiz_res(t_arbol* pa);
void recorrer_arbol_pre(const t_arbol* pa, void (*accion)(t_info* pinfo, void* datos_accion), void* datos_accion);
void recorrer_arbol_pre_res(const t_arbol* pa, void (*accion)(t_info* pinfo, void* datos_accion), void* datos_accion);
void recorrer_arbol_en(const t_arbol* pa, void (*accion)(t_info* pinfo, void* datos_accion), void* datos_accion);
void recorrer_arbol_en_res(const t_arbol* pa, void (*accion)(t_info* pinfo, void* datos_accion), void* datos_accion);
void recorrer_arbol_en_it(const t_arbol* pa, void (*accion)(t_info* pinfo, void* datos_accion), void* datos_accion);
void recorrer_arbol_en_it_res(const t_arbol* pa, void (*accion)(t_info* pinfo, void* datos_accion), void* datos_accion);
void recorrer_arbol_pos(const t_arbol* pa, void (*accion)(t_info* pinfo, void* datos_accion), void* datos_accion);
void recorrer_arbol_pos_res(const t_arbol* pa, void (*accion)(t_info* pinfo, void* datos_accion), void* datos_accion);
int cargar_arbol_de_archivo_ordenado(t_arbol* pa, const char* path); ///Retorna TODO_OK, ERROR_ARCHIVO o SIN_MEM
int cargar_arbol_de_archivo_ordenado_res(t_arbol* pa, const char* path); ///Retorna TODO_OK, ERROR_ARCHIVO o SIN_MEM
int grabar_arbol_en_archivo_ordenado(t_arbol* pa, const char* path);
int grabar_arbol_en_archivo_ordenado_res(t_arbol* pa, const char* path);
int altura_arbol(const t_arbol* pa);
int altura_arbol_res(const t_arbol* pa);
void vaciar_arbol(t_arbol* pa);
void vaciar_arbol_res(t_arbol* pa);
void arbol_grafico_res(const t_arbol*, void (*mostrar_clave)(const t_info *));
///void mostrar_clave(const t_info* pinfo);

void arbol_grafico(const t_arbol*, void (*mostrar_clave)(const t_info *));
void arbol_grafico_recur(const t_arbol*, void (*mostrar_clave)(const t_info *),int);
int comparacion_dni (const t_info*,const t_info*);


#endif // ARBOL_H_INCLUDED
