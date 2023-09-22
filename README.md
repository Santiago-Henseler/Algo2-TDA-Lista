<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# TDA Lista-Cola-Pila

## Repositorio de Santiago Henseler - 110732 - shenseler@fi.uba.ar

- Para compilar:

```bash
make pruebas_alumno
```

- Para ejecutar:
```bash
./pruebas_alumno
```

- Para ejecutar con valgrind:
```bash
make valgrind-alumno
```
---
##  ¿Qué es una lista?

Una lista es un T.D.A.(tipo de dato abstracto) que agrupa elementos, los cuales tienen un orden establecido, con predecesores(menos el primero) y sucesores(menos el ultimo). Y su ultimo elemento siempre apunta al NULL.

<br />
<div align="center">
<img width="70%" src="img/lista.jpg">
</div>

<br />

Al ser un T.D.A. esta completamente encapsulada y es imposible acceder a los elemento de la misma. Por eso se definen las siguientes operaciones:
`lista_crear()`, `lista_insertar()`, `lista_quitar()`, `lista_elemento_en_posicion()`, `lista_buscar_elemento()`, `lista_destruir()`, `lista_tamanio()`, un iterador externo, un iterador interno, entre otras funcionalidades extra que se le pueden añadir (como las que añadimos al T.D.A. en este trabajo).

<br />

La lista se puede implementar de 3 maneras distintas:

- Vector estatico: consiste en la implementacion de una lista con un campo declarado como vector, con su respectivo tamaño `[MAX_LISTA]` y otro campo con la cantidad de elementos `cant_elementos`. Esta implementacion nos restringe la cantidad de elementos a añadir a la lista por culpa del tamaño. El vector se declara con cierto tamaño y no se puede agrandar o achicar. 

```c
struct lista{
    void lista_estatica[MAX_LISTA];
    int cant_elementos;
}
```
- Vector dinamico: consiste en la implementacion de una lista con un campo declarado como puntero a un vector y otro campo con la cantidad de elementos `cant_elementos`. Esta implementacion no nos restringe la cantidad de elementos a añadir a la lista ya que mediante el uso de `realloc()` podemos ir agrandando su tamaño. El unico problema con esta implementación que la memoria almacenada deben ser bloques continuos de memoria, por lo tanto en situaciones donde se requiera mucha memoria o se disponga de poca puede fallar la implementación.
  
```c
struct lista{
    void *lista_estatica;
    int cant_elementos;
}
```
- Nodos: consiste en la implementacion de una lista como una serie de nodos enlazados los cuales contienen un valor y un puntero al siguiente nodo. De esta forma, todos los nodos quedan conectados mediante este puntero. La mayor ventaja que tiene es que utilizamos secciones separadas de memoria para cada nodo, descartando el problema de los vectores dinamicos.
```c
struct lista{
    nodo_t nodo_inicio*;
    int cant_elementos;
    nodo_t nodo_fin*;
}

struct nodo_t{
    nodo_t siguiente_nodo*;
    void* elemento;
}
```
A su vez los nodos se pueden implementar de dos maneras distintas:

- Nodos simplemente enlazados: Cada nodo referencia solo a su sucesor(menos el ultimo)
<div align="center">
<img width="70%" src="img/lista_nodo1.jpg">
</div>

-->La complejidad algoritmica para -Insertar al inicio o al final- en las listas implementadas con nodos simplemente enlazados es:

<div align="center">
<img width="70%" src="img/lista_nodo1_insertar.jpg">
</div>
  
```
creo un nuevo nodo --> 1
asigno como siguiente al nuevo nodo el nodo que esta en primera posicion --> 1
asigno como primer nodo al nuevo -->1
```
Contando todas las instrucciones se llega a la siguiente ecuación: `T(n) = 1+1+1` . Entonces tiene una complejidad de *O(1)* porque: `3 < N , ∀ N > 3`

<br>

-->La complejidad algoritmica para -Borrar al inicio- en las listas implementadas con nodos simplemente enlazados es:

<div align="center">
<img width="70%" src="img/lista_nodo1_borrar.jpg">
</div>

```
creo un puntero aux --> 1
apunto aux al nodo a borrar --> 1
asigno como primer nodo al segundo nodo -->1
libero la memoria de aux -->1
```
Contando todas las instrucciones se llega a la siguiente ecuación: `T(n) = 1+1+1+1` . Entonces tiene una complejidad de *O(1)* porque: `4 < N , ∀ N > 4`

-->La complejidad algoritmica para -obtener al inicio o al final- en las listas implementadas con nodos simplemente enlazados es:
```
apunto al primer nodo --> 1
```
Contando todas las instrucciones se llega a la siguiente ecuación: `T(n) = 1` . Entonces tiene una complejidad de *O(1)* porque: `1 < N , ∀ N > 1`

La complejidad algoritmica para las 3 operaciones con el primer elemento de la lista es *O(1)* porque tenemos a disposicion el puntero al primer elemento, lo que favorece a no tener que iterar toda la lista. Tambien se cumple que insertar y obtener al final es *O(1)* porque tambien tenemos el puntero al ultimo elemento. En cambio:

-->La complejidad algoritmica para -borrar al final- en las listas implementadas con nodos simplemente enlazados es:
```
libreo la memoria del ultimo nodo --> 1
recorro hasta el anteultimo nodo --> n-1
apunto el anteultimo nodo a NULL --> 1
asigno como ultimo nodo al anteultimo --> 1
```
Contando todas las instrucciones se llega a la siguiente ecuación: `T(n) = 1+1+1+n-1` . Entonces tiene una complejidad de *O(n)* porque: `2+n < N , ∀ N > 3`
