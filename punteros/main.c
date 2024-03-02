#include <stdlib.h>
#include <stdio.h>

void main() {
    // Un puntero es una variable que apunta a una dirección en memoria RAM.
    int num = 10, i;
    int *p; // Puntero
    p = &num; // Dirección a la que apunta.

    printf("Valor numerico de la variable: %d \n", num );
    printf("Direccón en memoria de la variable: %p\n", &num );
    printf("Direccón en memoria del puntero: %p\n", p );
    printf("Valor numerico del puntero: %d\n", *p );

    // USO de Malloc.
    int *a;
    a = malloc( sizeof(int) );
    *a = 2;

    printf("%d \n", *a);
    free(a);

    // USO de Calloc.
    int *arr;
    arr = calloc( 5, sizeof(int) );

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    for( i = 0; i < 5; i++ ) {
        printf( "%d, ", arr[i] );
    }
    printf("\n");
    
    // Esta función se utiliza para cambiar el tamaño de un bloque de memoria previamente asignado. Toma dos argumentos: un puntero al bloque de memoria existente y el nuevo tamaño deseado en bytes. Devuelve un puntero al nuevo bloque de memoria asignado, o NULL si falla. Es importante tener en cuenta que si la asignación falla, la memoria original aún se conserva y no se modifica.

    arr = realloc( arr, 10 * sizeof( int ));

    arr[5] = 6;
    arr[6] = 7;
    arr[7] = 8;
    arr[8] = 9;
    arr[9] = 10;

    for( i = 0; i < 10; i++ ) {
        printf( "%d, ", arr[i] );
    }
    printf("\n");
}