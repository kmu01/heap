#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#define TAM_INICIAL 1000

struct heap{  //En este caso trabajamos con un heap de minimos.
    void** datos;
    size_t cant;
    size_t tam;
    cmp_func_t cmp;
}; 

// ----------------- AUXILIARES ----------------- 

void swap(void* primero, void* segundo){
    void* aux = primero;
    primero = segundo;
    segundo = aux;
}


void upheap(void** datos, size_t hijo, cmp_func_t cmp){
    if (hijo == 0) return;
    size_t padre = (hijo - 1) / 2;
    if (cmp(datos[hijo], datos[padre]) < 0) return; 
    swap(datos[hijo], datos[padre]);
    upheap(datos, padre, cmp);
}

size_t minimo(void** datos, cmp_func_t cmp, size_t padre, size_t h_izq, size_t h_der){
    size_t min;
    if (cmp(datos[h_der], datos[h_izq]) < 0){
        min = h_der;
    } else{
        min = h_izq;
    }
    if (cmp(datos[padre], datos[min]) < 0) min = padre;
    return min;
}

void downheap(void** datos, size_t cant, size_t padre, cmp_func_t cmp){
    if (padre >= cant) return;
    size_t h_izq = (padre * 2) + 1;
    size_t h_der = (padre * 2) + 2;
    size_t min = minimo(datos, cmp, padre, h_izq, h_der);
    if (min != padre){
        swap(datos[padre], datos[min]);
        downheap(datos, cant, min, cmp);
    }
}

/*
 * Función que le da forma de heap a un arreglo de n elementos.
 */
void heapify(void** datos, size_t cant, cmp_func_t cmp){
    for(size_t i = (cant/2); i > 0 ; i--){
       downheap(datos, cant, i-1, cmp);
    }
}

// ----------------- PRIMITIVAS ----------------- 

/* Función de heapsort genérica. Esta función ordena mediante heap_sort
 * un arreglo de punteros opacos, para lo cual requiere que se
 * le pase una función de comparación. Modifica el arreglo "in-place".
 * Nótese que esta función NO es formalmente parte del TAD Heap.
 */
void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp){
    heapify(elementos, cant, cmp);
    for (size_t i = cant-1; i > 0; i--){
        swap(elementos[0], elementos[i]);
        downheap(elementos, i, 0, cmp);
    }
}

/* Crea un heap. Recibe como único parámetro la función de comparación a
 * utilizar. Devuelve un puntero al heap, el cual debe ser destruido con
 * heap_destruir().
 */
heap_t *heap_crear(cmp_func_t cmp){
    heap_t* heap = malloc(sizeof(heap_t));
    if (!heap) return NULL;
    heap->datos = malloc(TAM_INICIAL*sizeof(void*));
    if(!heap->datos){
        free(heap);
        return NULL;
    }
    heap->tam = TAM_INICIAL;
    heap->cant = 0;
    heap->cmp = cmp;
    return heap;
}

/*
 * Constructor alternativo del heap. Además de la función de comparación,
 * recibe un arreglo de valores con que inicializar el heap. Complejidad
 * O(n).
 *
 * Excepto por la complejidad, es equivalente a crear un heap vacío y encolar
 * los valores de uno en uno
*/
heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp){
    heap_t* heap = malloc(sizeof(heap_t));
    if (!heap) return NULL;
    heap->datos = malloc(n*sizeof(void*));
    if(!heap->datos){
        free(heap);
        return NULL;
    }
    for (size_t i = 0; i < n; i++) heap->datos[i] = arreglo[i];
    heap->tam = n;
    heap->cant = n;
    heap->cmp = cmp;
    heapify(heap->datos, heap->cant, heap->cmp);
    return heap;
}

/* Elimina el heap, llamando a la función dada para cada elemento del mismo.
 * El puntero a la función puede ser NULL, en cuyo caso no se llamará.
 * Post: se llamó a la función indicada con cada elemento del heap. El heap
 * dejó de ser válido. */
void heap_destruir(heap_t *heap, void (*destruir_elemento)(void *e)){
    if (destruir_elemento){
        for (size_t i = 0; i < heap->cant ; i++) destruir_elemento(heap->datos[i]);
    }
    free(heap->datos);
    free(heap);
}

/* Devuelve la cantidad de elementos que hay en el heap. */
size_t heap_cantidad(const heap_t *heap){
    return heap->cant;
}

/* Devuelve true si la cantidad de elementos que hay en el heap es 0, false en
 * caso contrario. */
bool heap_esta_vacio(const heap_t *heap){
    return heap->cant == 0;
}

/* Agrega un elemento al heap. El elemento no puede ser NULL.
 * Devuelve true si fue una operación exitosa, o false en caso de error.
 * Pre: el heap fue creado.
 * Post: se agregó un nuevo elemento al heap.
 */
bool heap_encolar(heap_t *heap, void *elem){
    //Agregar funcion de redimension.
    heap->datos[heap->cant] = elem;
    upheap(heap->datos, heap->cant, heap->cmp);
    heap->cant++;
    return true;
}

/* Devuelve el elemento con máxima prioridad. Si el heap esta vacío, devuelve
 * NULL.
 * Pre: el heap fue creado.
 */
void *heap_ver_max(const heap_t *heap){
    if(heap_esta_vacio(heap)) return NULL;
    return heap->datos[0];
}

/* Elimina el elemento con máxima prioridad, y lo devuelve.
 * Si el heap esta vacío, devuelve NULL.
 * Pre: el heap fue creado.
 * Post: el elemento desencolado ya no se encuentra en el heap.
 */
void *heap_desencolar(heap_t *heap){
    if(heap_esta_vacio(heap)) return NULL;
    void* dato = heap_ver_max(heap);
    heap->datos[0] = heap->datos[--heap->cant];
    downheap(heap->datos, heap->cant, 0, heap->cmp);
    //Agregar funcion de redimension.
    return dato;
}



