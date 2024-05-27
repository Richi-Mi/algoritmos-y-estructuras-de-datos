#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo {
    int value;

    struct Nodo *siguiente;
} Nodo;

typedef struct Queue {
    struct Nodo *inicio;

    int i;
} Queue;

void enQueue( Queue *myQueue, int element ) {
    Nodo *aux = myQueue -> inicio;

    
}

int main( void ) {
    Queue cola = { 0, NULL };
    int MAX;

    srand( time( NULL ) );

    // 1. Solicitar al usuario la cantidad de elementos en la cola
    printf("*---------------------------------------------------------*\n");
    printf("| Escriba la cantidad de elementos disponibles en la cola |\n");
    printf("*---------------------------------------------------------*\n");

    scanf("%d", &MAX );

    // 2. Inicializar la cola con valores aleatorios.
    
    return 0;
}