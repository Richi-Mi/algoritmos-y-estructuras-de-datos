#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

// Implementación de listas dinamicas circulares

typedef struct Nodo { 
    int value;
    struct Nodo *siguiente;
} Nodo;
/**
 * Agrega un elemento a la lista dinamica
 * @param node .- Elemento de Lista dinamica
 * @param valor -- Valor del nodo
*/
void addElement( Nodo **node, int valor ) {
    // Creación del nodo a agregar.
    Nodo *nuevo = malloc( sizeof( Nodo ) );
    nuevo -> value = valor;

    // Verificamos que sea el primer elemento
    if( (*node) == NULL ) {
        nuevo -> siguiente = nuevo;
        (*node) = nuevo;
    }
    else {
        Nodo *aux = (*node);
        while( aux -> siguiente != (*node) ) {
            aux = aux -> siguiente;
        }
        nuevo -> siguiente = (*node);
        aux -> siguiente = nuevo;
    }
}
/**
 * @param node .- Elemento de Lista dinamica
*/
void showElements( Nodo *node ) {
    Nodo *aux = node;

    while ( aux -> siguiente != node ) {
        printf("%d, ", aux -> value );
        aux = aux -> siguiente;

        if(aux -> siguiente == node){
            printf("%d, ", aux -> value );
        }
    }    
}
void main() {
    printf("Hola \n");
    Nodo *node = NULL;

    addElement( &node, 10 );
    addElement( &node, 20 );
    addElement( &node, 30 );
    addElement( &node, 40 );

    
    showElements( node );
}