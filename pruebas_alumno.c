#include "pa2m.h"
#include "src/lista.h"

// pruebas con lista no NULL
void dadaUnaListaInsertoVariosElementos()
{
	lista_t *lista = lista_crear();

	int num[] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; i++) {
		lista_insertar(lista, &num[i]);
	}

	pa2m_afirmar(lista_tamanio(lista) == 5, "inserto 5 numeros");

	char let[] = "abcde";

	for (int i = 0; i < 5; i++) {
		lista_insertar(lista, &let[i]);
	}

	pa2m_afirmar(lista_tamanio(lista) == 10, "inserto 5 letras");
	lista_destruir(lista);
}

void dadaUnaListaBorroVariosElementos()
{
	lista_t *lista = lista_crear();

	int num[] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; i++) {
		lista_insertar(lista, &num[i]);
	}

	for (int i = 0; i < 5; i++) {
		lista_quitar(lista);
	}

	pa2m_afirmar(lista_tamanio(lista) == 0, "Borro toda la lista");

	for (int i = 0; i < 5; i++) {
		lista_insertar(lista, &num[i]);
	}

	for (int i = 0; i < 3; i++) {
		lista_quitar(lista);
	}

	pa2m_afirmar(lista_tamanio(lista) == 2,
		     "Borro algunos elementos de la lista");

	lista_destruir(lista);
}

void dadaUnaListaInsertoElementosEnPosicion()
{
	lista_t *lista = lista_crear();

	int num[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	for (int i = 0; i < 5; i++) {
		lista_insertar(lista, &num[i]);
	}

	lista_insertar_en_posicion(lista, &num[5], 2);
	pa2m_afirmar((int *)lista_elemento_en_posicion(lista, 2) == &num[5],
		     "Inserto el 6 en posicion 2");

	lista_insertar_en_posicion(lista, &num[6], 1000);
	pa2m_afirmar((int *)lista_ultimo(lista) == &num[6],
		     "Inserto el 7 en posicion inexistente");

	lista_insertar_en_posicion(lista, &num[7], 0);
	pa2m_afirmar((int *)lista_primero(lista) == &num[7],
		     "Inserto el 8 al inicio");

	lista_destruir(lista);
}

void dadaUnaListaBorroElementosEnPosicion()
{
	lista_t *lista = lista_crear();

	int num[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	for (int i = 0; i < 8; i++) {
		lista_insertar(lista, &num[i]);
	}

	pa2m_afirmar((int *)lista_quitar_de_posicion(lista, 2) == &num[2],
		     "Borro un elemento");
	pa2m_afirmar((int *)lista_elemento_en_posicion(lista, 2) == &num[3],
		     "Borro un elemento y se acomoda bien la lista");

	pa2m_afirmar((int *)lista_quitar_de_posicion(lista, 0) == &num[0],
		     "Borro el primer elemento");
	pa2m_afirmar((int *)lista_primero(lista) == &num[1],
		     "Borro el primer elemento y se acomoda bien la lista");

	pa2m_afirmar(
		(int *)lista_quitar_de_posicion(lista, 1000) == &num[7],
		"Borro un elemento fuera de la lista y se borra el ultimo");

	lista_destruir(lista);
}

// pruebas con lista NULL
void dadaUnaListaNulaNoInsertaElementos()
{
	lista_t *lista = NULL;

	int num[] = { 1 };

	pa2m_afirmar(((void *)lista_insertar(lista, &num[0])) == NULL,
		     "inserto en una lista vacia devuelve NULL");
	pa2m_afirmar(
		((void *)lista_insertar_en_posicion(lista, &num[0], 0)) == NULL,
		"inserto en una posicion en una lista vacia devuelve NULL");
}

void dadaUnaListaNulaDevuelveNulo()
{
	lista_t *lista = NULL;

	pa2m_afirmar((void *)lista_tamanio(lista) == NULL,
		     "tamaño de una lista nula devuelve NULL");
	pa2m_afirmar(lista_vacia(lista), "una lista nula esta vacia");
	pa2m_afirmar((void *)lista_primero(lista) == NULL,
		     "una lista nula no tiene primero y devuelve NULL");
	pa2m_afirmar((void *)lista_ultimo(lista) == NULL,
		     "una lista nula no tiene ultimo y devuelve NULL");
}

void dadaUnaListaNulaNoBorraElementos()
{
	lista_t *lista = NULL;

	pa2m_afirmar(((void *)lista_quitar(lista)) == NULL,
		     "borro en una lista vacia devuelve NULL");
	pa2m_afirmar(((void *)lista_quitar_de_posicion(lista, 0)) == NULL,
		     "borro en una posicion en una lista vacia devuelve NULL");
}

// pruebas iterador externo
void dadaUnaListaLaIteroExternamente()
{
	lista_t *lista = lista_crear();

	int num[] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; i++) {
		lista_insertar(lista, &num[i]);
	}

	lista_iterador_t *it = lista_iterador_crear(lista);

	int cant_i = 0;

	int posicion_correcta = 0;

	while (lista_iterador_tiene_siguiente(it)) {
		if ((int *)lista_iterador_elemento_actual(it) == &num[cant_i])
			posicion_correcta++;
		cant_i++;
		lista_iterador_avanzar(it);
	}

	pa2m_afirmar((int)lista_tamanio(lista) == cant_i,
		     "recorro toda la lista con iterador externo");
	pa2m_afirmar((int)lista_tamanio(lista) == posicion_correcta,
		     "el elemento actual es el correcto");

	lista_iterador_destruir(it);
	lista_destruir(lista);
}

// pruebas iterador externo NULL
void dadaUnaListaNulaNoLaIteroExternamente()
{
	lista_t *lista = NULL;

	int num[] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; i++) {
		lista_insertar(lista, &num[i]);
	}

	lista_iterador_t *it = lista_iterador_crear(lista);

	int cant_i = 0;

	int posicion_correcta = 0;

	while (lista_iterador_tiene_siguiente(it)) {
		if ((int *)lista_iterador_elemento_actual(it) == &num[cant_i])
			posicion_correcta++;
		cant_i++;
		lista_iterador_avanzar(it);
	}

	pa2m_afirmar(cant_i == 0, "no recorro una lista nula");

	lista_iterador_destruir(it);
	lista_destruir(lista);
}

void dadoUnIteradorNuloNoRecorro()
{
	lista_t *lista = lista_crear();

	int num[] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; i++) {
		lista_insertar(lista, &num[i]);
	}

	lista_iterador_t *it = NULL;

	int cant_i = 0;

	int posicion_correcta = 0;

	while (lista_iterador_tiene_siguiente(it)) {
		if ((int *)lista_iterador_elemento_actual(it) == &num[cant_i])
			posicion_correcta++;
		cant_i++;
		lista_iterador_avanzar(it);
	}

	pa2m_afirmar(cant_i == 0, "no recorro con un iterador nulo");

	lista_destruir(lista);
}

//iterador interno
bool contar_iteracion(void *a, void *i)
{
	(*(int *)i)++;
	return true;
}

void dadoUnaListaLaIteroInternamente()
{
	lista_t *lista = lista_crear();

	int num[] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; i++) {
		lista_insertar(lista, &num[i]);
	}

	int i = 0;

	lista_con_cada_elemento(lista, &contar_iteracion, (void *)&i);

	pa2m_afirmar(i == 5,
		     "itero todos los elementos con el iterador interno");

	lista_destruir(lista);
}

//iterador interno NULL

void dadaUnaListaNulaNoLaIteroInternamente()
{
	lista_t *lista = NULL;

	int i = 0;

	lista_con_cada_elemento(lista, &contar_iteracion, (void *)&i);

	pa2m_afirmar(i == 0, "no itero una lista nula con el iterador interno");
}

void dadaUnaFuncionNulaNoRecorro()
{
	lista_t *lista = lista_crear();

	int num[] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; i++) {
		lista_insertar(lista, &num[i]);
	}

	int i = 0;

	lista_con_cada_elemento(lista, NULL, (void *)&i);

	pa2m_afirmar(
		i == 0,
		"no itero con el iterador interno si la funcion no existe");

	lista_destruir(lista);
}

int main()
{
	pa2m_nuevo_grupo(
		"\n======================== Pruebas lista ========================");

	dadaUnaListaInsertoVariosElementos();
	dadaUnaListaBorroVariosElementos();
	dadaUnaListaInsertoElementosEnPosicion();
	dadaUnaListaBorroElementosEnPosicion();

	pa2m_nuevo_grupo(
		"\n======================== Pruebas lista NULL ========================");

	dadaUnaListaNulaNoInsertaElementos();
	dadaUnaListaNulaDevuelveNulo();
	dadaUnaListaNulaNoBorraElementos();

	pa2m_nuevo_grupo(
		"\n======================== Pruebas con iterador externo ========================");

	dadaUnaListaLaIteroExternamente();

	pa2m_nuevo_grupo(
		"\n======================== Pruebas con iterador externo NULL ========================");

	dadaUnaListaNulaNoLaIteroExternamente();
	dadoUnIteradorNuloNoRecorro();

	pa2m_nuevo_grupo(
		"\n======================== Pruebas con iterador interno ========================");

	dadoUnaListaLaIteroInternamente();

	pa2m_nuevo_grupo(
		"\n======================== Pruebas con iterador interno NULL ========================");

	dadaUnaListaNulaNoLaIteroInternamente();
	dadaUnaFuncionNulaNoRecorro();

	return pa2m_mostrar_reporte();
}
