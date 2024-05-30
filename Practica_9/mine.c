#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo {

    int i;    
    int value;
    struct Nodo *siguiente;

}Nodo;

int isEmpty( Nodo *myStack ) {
    return myStack == NULL;
}

int isFull( Nodo *myStack , int max ){

    if(myStack -> i >= max)
        return 1;
    else
        return 0;

}

void enQueue(Nodo **myNode, int x){

    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->value = x;

    if( *myNode == NULL ) {
        nuevo -> siguiente = nuevo;
        *myNode = nuevo;
        nuevo -> i = 0;
    }
    else {
        Nodo *aux = *myNode;
        while( aux -> siguiente != *myNode ) {
            aux = aux -> siguiente;
        }
        nuevo -> siguiente = aux -> siguiente;
        aux -> siguiente = nuevo;
        nuevo -> i += 1;

    }
}

int deenQueue(Nodo **p){

    int v = (*p)->siguiente->value;

    if((*p)->siguiente == *p){
        free(*p);
        (*p) = NULL;
    }

    else{

        Nodo *aux = (*p)->siguiente;

        (*p)->siguiente = aux->siguiente;
        free(aux);

    }

    return v;

}


int main( void ) {
    
    int i,MAX,num;

    Nodo *cola = NULL;

    srand( time( NULL ) );

    // 1. Solicitar al usuario la cantidad de elementos en la cola
    printf("*---------------------------------------------------------*\n");
    printf("| Escriba la cantidad de elementos disponibles en la cola |\n");
    printf("*---------------------------------------------------------*\n");

    scanf("%d", &MAX );

    // 2. Inicializar la cola con valores aleatorios.
    printf("*--------------------*\n");
    printf("| Numeros en la cola |\n");
    printf("*--------------------*\n");

    for(i=0 ; i<MAX ; i++)
        enQueue(&cola,rand()%99+1);

    while(!isEmpty(cola))
        printf("%d ",deenQueue(&cola));

    // 3. Llamar a la función para inicializar el árbol e imprimir todos los valores en el arreglo.
    
    return 0;
}