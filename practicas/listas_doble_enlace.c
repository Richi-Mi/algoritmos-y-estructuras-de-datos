#include <stdlib.h>
#include <stdio.h>

// Implementación de listas dinamicas circulares

typedef struct Nodo { 
    int value;
    struct Nodo *anterior;
    struct Nodo *siguiente;
} Nodo;

void addElementToEnd( Nodo **inicio, Nodo **final, int value ) {
    // Creación del nodo a agregar.
    Nodo *nuevo = malloc( sizeof( Nodo ) );
    nuevo -> value = value;
    nuevo -> anterior = NULL;
    nuevo -> siguiente = NULL;

    if( *final == NULL ) {
        *inicio = nuevo;
        *final  = nuevo; 
    }
    else {
        Nodo *aux = *final;
        nuevo -> anterior = aux;
        aux -> siguiente = nuevo;

        *inicio = nuevo;
    }
}

void addElementToStart( Nodo **inicio, Nodo **final, int value ) {
    // Creación del nodo a agregar.
    Nodo *nuevo = malloc( sizeof( Nodo ) );
    nuevo -> value = value;
    nuevo -> anterior = NULL;
    nuevo -> siguiente = NULL;

    if( *inicio == NULL ) {
        *inicio = nuevo;
        *final  = nuevo; 
    }
    else {
        Nodo *aux = *inicio;
        nuevo -> siguiente = aux;
        aux -> anterior = nuevo;

        *inicio = nuevo;
    }
}

void main( void ) {

}