#include "lista.h"
#include "auxiliares.h"

struct lista {
	nodo_t *nodo_inicio;
	int cant_nodos;
	nodo_t *nodo_fin;
};

struct lista_iterador {
	nodo_t *actual;
};
 
lista_t *lista_crear()
{
	struct lista *nueva_lista = calloc(1, sizeof(sizeof(struct lista )));

	if(nueva_lista == NULL){
		return NULL;
	}

	return nueva_lista;
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
	}else{
		lista->nodo_fin->siguiente = nodo;
		lista->nodo_fin = nodo;
	}

	lista->cant_nodos++;
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

	if(posicion == 0){
		nodo->siguiente = lista->nodo_inicio;
		lista->nodo_inicio = nodo;
	}else{


		nodo_t* actual = lista->nodo_inicio;
		int i = 1;

        while(actual->siguiente && i < posicion){
            actual = actual->siguiente;
            i++;
        }

        nodo->siguiente = actual->siguiente;
        actual->siguiente = nodo;
	}


	lista->cant_nodos++;
	return lista;
}

void *lista_quitar(lista_t *lista)
{
	if(lista == NULL || lista_vacia(lista))
		return NULL;

	nodo_t *nodo_borrado = lista->nodo_fin->elemento;

	nodo_t * ante_ultimo = posicion_nodo(lista->nodo_inicio, lista->cant_nodos-1);

	if(ante_ultimo == NULL){
		return NULL;
	}
	
	lista->nodo_fin = ante_ultimo;
	lista->nodo_fin->siguiente = NULL;

	lista->cant_nodos--;

	return nodo_borrado;

}

void *lista_quitar_de_posicion(lista_t *lista, size_t posicion)
{

	if(lista_vacia(lista))
		return NULL;

	if(lista->cant_nodos < posicion){
		return lista_quitar(lista);
	}

	if(posicion == 0){
		nodo_t * aux = lista->nodo_inicio;
		lista->nodo_inicio = lista->nodo_inicio->siguiente;
		lista->cant_nodos--;
		return aux->elemento;
	}

	nodo_t *nodo_anterior = posicion_nodo(lista->nodo_inicio, (int)posicion);

	if(nodo_anterior == NULL){
		return NULL;
	}

	nodo_t *nodo_borrado = nodo_anterior->siguiente;

	nodo_anterior->siguiente = nodo_anterior->siguiente->siguiente;

	lista->cant_nodos--;

	return nodo_borrado->elemento;
}

void *lista_elemento_en_posicion(lista_t *lista, size_t posicion)
{
	if(lista->cant_nodos < posicion)
		return NULL;

	if(posicion == 0)
		return lista->nodo_inicio->elemento;

	return posicion_nodo(lista->nodo_inicio, (int)posicion)->elemento;
}

void *lista_buscar_elemento(lista_t *lista, int (*comparador)(void *, void *), void *contexto)
{
	if(lista == NULL || comparador == NULL)
		return NULL;

	nodo_t *nodo = lista->nodo_inicio;

	while(comparador(nodo->elemento, contexto) != 0 && nodo != NULL)
	{
		nodo = nodo->siguiente;
	}
	
	if(nodo == NULL)
		return NULL;
	
	return nodo->elemento;
}

void *lista_primero(lista_t *lista)
{
	if(lista_vacia(lista))
		return NULL;

	return lista->nodo_inicio->elemento;
}

void *lista_ultimo(lista_t *lista)
{
	if(lista_vacia(lista))
		return NULL;

	return lista->nodo_fin->elemento;
}

bool lista_vacia(lista_t *lista)
{
	if(lista == NULL)
		return true;

	if(lista->cant_nodos == 0)
		return true;
		
	return false;
}

size_t lista_tamanio(lista_t *lista)
{
	if(lista == NULL)
		return 0;
	
	return (long unsigned int)lista->cant_nodos;
}

void lista_destruir(lista_t *lista)
{
	if(lista != NULL){
		nodo_t *nodo = lista->nodo_inicio;

		while(nodo != NULL)
		{
			nodo_t *aux = nodo->siguiente;
			free(nodo->elemento);
			free(nodo);
			nodo = aux;
		}
		
		free(lista);
	}
}

void lista_destruir_todo(lista_t *lista, void (*funcion)(void *))
{
	if(lista == NULL || funcion == NULL){
		nodo_t *nodo = lista->nodo_inicio;

		while(nodo != NULL)
		{
			nodo_t *aux = nodo->siguiente;
			funcion(nodo->elemento);
			free(nodo->elemento);
			free(nodo);
			nodo = aux;
		}
		
		free(lista);
	}
}

lista_iterador_t *lista_iterador_crear(lista_t *lista)
{
	if(lista == NULL)
		return NULL;

	struct lista_iterador* it = calloc(1, sizeof(struct lista_iterador));

	if(it == NULL)
		return NULL;

	it->actual = lista->nodo_inicio;
	it->actual->elemento = lista->nodo_inicio->elemento;

	return it;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t *iterador)
{
	if(iterador == NULL || iterador->actual->siguiente == NULL)
		return false;
	
	return true;
}

bool lista_iterador_avanzar(lista_iterador_t *iterador)
{
	if(iterador == NULL || !lista_iterador_tiene_siguiente(iterador))
		return false;

	iterador->actual = iterador->actual->siguiente;

	return true;
}

void *lista_iterador_elemento_actual(lista_iterador_t *iterador)
{
	if(iterador == NULL || iterador->actual == NULL)
		return NULL;

	return iterador->actual->elemento;
}

void lista_iterador_destruir(lista_iterador_t *iterador)
{
	free(iterador);
}

size_t lista_con_cada_elemento(lista_t *lista, bool (*funcion)(void *, void *),void *contexto)
{
	if(lista == NULL || funcion == NULL || lista_vacia(lista))
		return 0;

	size_t i = 0;
	nodo_t *actual = lista->nodo_inicio;

	while(funcion(actual->elemento, contexto) && actual != NULL)
	{
		i++;
		actual = actual->siguiente;
	}
	
	return i;
}