#include <stdio.h>
#include <stdlib.h>

#define MAX 260

typedef struct Pila {
    int tope;

    char operatorValue;

    struct Pila *siguiente;
} Pila;

// Funciones de la Pila.
int empty( Pila *myPila ) {
    return myPila -> tope == 0;
}
void destroy( Pila *myPila ) {
    if( !empty( myPila ) ) {

        free( myPila );

        myPila = malloc( sizeof( Pila ) );
        myPila -> tope = 0;
        myPila -> operatorValue = ' ';

        myPila -> siguiente = NULL;
    }
}
Pila* tope( Pila *myPila ) {
    int i;
    for( i = 0; i < myPila -> tope; i++ ) {
        myPila = myPila -> siguiente;
    }
    return myPila;
}
void pop( Pila *myPila ) {
    int i;
    if( !empty( myPila ) ) {
        myPila -> tope--;
        for( i = 0; i < myPila -> tope; i++ ) {
            myPila = myPila -> siguiente;
        }
        myPila -> siguiente = NULL;
    }
}
void push( Pila *myPila, char element ) {
    int i;
    
    Pila next;
    next.operatorValue = element;
    next.siguiente = NULL;

    
}

void main( void ) {
    char caracter, expressionInfija[255];
    int i = 0;
    Pila *pila;

    pila = malloc( sizeof( Pila ) );
    pila -> tope = 0;
    pila -> operatorValue = ' ';
    
    printf("Ingrese una expresión: \n");

    while ( ( caracter = getchar() ) != '\n' ) {
        expressionInfija[i++] = caracter;
    }
    expressionInfija[i] = '\0';

    printf("%s", expressionInfija );
}