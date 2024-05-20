#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//hola
typedef struct Queue {
    int value;

    struct Queue *siguiente;
} Queue;

void enQueue(Queue **myQueue, int element){

    Queue *nuevo = (Queue*)malloc(sizeof(Queue));
    nuevo -> value = element;

    if( *myQueue == NULL ) {
        nuevo -> siguiente = nuevo;
        *myQueue = nuevo;
    }
    else {
        Queue *aux = *myQueue;
        while( aux -> siguiente != *myQueue ) {
            aux = aux -> siguiente;
        }
        nuevo -> siguiente = aux -> siguiente;
        aux -> siguiente = nuevo;

    }
}

// Programa 2. Suma de enteros largos 

void getNumber( Queue *numero ) {
    char caracter;
    // Leer la numero
    while ((caracter = getchar()) != '\n') {
        if( !isdigit( caracter ) ) {
            printf("Ingrese solo numeros\n");
            exit(1);     
        }
        enQueue( &numero, atoi( &caracter ) );
    }
}

void main() {
    Queue *numero1 = malloc( sizeof( Queue ) );
    Queue *numero2 = malloc( sizeof( Queue ) );

    numero1 = NULL;
    numero2 = NULL;

    printf("Ingrese el primer numero: ");
    getNumber( numero1 );
    printf("Ingrese el segundo numero: ");
    getNumber( numero2 );


    while( numero1 -> siguiente != NULL ) {
        printf("%d", numero1 -> value );
        numero1 = numero1 -> siguiente;
    }
}