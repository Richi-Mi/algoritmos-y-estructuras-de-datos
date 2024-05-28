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
    // Creacion del nuevo nodo
    Nodo *nuevo = malloc( sizeof( Nodo ) );
    nuevo -> value = element;
    // Inicia en el primer elemento
    if( myQueue -> inicio == NULL ) {
        nuevo -> siguiente = nuevo;
        myQueue -> inicio = nuevo;
    }
    // Ya hay elementos
    else {
        Nodo *aux = myQueue -> inicio;
        nuevo -> siguiente = aux -> siguiente;
        aux -> siguiente = nuevo;

        myQueue -> inicio = nuevo;
    }
}
int deQueue( Queue *myQueue ) {
    // Nodo *elementToDeQueue = myQueue -> inicio -> siguiente;
    int element = 0;
    if( myQueue -> inicio == NULL )
        return element; // Comprobamos que no este vacia 

    // Si solo hay un elemento.
    if( myQueue -> inicio == myQueue -> inicio -> siguiente ) {
        element = myQueue -> inicio -> value;

        free( myQueue -> inicio );
        myQueue -> inicio = NULL;

        return element;
    }
    else {
        Nodo *aux = myQueue -> inicio -> siguiente;
        element = aux -> value;

        myQueue -> inicio -> siguiente = aux -> siguiente; 
        free( aux );

        return element;
    }

}
void showElements( Queue *myQueue ) {
    Nodo *aux = myQueue -> inicio;
    if( aux != NULL ) {
        if ( aux -> siguiente == myQueue -> inicio ) {
            printf("%d", myQueue -> inicio -> value );
        }
        else {         
            while ( aux -> siguiente != myQueue -> inicio ) {
                printf("%d, ", aux -> value );
                aux = aux -> siguiente;

                if( aux -> siguiente == myQueue -> inicio ) {
                   printf("%d", aux -> value );
                }
            }     
        }
    }
    else {
        printf("Cola Vacia \n");
    }
}
int main( void ) {
    Queue cola = { 0 };
    srand( time( NULL ) );

    // 2. Inicializar la cola con valores aleatorios

    enQueue(&cola, 10);
    enQueue(&cola, 20);
    enQueue(&cola, 30);
    enQueue(&cola, 40);
    enQueue(&cola, 50);
    enQueue(&cola, 60);

    showElements( &cola );
    printf("\n");

    deQueue( &cola );
    deQueue( &cola );
    deQueue( &cola );

    showElements( &cola );

    return 0;
}