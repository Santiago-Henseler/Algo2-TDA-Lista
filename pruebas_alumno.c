#include "pa2m.h"
#include "src/lista.h"

// pruebas con lista no NULL
void dadaUnaListaInsertoVariosElementos()
{
	lista_t *lista = lista_crear();

	int num[] = { 1, 2, 3, 4, 5};

	for(int i = 0; i < 5; i++){
		lista_insertar(lista, &num[i]);
	}

	pa2m_afirmar(lista_tamanio(lista) == 5, "inserto 5 numeros");

	char let[] = "abcde";

	for(int i = 0; i < 5; i++){
		lista_insertar(lista, &let[i]);
	}

	pa2m_afirmar(lista_tamanio(lista) == 10, "inserto 5 letras");
	lista_destruir(lista);
}

void dadaUnaListaBorroVariosElementos(){
	lista_t *lista = lista_crear();

	int num[] = { 1, 2, 3, 4, 5};

	for(int i = 0; i < 5; i++){
		lista_insertar(lista, &num[i]);
	}

	for(int i = 0; i < 5; i++){
		lista_quitar(lista);
	}

	pa2m_afirmar(lista_tamanio(lista) == 0, "Borro toda la lista");

		for(int i = 0; i < 5; i++){
		lista_insertar(lista, &num[i]);
	}

	for(int i = 0; i < 3; i++){
		lista_quitar(lista);
	}

	pa2m_afirmar(lista_tamanio(lista) == 2, "Borro algunos elementos de la lista");

	lista_destruir(lista);
}

void dadaUnaListaInsertoElementosEnPosicion(){
	lista_t *lista = lista_crear();

	int num[] = { 1, 2, 3, 4, 5, 6, 7, 8};

	for(int i = 0; i < 5; i++){
		lista_insertar(lista, &num[i]);
	}

	lista_insertar_en_posicion(lista,  &num[5], 2);
	pa2m_afirmar( (int *)lista_elemento_en_posicion(lista, 2) ==  &num[5], "Inserto el 6 en posicion 2");

	lista_insertar_en_posicion(lista,  &num[6], 1000);
	pa2m_afirmar( (int *)lista_ultimo(lista) ==  &num[6], "Inserto el 7 en posicion inexistente");

	lista_insertar_en_posicion(lista,  &num[7], 0);
	pa2m_afirmar( (int *)lista_primero(lista) ==  &num[7], "Inserto el 8 al inicio");

	lista_destruir(lista);
}

void dadaUnaListaBorroElementosEnPosicion(){
	lista_t *lista = lista_crear();

	int num[] = { 1, 2, 3, 4, 5, 6, 7, 8};

	for(int i = 0; i < 8; i++){
		lista_insertar(lista, &num[i]);
	}

	
	pa2m_afirmar( (int *)lista_quitar_de_posicion(lista, 2) ==  &num[2], "Borro un elemento");
		pa2m_afirmar( (int *)lista_elemento_en_posicion(lista, 2) ==  &num[3], "Borro un elemento y se acomoda bien la lista");

	pa2m_afirmar( (int *)lista_quitar_de_posicion(lista, 0) ==  &num[0], "Borro el primer elemento");
	pa2m_afirmar( (int *)lista_primero(lista) ==  &num[1], "Borro el primer elemento y se acomoda bien la lista");

	pa2m_afirmar( (int *)lista_quitar_de_posicion(lista, 1000) == &num[7], "Borro un elemento fuera de la lista y se borra el ultimo");

	lista_destruir(lista);
}

void dadaUnaListaLaDestruyo(){

	lista_t *lista = lista_crear();

	lista_insertar(lista, malloc(sizeof(int *)));
	lista_insertar(lista, malloc(sizeof(int *)));
	lista_insertar(lista, malloc(sizeof(int *)));
	lista_insertar(lista, malloc(sizeof(int *)));
	lista_insertar(lista, malloc(sizeof(int *)));

	lista_destruir_todo(lista, free);

	pa2m_afirmar(lista_vacia(lista), "destruyo una lista con una funcion");

	lista_t *lista2 = lista_crear();

	lista_destruir(lista2);
	pa2m_afirmar(lista_vacia(lista2), "destruyo una lista");
}

// pruebas con lista NULL
void dadaUnaListaNulaNoInsertaElementos(){
	
	lista_t *lista = NULL;

	int num[] = {1};

	pa2m_afirmar(((void *)lista_insertar(lista, &num[0])) == NULL, "inserto en una lista vacia devuelve NULL");
	pa2m_afirmar(((void *)lista_insertar_en_posicion(lista, &num[0], 0)) == NULL, "inserto en una posicion en una lista vacia devuelve NULL");
}

void dadaUnaListaNulaDevuelveNulo(){
	lista_t *lista = NULL;

	pa2m_afirmar((void *)lista_tamanio(lista) == NULL, "tamaño de una lista nula devuelve NULL");
	pa2m_afirmar(lista_vacia(lista), "una lista nula esta vacia");
	pa2m_afirmar((void *)lista_primero(lista) == NULL, "una lista nula no tiene primero y devuelve NULL");
	pa2m_afirmar((void *)lista_ultimo(lista) == NULL, "una lista nula no tiene ultimo y devuelve NULL");
}

void dadaUnaListaNulaNoBorraElementos(){
	lista_t *lista = NULL;

	pa2m_afirmar(((void *)lista_quitar(lista)) == NULL, "borro en una lista vacia devuelve NULL");
	pa2m_afirmar(((void *)lista_quitar_de_posicion(lista, 0)) == NULL, "borro en una posicion en una lista vacia devuelve NULL");
}

// pruebas iterador externo

void dadUnaListaLaItero(){

	lista_t *lista = lista_crear();

	int num[] = { 1, 2, 3, 4, 5};

	for(int i = 0; i < 5; i++){
		lista_insertar(lista, &num[i]);
	}

	lista_iterador_t*  it = lista_iterador_crear(lista);

	int cant_i = 0;

	int posicion_correcta = 0;

	while (lista_iterador_tiene_siguiente(it))
	{
	
		if((int*)lista_iterador_elemento_actual(it) == &num[cant_i])
			posicion_correcta++;
		cant_i++;
		lista_iterador_avanzar(it);
	}


	pa2m_afirmar((int)lista_tamanio(lista) == cant_i, "recorro toda la lista con iterador externo");
	pa2m_afirmar((int)lista_tamanio(lista) == posicion_correcta, "el elemento actual es el correcto");
	
	lista_iterador_destruir(it);
	lista_destruir(lista);
}

int main()
{

	pa2m_nuevo_grupo("\n======================== Pruebas lista ========================");

	dadaUnaListaInsertoVariosElementos();
	dadaUnaListaBorroVariosElementos();
	dadaUnaListaInsertoElementosEnPosicion();
	dadaUnaListaBorroElementosEnPosicion();
	dadaUnaListaLaDestruyo();

	pa2m_nuevo_grupo("\n======================== Pruebas lista NULL ========================");

	dadaUnaListaNulaNoInsertaElementos();
	dadaUnaListaNulaDevuelveNulo();
	dadaUnaListaNulaNoBorraElementos();

	pa2m_nuevo_grupo("\n======================== Pruebas con iterador========================");

	dadUnaListaLaItero();

	return pa2m_mostrar_reporte();
}
