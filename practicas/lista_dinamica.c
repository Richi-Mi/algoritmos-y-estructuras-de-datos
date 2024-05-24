#include <stdio.h>
#include <stdlib.h>

// Implementación de listas dinamicas

typedef struct Nodo { 
    int value;
    struct Nodo *siguiente;
} Nodo;

int isEmpty( Nodo *node ) {
    return node == NULL;
}

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
    if( !isEmpty( node ) ) {
        Nodo *aux = node;
        while ( aux != NULL ) {
            printf("%d, ", aux -> value );
            aux = aux -> siguiente;
        } 
    }   
    else {
        printf("La lista esta vacia\n");
    }
}
void deleteElementByIndex( Nodo **node, int index ) {
    Nodo *aux = *node;
    Nodo *anterior;

    int i = 0;

    if( index ) {
        while( aux != NULL && i < index ) {
            anterior = aux;
            aux = aux -> siguiente;
            i++;
        }
        anterior -> siguiente = aux -> siguiente;
    }
    else {
        (*node) = (*node)->siguiente;
    }
    free( aux );
}
Nodo* searchElement( Nodo **node, int valueToSearch ) {
    Nodo *aux = *node;

    while( aux != NULL ) {
        if( aux -> value == valueToSearch ) {
            return aux;
        }
        aux = aux -> siguiente;
    }
    return NULL;
}
void deleteElementByValue( Nodo **node, int valueToSearch ) {
    Nodo *aux = *node;
    Nodo *anterior = NULL;

    if( aux -> value == valueToSearch ) {
        (*node) = (*node) -> siguiente;
    }
    else {
        while( aux -> value != valueToSearch && aux -> siguiente != NULL ) {
            anterior = aux;
            aux = aux -> siguiente;
        } 
        anterior -> siguiente = aux -> siguiente;
    }
    free( aux );
}
void liberarMemoria( Nodo **inicio ) {
    while( (*inicio) != NULL ) {
        Nodo *aux = *inicio;
        *inicio = (*inicio) -> siguiente;
        free( aux );
    }
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

    Nodo *element = searchElement( &node, 50 );
    if( element != NULL ) {
        printf("%d, \n", element -> value );
    }
    else {
        printf("No existe el elemento. \n");
    }
    // deleteElementByIndex( &node, 0 );
    deleteElementByValue( &node, 10 );

    showElements( node );

    liberarMemoria( &node );

    printf("\n");

    showElements( node );

}