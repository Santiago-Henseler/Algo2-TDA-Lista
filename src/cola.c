#include "cola.h"
#include "auxiliares.h"

struct _cola_t
{
	nodo_t *nodo_inicio;
	int cant_nodos;
};

cola_t *cola_crear()
{

	struct _cola_t *nueva_cola = NULL;

	return constructor(nueva_cola);
}

cola_t *cola_encolar(cola_t *cola, void *elemento)
{
	
	if(cola == NULL)
		return NULL;

	nodo_t *nodo = nuevo_nodo(elemento);

	if(nodo == NULL)
		return NULL;

	if(cola_vacia(cola)){
		cola->nodo_inicio = nodo;
		cola->nodo_inicio->siguiente = NULL;
	}else{
		nodo_t *aux = cola->nodo_inicio;
		cola->nodo_inicio = nodo;
		cola->nodo_inicio->siguiente = aux; 
	}

	cola->cant_nodos++;
	return cola;
}

void *cola_desencolar(cola_t *cola)
{
	
	if(cola_vacia(cola))
		return NULL;

	nodo_t *nodo_borrado = cola->nodo_inicio;

	if(cola->cant_nodos == 1){
		cola->nodo_inicio = NULL;
	}else{
		nodo_t * aux = cola->nodo_inicio->siguiente;
		cola->nodo_inicio = aux;
	}

	cola->cant_nodos--;
	return nodo_borrado->elemento;
}

void *cola_frente(cola_t *cola)
{
	if(cola_vacia(cola))
		return NULL;

	return first(cola->nodo_inicio);
}

size_t cola_tamanio(cola_t *cola)
{
	return size(cola, cola->cant_nodos);
}

bool cola_vacia(cola_t *cola)
{
	return is_empty(cola, cola->cant_nodos);
}

void cola_destruir(cola_t *cola)
{
}
