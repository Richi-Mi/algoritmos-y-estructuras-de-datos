#include <stdio.h>
#include <stdlib.h>

// Implementación de listas dinamicas

typedef struct Nodo { 
    int value;
    struct Nodo *siguiente;
} Nodo;

void addElement( Nodo **node, int valor ) {
    // Creación del nodo a agregar.
    Nodo *nuevo = malloc( sizeof( Nodo ) );
    nuevo -> value = valor;
    nuevo -> siguiente = NULL;

    if( (*node) == NULL ) {
        (*node) = nuevo;
    }
    else {
        Nodo *aux = (*node);
        while( aux -> siguiente != NULL ) {
            aux = aux -> siguiente;
        }
        aux -> siguiente = nuevo;
    }
}
void showElements( Nodo *node ) {
    Nodo *aux = node;
    while ( aux != NULL ) {
        printf("%d, ", aux -> value );
        aux = aux -> siguiente;
    }    
}
void deleteElementByIndex( Nodo **node, int index ) {
    Nodo *aux = *node;
    Nodo *left;

    int i = 0;

    if( index ) {
        while( aux != NULL && i < index ) {
            left = aux;
            aux = aux -> siguiente;
            i++;
        }
        left -> siguiente = aux -> siguiente;
    }
    else {
        (*node) = (*node)->siguiente;
    }
    free( aux );
}
void deleteElementByValue() {

}

void main( void  ) {
    Nodo *node = NULL;

    addElement( &node, 10 );
    addElement( &node, 25 );
    addElement( &node, 30 );
    addElement( &node, 40 );
    addElement( &node, 50 );

    showElements( node );

    printf("\n");
    deleteElementByIndex( &node, 0 );

    printf("SEXO?\n");
    showElements( node );

}