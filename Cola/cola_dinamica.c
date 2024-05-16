#include<stdio.h>
#include<stdlib.h>

typedef struct Cola{
    
    int valor;
    struct Cola *sig;


}Cola;

void enqueue(Cola **p, int x){

    Cola *nuevo = (Cola*)malloc(sizeof(Cola));
    nuevo->valor = x;

    if(*p = NULL)
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

    enqueue(&p,5);





}