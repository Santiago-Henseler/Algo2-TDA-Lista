#include "cola.h"
#include "nodo.h"
#include "lista.h"

struct _cola_t {
	nodo_t *nodo_inicio;
	size_t cant_nodos;
	nodo_t *nodo_fin;
};

cola_t *cola_crear()
{
	return (cola_t *)lista_crear();
}

cola_t *cola_encolar(cola_t *cola, void *elemento)
{
	return (cola_t *)lista_insertar((lista_t *)cola, elemento);
}

void *cola_desencolar(cola_t *cola)
{
	return lista_quitar_de_posicion((lista_t *)cola, 0);
}

void *cola_frente(cola_t *cola)
{
	return lista_primero((lista_t *)cola);
}

size_t cola_tamanio(cola_t *cola)
{
	return lista_tamanio((lista_t *)cola);
}

bool cola_vacia(cola_t *cola)
{
	return lista_vacia((lista_t *)cola);
}

void cola_destruir(cola_t *cola)
{
	lista_destruir((lista_t *)cola);
}
