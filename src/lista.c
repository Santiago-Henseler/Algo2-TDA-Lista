#include "lista.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
	void *elemento;
	struct nodo *siguiente;
} nodo_t;

struct lista {
	nodo_t *nodo_inicio;
	int cant_nodos;
	nodo_t *nodo_fin;
};

struct lista_iterador {
	//y acá?
	int sarasa;
};

nodo_t *posicion_nodo(nodo_t *nodo, int posicion){

	if(posicion == 1)
		return nodo;

	return posicion_nodo(nodo->siguiente, posicion-1);
}

lista_t *lista_crear()
{
	struct lista *nueva_lista = calloc(1, sizeof(struct lista *));

	if(nueva_lista == NULL){
		return NULL;
	}

	return nueva_lista;
}

nodo_t *nuevo_nodo(void *elemento){

    nodo_t* nodo = calloc(1, sizeof(nodo_t));
	
    if (nodo == NULL)
        return NULL;

    nodo->elemento = elemento;

    return nodo;
}

lista_t *lista_insertar(lista_t *lista, void *elemento)
{

	if(lista == NULL)
		return NULL;

	nodo_t *nodo = nuevo_nodo(elemento);

	if(nodo == NULL)
		return NULL;

	if(lista_vacia(lista)){
		lista->nodo_inicio = nodo;
		lista->nodo_fin = nodo;
		lista->nodo_fin->siguiente = NULL;
	}else{
		lista->nodo_fin->siguiente = nodo;
		lista->nodo_fin = nodo;
	}

	return lista;
}

lista_t *lista_insertar_en_posicion(lista_t *lista, void *elemento, size_t posicion)
{
	if(lista == NULL)
		return NULL;

	if(lista->cant_nodos < posicion){
		return lista_insertar(lista, elemento);
	}

	nodo_t *nodo = nuevo_nodo(elemento);

	if(nodo == NULL)
		return NULL;

	nodo_t *nodo_a_mover = posicion_nodo(lista->nodo_inicio, (int)posicion);

	nodo->elemento = elemento;
	nodo->siguiente = nodo_a_mover->siguiente;

	nodo_a_mover->siguiente = nodo;

	return lista;
}

void *lista_quitar(lista_t *lista)
{
	if(lista == NULL)
		return NULL;

	nodo_t *nodo_borrado = lista->nodo_fin;

	nodo_t *nodo_fin = posicion_nodo(lista->nodo_inicio, lista->cant_nodos);

	if(nodo_fin == NULL){
		return NULL;
	}
	
	lista->nodo_fin = nodo_fin;
	lista->nodo_fin->siguiente = NULL;

	return nodo_borrado->elemento;
}

void *lista_quitar_de_posicion(lista_t *lista, size_t posicion)
{
	if(lista == NULL || lista->cant_nodos == 0)
		return NULL;

	if(lista->cant_nodos < posicion){
		return lista_quitar(lista);
	}

	nodo_t *nodo_anterior = posicion_nodo(lista->nodo_inicio, (int)posicion);

	if(nodo_anterior == NULL){
		return NULL;
	}

	nodo_t *nodo_borrado = nodo_anterior->siguiente;

	nodo_anterior->siguiente = nodo_anterior->siguiente->siguiente;

	return nodo_borrado->elemento;
}

void *lista_elemento_en_posicion(lista_t *lista, size_t posicion)
{
	return NULL;
}

void *lista_buscar_elemento(lista_t *lista, int (*comparador)(void *, void *), void *contexto)
{
	return NULL;
}

void *lista_primero(lista_t *lista)
{
	if(lista == NULL || lista_vacia(lista))
		return NULL;

	return lista->nodo_inicio;
}

void *lista_ultimo(lista_t *lista)
{
	if(lista == NULL || lista_vacia(lista))
		return NULL;

	return lista->nodo_fin;
}

bool lista_vacia(lista_t *lista)
{
	if(lista == NULL || lista->cant_nodos == 0)
		return true;
	
	return false;
}

size_t lista_tamanio(lista_t *lista)
{
	/*
	if(lista == NULL)
		return NULL;

	return lista->cant_nodos;*/
	return 0;
}

void lista_destruir(lista_t *lista)
{
}

void lista_destruir_todo(lista_t *lista, void (*funcion)(void *))
{
}

lista_iterador_t *lista_iterador_crear(lista_t *lista)
{
	return NULL;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t *iterador)
{
	return false;
}

bool lista_iterador_avanzar(lista_iterador_t *iterador)
{
	return false;
}

void *lista_iterador_elemento_actual(lista_iterador_t *iterador)
{
	return NULL;
}

void lista_iterador_destruir(lista_iterador_t *iterador)
{
}

size_t lista_con_cada_elemento(lista_t *lista, bool (*funcion)(void *, void *),
			       void *contexto)
{
	return 0;
}
