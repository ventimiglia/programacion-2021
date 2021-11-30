#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

typedef struct sNodo
{
  void * info;
  unsigned tamInfo;
  struct sNodo * ant;
  struct sNodo * sig;
} tNodoD;

struct tNodoD * tListaD;

void crearLista(tListaD *p);
int vaciarLista(tListaD * p);
int listaVacia(const tListaD *p);
int listaLlena(const tListaD *p);
int insertarAlFinal(tListaD * p, const void *d, unsigned cantBytes);
int insertarAlInicio(tListaD * p, const void *d, unsigned cantBytes);
int mostrarDeIzqADer(const tListaD *p, void (*mostrar)(void *));
int mostrarDeDerAIzq(const tListaD *p, void (*mostrar)(void *));
int insertarEnOrder(tListaD *p, const void *d, unsigned cantBytes, int (*comparar)(const void *, const void *), int (*acumular)(void **, unsigned *, const void *, unsigned));
void ordenarLista(tListad *p, int (*comparar)(const void *, const void *));
int eliminarPorClave(tListaD *p, void *d, unsigned cantBytes, int (*comparar)(const void *, const void *));

#endif // LISTADOBLE_H_INCLUDED
