#ifndef __AUXILIARES_H__
#define __AUXILIARES_H__

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct nodo {
	void *elemento;
	struct nodo *siguiente;
} nodo_t;

nodo_t *posicion_nodo(nodo_t *nodo, int posicion);

nodo_t *nuevo_nodo(void *elemento);

#endif /* __ AUXILIARES_H__*/