#include "auxiliares.h"

nodo_t *posicion_nodo(nodo_t *nodo, int posicion){

	if(posicion == 1)
		return nodo;

	return posicion_nodo(nodo->siguiente, posicion-1);
}

nodo_t *nuevo_nodo(void *elemento){

    nodo_t* nodo = calloc(1, sizeof(nodo_t));
	
    if (nodo == NULL)
        return NULL;

    nodo->elemento = elemento;

    return nodo;
}

void *constructor(void * estructura){

	void *nueva_estructura = calloc(1, sizeof(estructura));

	if(nueva_estructura == NULL){
		return NULL;
	}

	return nueva_estructura;
}

void *first(nodo_t *nodo){
	return nodo->elemento;
}

bool is_empty(void *estructura, int cant_nodos){
	if(estructura == NULL || cant_nodos == 0)
		return true;
	return false;
}

size_t size(void* estructura, int cant_nodos){
	if(is_empty(estructura, cant_nodos))
		return 0;

	return (long unsigned int)cant_nodos;
}
