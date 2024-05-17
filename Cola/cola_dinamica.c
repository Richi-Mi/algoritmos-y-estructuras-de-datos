#include<stdio.h>
#include<stdlib.h>

typedef struct Cola{
    
    int valor;
    struct Cola *sig;


}Cola;

void enqueue(Cola **p, int x){

    Cola *nuevo = (Cola*)malloc(sizeof(Cola));
    nuevo->valor = x;

    if(*p == NULL)
        nuevo->sig = nuevo;
    else{
        nuevo->sig = (*p)->sig;
        (*p)->sig = nuevo;
    }

    *p = nuevo;


}

int deenqueue(Cola **p){

    int v = (*p)->sig->valor;

    if((*p)->sig == *p){
        free(*p);
        (*p) = NULL;
    }

    else{

        Cola *aux = (*p)->sig;

        (*p)->sig = aux->sig;
        free(aux);

    }

    return v;

}


int main(){

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