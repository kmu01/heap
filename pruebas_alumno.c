#include <stdio.h>
#include <stdlib.h>   // malloc
#include <stdbool.h>  // bool
#include <stddef.h>   // size_t
#include <string.h>   // strcmp
#include "heap.h"
#include "testing.h"

/* Funciones de comparacion */
int comparar_enteros (const void* a , const void* b){
    int numero_a = *(int*)a;
    int numero_b = *(int*)b;
    if (numero_a < numero_b){
        return -1;
    }
    else if (numero_a > numero_b){
        return 1;
    }
    return 0;
}

int comparar_cadenas (const void* a , const void* b){
    char* cadena_a = (char*)a;
    char* cadena_b = (char*)b;
    return (strcmp(cadena_a,cadena_b));
}

/* Funciones de pruebas */
static void prueba_heap_vacio (void){
    printf ("\nINICIO DE PRUEBAS HEAP VACIO\n");
    /* Defino los recursos a utilizar */
    heap_t* heap = heap_crear (comparar_enteros);

    /* Inicio pruebas */
    print_test ("El heap esta vacio" , heap_esta_vacio(heap));
    print_test ("La cantidad es 0" , heap_cantidad(heap)==0);
    print_test ("Obtener max heap vacio" , heap_ver_max(heap)==NULL);
    print_test ("Desencolar heap vacio" , heap_desencolar(heap)==NULL);

    /* Destruyo el heap */
    heap_destruir (heap , NULL);
    printf ("El heap fue destruido\n");
}

static void prueba_heap_encolar_en_orden (void){
    printf ("\nINICIO DE PRUEBAS HEAP ENCOLAR EN ORDEN\n");
    /* Defino los recursos a utilizar */
    heap_t* heap = heap_crear (comparar_enteros);
    int numero1 = 0; int* numero_1 = &numero1;
    int numero2 = 1; int* numero_2 = &numero2;
    int numero3 = 2; int* numero_3 = &numero3;
    int numero4 = 3; int* numero_4 = &numero4;
    int numero5 = 4; int* numero_5 = &numero5;
    int numero6 = 5; int* numero_6 = &numero6;

    /* Inicio de pruebas */
    print_test ("El heap esa vacio" , heap_esta_vacio(heap));
    print_test ("Encolo elemento 1" , heap_encolar (heap , numero_1));
    print_test ("Verifico que no está vacio" , !heap_esta_vacio(heap));
    print_test ("Verifico la cantidad" , heap_cantidad(heap)==1);
    print_test ("Verifico maximo elemento" , heap_ver_max (heap) == numero_1);
    print_test ("Encolo elemento 2" , heap_encolar (heap , numero_2));
    print_test ("Verifico la cantidad" , heap_cantidad(heap)==2);
    print_test ("Verifico maximo elemento" , heap_ver_max (heap) == numero_2);
    print_test ("Encolo elemento 3" , heap_encolar (heap , numero_3));
    print_test ("Verifico la cantidad" , heap_cantidad(heap)==3);
    print_test ("Verifico maximo elemento" , heap_ver_max (heap) == numero_3);
    print_test ("Encolo elemento 4" , heap_encolar (heap , numero_4));
    print_test ("Verifico la cantidad" , heap_cantidad(heap)==4);
    print_test ("Verifico maximo elemento" , heap_ver_max (heap) == numero_4);
    print_test ("Encolo elemento 5" , heap_encolar (heap , numero_5));
    print_test ("Verifico la cantidad" , heap_cantidad(heap)==5);
    print_test ("Verifico maximo elemento" , heap_ver_max (heap) == numero_5);
    print_test ("Encolo elemento 6" , heap_encolar (heap , numero_6));
    print_test ("Verifico la cantidad" , heap_cantidad(heap)==6);
    print_test ("Verifico maximo elemento" , heap_ver_max (heap) == numero_6);

    /* Destruyo el heap */
    heap_destruir (heap , NULL);
    printf ("El heap fue destruido\n");
}

static void prueba_heap_encolar_desordenado (void){
    printf ("\nINICIO DE PRUEBAS HEAP ENCOLAR DESORDENADO\n");
    /* Defino los recursos a utilizar */
    heap_t* heap = heap_crear (comparar_enteros);
    int numero1 = 0; int* numero_1 = &numero1;
    int numero2 = 1; int* numero_2 = &numero2;
    int numero3 = 2; int* numero_3 = &numero3;
    int numero4 = 3; int* numero_4 = &numero4;
    int numero5 = 4; int* numero_5 = &numero5;
    int numero6 = 5; int* numero_6 = &numero6;


    /* Inicio de pruebas */
    print_test ("El heap esa vacio" , heap_esta_vacio(heap));
    print_test ("Encolo elemento 1" , heap_encolar (heap , numero_3));
    print_test ("Verifico que no está vacio" , !heap_esta_vacio(heap));
    print_test ("Verifico la cantidad" , heap_cantidad(heap)==1);
    print_test ("Verifico maximo elemento" , heap_ver_max (heap) == numero_3);
    print_test ("Encolo elemento 2" , heap_encolar (heap , numero_1));
    print_test ("Verifico la cantidad" , heap_cantidad(heap)==2);
    print_test ("Verifico maximo elemento" , heap_ver_max (heap) == numero_3);
    print_test ("Encolo elemento 3" , heap_encolar (heap , numero_5));
    print_test ("Verifico la cantidad" , heap_cantidad(heap)==3);
    print_test ("Verifico maximo elemento" , heap_ver_max (heap) == numero_5);
    print_test ("Encolo elemento 4" , heap_encolar (heap , numero_4));
    print_test ("Verifico la cantidad" , heap_cantidad(heap)==4);
    print_test ("Verifico maximo elemento" , heap_ver_max (heap) == numero_5);
    print_test ("Encolo elemento 5" , heap_encolar (heap , numero_2));
    print_test ("Verifico la cantidad" , heap_cantidad(heap)==5);
    print_test ("Verifico maximo elemento" , heap_ver_max (heap) == numero_5);
    print_test ("Encolo elemento 6" , heap_encolar (heap , numero_6));
    print_test ("Verifico la cantidad" , heap_cantidad(heap)==6);
    print_test ("Verifico maximo elemento" , heap_ver_max (heap) == numero_6);

    /* Destruyo el heap */
    heap_destruir (heap , NULL);
    printf ("El heap fue destruido\n");
}

static void prueba_heap_desencolar (void){
    printf ("\nINICIO DE PRUEBAS HEAP DESENCOLAR\n");
    /* Defino los recursos a utilizar */
    heap_t* heap = heap_crear (comparar_enteros);
    int numero1 = 0; int* numero_1 = &numero1;
    int numero2 = 1; int* numero_2 = &numero2;
    int numero3 = 2; int* numero_3 = &numero3;
    int numero4 = 3; int* numero_4 = &numero4;
    int numero5 = 4; int* numero_5 = &numero5;
    int numero6 = 5; int* numero_6 = &numero6;

    
    /* Inicio de pruebas */
    print_test ("Heap vacio" , heap_esta_vacio(heap));
    print_test ("Encolar elemento 1" , heap_encolar(heap , numero_3));
    print_test ("Encolar elemento 2" , heap_encolar(heap , numero_2));
    print_test ("Encolar elemento 3" , heap_encolar(heap , numero_5));
    print_test ("Encolar elemento 4" , heap_encolar(heap , numero_1));
    print_test ("Encolar elemento 5" , heap_encolar(heap , numero_4));
    print_test ("Encolar elemento 6" , heap_encolar(heap , numero_6));

    print_test ("Verifico cantidad" , heap_cantidad (heap)==6);

    print_test ("Desencolar" , heap_desencolar (heap)==numero_6);
    print_test ("Verifico cantidad" , heap_cantidad(heap)==5);
    print_test ("Desencolar" , heap_desencolar (heap)==numero_5);
    print_test ("Verifico cantidad" , heap_cantidad(heap)==4);
    print_test ("Desencolar" , heap_desencolar (heap)==numero_4);
    print_test ("Verifico cantidad" , heap_cantidad(heap)==3);
    print_test ("Desencolar" , heap_desencolar (heap)==numero_3);
    print_test ("Verifico cantidad" , heap_cantidad(heap)==2);
    print_test ("Desencolar" , heap_desencolar (heap)==numero_2);
    print_test ("Verifico cantidad" , heap_cantidad(heap)==1);
    print_test ("Desencolar" , heap_desencolar (heap)==numero_1);
    print_test ("Verifico que está vacio" , heap_esta_vacio(heap));
    print_test ("Verifico que no puedo desencolar" , heap_desencolar(heap)==NULL);

    /* Destruyo el heap */
    heap_destruir (heap , NULL);
    printf ("El heap fue destruido\n");
}

static void prueba_heap_destruir_con_NULL (void){
    printf ("\nINICIO DE PRUEBAS HEAP DESTRUIR CON FUNCION NULL\n");
    /* Defino los recursos a utilizar */
    heap_t* heap = heap_crear (comparar_cadenas);
    char* cadena_1 = "prueba1";
    char* cadena_2 = "prueba2";
    char* cadena_3 = "prueba3";
    char* cadena_4 = "prueba4";
    char* cadena_5 = "prueba5";
    char* cadena_6 = "prueba6";

    /* Inicio de pruebas */
    print_test ("Encolar elemento 1" , heap_encolar (heap , cadena_1));
    print_test ("Encolar elemento 2" , heap_encolar (heap , cadena_2));
    print_test ("Encolar elemento 3" , heap_encolar (heap , cadena_3));
    print_test ("Encolar elemento 4" , heap_encolar (heap , cadena_4));
    print_test ("Encolar elemento 5" , heap_encolar (heap , cadena_5));
    print_test ("Encolar elemento 6" , heap_encolar (heap , cadena_6));

    /* Destruyo el heap */
    heap_destruir (heap , NULL);
    print_test ("El heap fue destruido con elementos",true);
}

static void prueba_heap_destruir_con_free (void){
    printf ("\nINICIO DE PRUEBAS HEAP DESTRUIR CON FUNCION FREE\n");
    /* Defino los recursos a utilizar */
    heap_t* heap = heap_crear (comparar_cadenas);
    char* cadena_1 = malloc (5*sizeof (char));
    cadena_1[0] = 'H'; cadena_1[1] = 'o'; cadena_1[2] = 'l'; cadena_1[3] = 'a'; cadena_1[4] = '\0';
    char* cadena_2 = malloc (5*sizeof (char));
    cadena_2[0] = 'C'; cadena_2[1] = 'a'; cadena_2[2] = 's'; cadena_2[3] = 'a'; cadena_2[4] = '\0';
    char* cadena_3 = malloc (5*sizeof (char));
    cadena_3[0] = 'P'; cadena_3[1] = 'e'; cadena_3[2] = 'r'; cadena_3[3] = 'a'; cadena_3[4] = '\0';

    /* Inicio de pruebas */
    print_test ("Encolar elemento" , heap_encolar(heap , cadena_1));
    print_test ("Encolar elemento" , heap_encolar(heap , cadena_2));
    print_test ("Encolar elemento" , heap_encolar(heap , cadena_3));

    void (*puntero_free)() = &free;
    heap_destruir (heap , puntero_free);
    print_test ("El heap fue destruido con free" , true);
}

static void prueba_heapify (){
    printf ("\nINICIO DE PRUEBAS HEAPIFY\n");
    /* Defino los recursos a utilizar */
    char* cadena_1 = "A";
    char* cadena_2 = "B";
    char* cadena_3 = "C";
    char* cadena_4 = "D";
    void** arreglo = malloc (4*sizeof (char*));

    arreglo[0] = cadena_2; arreglo[1]=cadena_3; arreglo[2] = cadena_1; arreglo[3]=cadena_4;
    heap_t* heap = heap_crear_arr (arreglo , 4 , comparar_cadenas);

    /* Inicio de pruebas */
    print_test ("Verifico maximo" , heap_ver_max(heap)==cadena_4);
    print_test ("Desencolar" , heap_desencolar(heap)==cadena_4);
    print_test ("Verifico maximo" , heap_ver_max(heap)==cadena_3);
    print_test ("Desencolar" , heap_desencolar(heap)==cadena_3);
    print_test ("Verifico maximo" , heap_ver_max(heap)==cadena_2);
    print_test ("Desencolar" , heap_desencolar(heap)==cadena_2);
    print_test ("Verifico maximo" , heap_ver_max(heap)==cadena_1);
    print_test ("Desencolar" , heap_desencolar(heap)==cadena_1);


    /* Destruyo el heap */
    heap_destruir (heap , NULL);
    free (arreglo);
    printf ("El heap fue destruido\n");
}

static void prueba_heapsort (void){
    printf ("\nINICIO DE PRUEBAS HEAP-SORT\n");
    /* Defino los recursos a utilizar */
    char* cadena_1 = "A";
    char* cadena_2 = "B";
    char* cadena_3 = "C";
    char* cadena_4 = "D";
    void** arreglo = malloc (4*sizeof (char*));
    arreglo[0] = cadena_2; arreglo[1]=cadena_3; arreglo[2] = cadena_1; arreglo[3]=cadena_4;
    heap_sort (arreglo , 4 , comparar_cadenas);

    /* Inicio de pruebas */
    print_test ("Verifico elemento 1" , arreglo[0] == cadena_1);
    print_test ("Verifico elemento 2" , arreglo[1] == cadena_2);
    print_test ("Verifico elemento 3" , arreglo[2] == cadena_3);
    print_test ("Verifico elemento 4" , arreglo[3] == cadena_4);

    /* Librero el arreglo */
    free(arreglo);
    print_test ("El arreglo fue liberado" , true);
}


void pruebas_heap_estudiante(void){
    prueba_heap_vacio();
    prueba_heap_encolar_en_orden();
    prueba_heap_encolar_desordenado();
    prueba_heap_desencolar();
    prueba_heap_destruir_con_NULL ();
    prueba_heap_destruir_con_free ();
    prueba_heapify ();
    prueba_heapsort();
}