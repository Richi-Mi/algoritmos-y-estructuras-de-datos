#include<stdio.h>
#include<stdlib.h>

#define Max 5

typedef struct Pila {
    
    int values[Max];    
    struct Pila *sig;

}Pila;

/*

int empty( Pila *myPila ) {
    return (myPila -> tope == 0);
}

void anula( Pila *myPila ) {
    
    if( !empty( myPila ) ) {
        myPila -> tope = 0;
        
        for( int i = 0; i < Max; i++ )
            myPila -> values[i] = 0;
        
    }
}

int tope( Pila *myPila ) {
    return myPila -> values[ myPila -> tope ];
}

//Quitar valor
void pop( Pila *myPila ) {
    
    if( !empty( myPila ) ) {
        myPila -> values[ myPila -> tope ] = 0;
        myPila -> tope--;
    }

}

//Agregar valores
void push( Pila *myPila, int element ) {
    
    (Nodo *)malloc(sizeof(Nodo))

    if( muPila != NULL)
    if( myPila -> tope < Max ){ 
        myPila -> values[ myPila -> tope ] = element;
        myPila -> tope++;
    }
}

*/

int main(){

    int num, top;
    Pila *stack = NULL;
    
    

    printf("Pila tope :%d\n");

}