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

void *constructor(void * estructura);

void *first(nodo_t *nodo);

bool is_empty(void *estructura, int cant_nodos);

size_t size(void* estructura, int cant_nodos);

#endif /* __ AUXILIARES_H__*/