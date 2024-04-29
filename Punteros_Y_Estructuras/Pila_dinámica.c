//Pila dinámica

#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
    
    int valor;
    struct Nodo *sig;

}Nodo;

//Agregar elemento a Pila
void push( Nodo **p, int v){

    Nodo *new = (Nodo *)malloc(sizeof(Nodo));

    new->valor = v;
    //new->sig = NULL;

    new->sig = *p;
    *p = new;

}

//Quitar un elemento de Pila
void pop( Nodo **p ){

    //Comprobar que la lista no esté vacia
    if(!empty(*p)){

        Nodo *aux = *p;
        int retorno = aux->valor;
        *p = aux->sig;
        free(aux);
        return retorno;

    }

}

int empty(Nodo *p){



}


int main(){

    Nodo *pila = NULL;

}