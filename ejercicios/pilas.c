#include <stdio.h>

#define MAX_SIZE 5

typedef struct Pila {
    
    int values[ MAX_SIZE ];    
    int tope;

} Pila;

// Vaciamos Pila.
void anula( Pila *myPila ) {
    if( !vacia( myPila ) ) {
        myPila -> tope = 0;
        for( int i = 0; i < MAX_SIZE; i++ ) {
            myPila -> values[i] = 0;
        }
    }
}

int tope( Pila *myPila ) {
    return myPila -> values[ myPila -> tope ];
}
void pop( Pila *myPila ) {
    if( !vacia( myPila ) ) {
        myPila -> values[ myPila -> tope ] = 0;
        myPila -> tope--;
    }
}
void push( Pila *myPila, int element ) {
    if( myPila -> tope < MAX_SIZE ) { 
        myPila -> values[ myPila -> tope ] = element;
        myPila -> tope++;
    }
}
int vacia( Pila *myPila ) {
    return myPila -> tope == 0;
}

void main( void ) {
    Pila numbers = { { 0 }, 0 };


}