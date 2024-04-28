//Lista restringida

#include<stdio.h>
#include<stdlib.h>

#define Max 3


//Comprobar si pila esta llena
int full(int tope){

    if(tope == Max-1)
        return -1;
    
    else
        return 0;

}

//Comprobar si pila esta vacia
int empty(int tope){

    if(tope == -1)
        return 1;
    
    else
        return 0;

}

//Agregar valores en una pila
void push(int pila[], int *tope, int v){

    if(!full(*tope))
        pila[(*tope)++] = v;

    else
        printf("No es posible agregar un elemento\n");

}

//Quitar valor en una pila
int pop(int pila[], int *tope){

    if(!empty(*tope))
        return (pila[(*tope)--]); //Envia el valor del tope y después decrementa 'tope'

    else
        printf("La lista esta vacia");

}

int main(){

    int tope = -1;
    int pila[Max];
    int valor;

    push(pila,&tope,1);
    push(pila,&tope,2);
    push(pila,&tope,3);

    while(!empty(tope)){

        valor = pop(pila,&tope);
        printf("%i\n",valor);

    }

}