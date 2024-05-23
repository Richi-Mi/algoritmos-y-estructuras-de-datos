#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//hola
typedef struct Queue {
    int value;

    struct Queue *siguiente;
} Queue;

void enQueue(Queue **myQueue, int element){
    Queue *nuevo = (Queue*) malloc(sizeof(Queue));
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
// Ta mal
int deQueue(Queue **myQueue){
    int value = (*myQueue) -> siguiente -> value;

    if( (*myQueue)->siguiente == *myQueue ){
        free(*myQueue);
        (*myQueue) = NULL;
    }
    else {
        Queue *aux = (*myQueue)->siguiente;

        (*myQueue)->siguiente = aux->siguiente;
        free(aux);
    }

    return value;
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
    Queue *numero1 = NULL;
    Queue *numero2 = NULL;

    printf("Ingrese el primer numero: ");
    getNumber( numero1 );
    
    printf("Ingrese el segundo numero: ");
    getNumber( numero2 );

    while( numero1 != NULL ) {
        printf("%d", deQueue( &numero1 ) );
    }
}