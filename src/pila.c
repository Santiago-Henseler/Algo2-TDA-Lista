#include "pila.h"
#include "auxiliares.h"

struct _pila_t
{
	nodo_t *nodo_final;
	int cant_nodos;
};

pila_t *pila_crear()
{
	struct _pila_t *nueva_pila = NULL;

	return constructor(nueva_pila);
}

pila_t *pila_apilar(pila_t *pila, void *elemento)
{
	return NULL;
}

void *pila_desapilar(pila_t *pila)
{
	return NULL;
}

void *pila_tope(pila_t *pila)
{
	if(pila == NULL){
		return NULL;
	}

	return pila->nodo_final->elemento;
}

size_t pila_tamanio(pila_t *pila)
{
	return size(pila, pila->cant_nodos);
}

bool pila_vacia(pila_t *pila)
{
	return false;
}

void pila_destruir(pila_t *pila)
{
}
