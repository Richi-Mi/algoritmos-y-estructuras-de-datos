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

/**
 *@param PAIIIIIIIIIIIIIIIIIIIIIIII
 * 
*/
void eliminarNodo( Nodo **inicio, Nodo **final, int valor ) {
    // Creamos el nodo a eliminar
    Nodo *aux = *inicio;
    Nodo *anterior = NULL;
    Nodo *siguiente = NULL;

    while( aux != NULL && aux -> value != valor ) {
        aux = aux -> siguiente;
    }
    if( aux != NULL ) {
        anterior = aux -> anterior;
        siguiente = aux -> siguiente;

        // Significa que es el primer elemento a eliminar.
        if( anterior == NULL ) {
            (*inicio) = aux -> siguiente;
            siguiente -> anterior = aux -> anterior;
        }
        // Significa que es el ultimo elemento a eliminar.
        if( siguiente == NULL ) {
            (*inicio) = aux -> anterior;
            anterior -> siguiente = aux -> siguiente;
        }
        if( anterior != NULL && siguiente != NULL ) {
            anterior -> siguiente = aux -> siguiente;
            siguiente -> anterior = aux -> anterior;
        }
        free( aux );
    }
}

int deleteNodo(Nodo **inicio, Nodo **final, int x){

    Nodo *aux = *inicio;
    Nodo *anterior, *siguiente;
    anterior = siguiente = NULL;

    //Recorer los nodos hasta encontrar el fin "NULL" o el valor a eliminar
    while(aux != NULL && aux->value != x)
        aux = aux->siguiente;
        
        //Inicializar "anterior y suiguiente" tras recorer los nodos
        if(aux != NULL){

            anterior = aux->anterior;
            siguiente = aux->siguiente;


        //Desenlazar primer elemento
        if(anterior == NULL){

            (*inicio) = aux->siguiente;
            siguiente->anterior = aux->anterior;

        }

        //Desenlazar último elemento
        if(siguiente == NULL){

            (*final) = aux->anterior;
            anterior->siguiente = aux->siguiente;

        }

        //Desenlazar elementos del medio
        if(anterior != NULL && siguiente != NULL){

            anterior->siguiente = aux->siguiente;
            siguiente->anterior = aux->anterior;

        }

        free(aux);

        }
        else{
            return 0;
        }

    return x;

}

void showNodo(Nodo *p){

    while( p != NULL){

        printf("%d ",p->value);
        p = p->anterior;

    }

}


void main( void ) {

    Nodo *p,*q;
    p = NULL;
    q = NULL;

    addElementToStart(&p,&q,1);
    
    addElementToStart(&p,&q,2);
    addElementToStart(&p,&q,3);
    addElementToStart(&p,&q,4);
    addElementToStart(&p,&q,5);
    addElementToStart(&p,&q,6);

    showNodo(q);

    eliminarNodo(&p,&q,5);

    showNodo(q);

}