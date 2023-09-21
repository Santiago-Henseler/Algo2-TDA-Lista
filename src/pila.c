#include "pila.h"
#include "lista.h"
#include "auxiliares.h"
#include <stdio.h>

struct _pila_t {
	nodo_t *nodo_inicio;
	size_t cant_nodos;
	nodo_t *nodo_fin;
};

pila_t *pila_crear()
{
	return (pila_t *)lista_crear();
}

pila_t *pila_apilar(pila_t *pila, void *elemento)
{
	return (pila_t *)lista_insertar((lista_t *)pila, elemento);
}

void *pila_desapilar(pila_t *pila)
{
	return lista_quitar((lista_t *)pila);
}

void *pila_tope(pila_t *pila)
{
	return lista_ultimo((lista_t *)pila);
}

size_t pila_tamanio(pila_t *pila)
{
	return lista_tamanio((lista_t *)pila);
}

bool pila_vacia(pila_t *pila)
{
	return lista_vacia((lista_t *)pila);
}

void pila_destruir(pila_t *pila)
{
	lista_destruir((lista_t *)pila);
}
