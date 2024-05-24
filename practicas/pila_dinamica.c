#include <stdio.h>
#include <stdlib.h>

// TODO: Programar push y pop

// Implementación de pilas dinamicas
typedef struct Nodo { 
    int value;
    struct Nodo *siguiente;
} Nodo;

typedef struct Pila {
    struct Nodo *inicio;
    int tope;
} Pila;
/**
 * @param Pila Pila a evaluar.
 * Evalua si la pila esta vacia o no
 * @return 0 o 1
*/
int isEmpty( Pila *myStack ) {
    return myStack -> tope == 0;
}
void push( Pila *myStack, int value ) {
    Nodo *aux = myStack -> inicio;

    // Creamos el nuevo Nodo.
    Nodo *nuevo = malloc( sizeof( Nodo ) );
    nuevo -> value = value;

    if( aux == NULL ) {
        nuevo -> siguiente = NULL;
        myStack -> inicio = nuevo;
    }
    else {
        nuevo -> siguiente = aux;
        myStack -> inicio = nuevo;
    }
    myStack -> tope++;
}
void pop( Pila *myStack ) {
    if( !isEmpty( myStack ) ) {
        Nodo *aux;
        
        aux = myStack -> inicio;

        myStack -> inicio = myStack -> inicio -> siguiente;

        free( aux );   
    }
    else {
        printf("La pila esta vacia\n");
    }
}
void showElements( Pila *myStack ) {
    if( !isEmpty( myStack ) ) {
        Nodo *aux = myStack -> inicio;
        while ( aux != NULL ) {
            printf("%d, ", aux -> value );
            aux = aux -> siguiente;
        } 
    }   
    else {
        printf("La pila esta vacia\n");
    }
}
void liberarMemoria( Pila *myStack ) {
    Nodo *inicio = myStack -> inicio;
    while( inicio != NULL ) {
        Nodo *aux = inicio;
        inicio = inicio -> siguiente;

        free( aux );
    }
    myStack -> tope = 0;
}
void main( void ) {
    printf("Pilas dinamicas\n");
    // Inicializamos las variables
    Pila *myStack = malloc( sizeof(Pila) );
    myStack -> tope = 0;
    myStack -> inicio = NULL;

    showElements( myStack );

    push( myStack, 10 );
    push( myStack, 30 );
    push( myStack, 50 );
    push( myStack, 40 );
    push( myStack, 36 );
    push( myStack, 57 );

    showElements( myStack );

    printf("\n");

    pop(myStack);
    pop( myStack );

    showElements( myStack );

    liberarMemoria( myStack );
}