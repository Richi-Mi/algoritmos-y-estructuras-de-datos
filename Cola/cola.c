#include<stdio.h>
#include<stdlib.h>

//ESTÁTICA
//puntero en cabeza y cola
//Guardar n-1 elementos

#define lenghtQ 12

typedef struct Cola{

    int head;
    int tail;
    int Q[lenghtQ];

}Cola;

//cola vacia --> head = tail

int empty(int head, int tail){

    return (head == tail);
}

//cola llena --> head = tail+1 ; head = 1 ; tail = lenght_Cola

int full(int head, int tail){

    if((head == 1 && tail == lenghtQ-1) || (head == tail+1))
        return 1;
    else
        return 0;

}

//Agregar elemento a una cola
void enqueue(Cola cola, int x){

    cola.Q[cola.tail] = x;

    if(cola.tail == lenghtQ)
        cola.tail = 1;
    else{
        cola.tail++;
    }
}

//Quitar elementos de una cola
int dequeue(Cola cola){

    int v;

    if(empty(cola.head,cola.tail))
        return 0;

    v = cola.head;

    if(cola.head == lenghtQ)
        cola.head = 1;
    else
        cola.head++;

    return v;   //El return es solo para saber el valor eliminado, por lo que podemos quitar el return si no nos interesa

}

int main(){

    Cola *p;

    enqueue(*p,1);
    enqueue(*p,2);
    enqueue(*p,3);

    printf("\tValor fuera cola: %d\n",dequeue(*p));

}