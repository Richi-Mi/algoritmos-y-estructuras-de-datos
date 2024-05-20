#include<stdio.h>
#include<stdlib.h>

typedef struct Cola {    

    int valor;
    struct Cola *siguiente;

} Cola;

void enqueue(Cola **myNode, int x){

    Cola *nuevo = (Cola*)malloc(sizeof(Cola));
    nuevo->valor = x;

    if( *myNode == NULL ) {
        nuevo -> siguiente = nuevo;
        *myNode = nuevo;
    }
    else {
        Cola *aux = *myNode;
        while( aux -> siguiente != *myNode ) {
            aux = aux -> siguiente;
        }
        nuevo -> siguiente = aux -> siguiente;
        aux -> siguiente = nuevo;

    }
}
int deenqueue(Cola **p){

    int v = (*p)->siguiente->valor;

    if((*p)->siguiente == *p){
        free(*p);
        (*p) = NULL;
    }

    else{

        Cola *aux = (*p)->siguiente;

        (*p)->siguiente = aux->siguiente;
        free(aux);

    }

    return v;

}

int main() {
    
    printf("Colas: Implementación Dinamica\n");
    Cola *p = NULL;

    //encolamos vario elementos
    enqueue(&p,1);
    enqueue(&p,2);
    enqueue(&p,3);

    //desencolamos un elemento (sale el 1)
    printf("%d\n",deenqueue(&p));

    //desencolamos un elemento (sale el 2)
    printf("%d\n",deenqueue(&p));

    //encolamos más elementos
    enqueue(&p,4);
    enqueue(&p,5);
    enqueue(&p,6);

    //desencolamos un elemento (sale el 3)
    printf("%d\n",deenqueue(&p));

    //desencolamos mientras queden elementos en la cola
    while(p != NULL)
        printf("%d\n",deenqueue(&p));

}