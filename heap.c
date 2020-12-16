#include "heap.h"
#include <stdbool.h>  // bool
#include <stddef.h>   // size_t

#define TAM_INICIAL 1000

struct heap{
    void** datos;
    size_t cant;
    size_t tam;
    cmp_func_t cmp;
} 

// ----------------- AUXILIARES ----------------- 

void heapify(heap_t* heap){
    for (size_t i = 0; i <n ; i++);
}

// ----------------- PRIMITIVAS ----------------- 

/* Función de heapsort genérica. Esta función ordena mediante heap_sort
 * un arreglo de punteros opacos, para lo cual requiere que se
 * le pase una función de comparación. Modifica el arreglo "in-place".
 * Nótese que esta función NO es formalmente parte del TAD Heap.
 */
void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp);

/* Crea un heap. Recibe como único parámetro la función de comparación a
 * utilizar. Devuelve un puntero al heap, el cual debe ser destruido con
 * heap_destruir().
 */
heap_t *heap_crear(cmp_func_t cmp){
    heap_t heap = malloc(sizeof(heap_t));
    if (!heap) return NULL;
    heap->datos = malloc(TAM_INICIAL*sizeof(void*));
    if(!datos){
        free(heap);
        return NULL;
    }
    heap->tam = TAM_INICIAL;
    heap->cant = 0;
    heap->cmp = cmp;
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
    heap_t heap = malloc(sizeof(heap_t));
    if (!heap) return NULL;
    heap->datos = malloc(n*sizeof(void*));
    if(!datos){
        free(heap);
        return NULL;
    }
    for (size_t i = 0; i <n ; i++) heap->datos[i] = arreglo[i];
    heapify(heap);
    heap->tam = n;
    heap->cant = n;
    heap->cmp = cmp;
}

/* Elimina el heap, llamando a la función dada para cada elemento del mismo.
 * El puntero a la función puede ser NULL, en cuyo caso no se llamará.
 * Post: se llamó a la función indicada con cada elemento del heap. El heap
 * dejó de ser válido. */
void heap_destruir(heap_t *heap, void (*destruir_elemento)(void *e)){
    if (destruir_elemento){
        for (size_t i = 0; i <n ; i++) destruir_elemento(heap->datos[i]);
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
bool heap_encolar(heap_t *heap, void *elem);

/* Devuelve el elemento con máxima prioridad. Si el heap esta vacío, devuelve
 * NULL.
 * Pre: el heap fue creado.
 */
void *heap_ver_max(const heap_t *heap);

/* Elimina el elemento con máxima prioridad, y lo devuelve.
 * Si el heap esta vacío, devuelve NULL.
 * Pre: el heap fue creado.
 * Post: el elemento desencolado ya no se encuentra en el heap.
 */
void *heap_desencolar(heap_t *heap);


<<<<<<< HEAD
void pruebas_heap_estudiante(void);
=======
void pruebas_heap_estudiante(void);
>>>>>>> bb296560d7ed73893fed581c3ccec9f0d6b673d0
