#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{

    int valor;
    struct Nodo *sig;

}Nodo;

void f(int *x){
    *x = 3;
}

void asingMemory(int **p){

    *p = (int*)malloc(sizeof(int));

}

//Apunrador doble
void agregar(Nodo **p, int x){

    Nodo *new = (Nodo*)malloc(sizeof(Nodo));

    new->valor = x;
    new->sig = NULL;

    if(*p == NULL){
        *p=new;
    }
    else{
        //aux -> Accede al valor al que apunta 'p' (dirección de estructura)
        Nodo *aux = *p;

        while (aux->sig != NULL){
            //aux apunta al siguiente NODO
            aux = aux->sig;
        }
        //Lo enlazamos como siguiente de 'aux'
        aux->sig = new;

    }

}

void mostrar(){



}

int main(){

    int x=10;
    //Modifica el valor de x
    f(&x);

    Nodo *p;


    agregar(&p,5);

    //mostrar();

    free(&p);

}