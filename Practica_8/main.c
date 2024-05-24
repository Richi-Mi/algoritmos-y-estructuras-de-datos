#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Practica 8. Suma de enteros muy largos
// Implementación de pilas dinamicas
typedef struct Nodo { 
    int value;
    struct Nodo *siguiente;
} Nodo;

typedef struct Stack {
    struct Nodo *inicio;
    int tope;
} Pila;

int isEmpty( Pila *myStack ) {
    return myStack -> tope == 0;
}

void push( Pila *myStack, int value ) {
    Nodo *aux = myStack -> inicio;

    // Creamos el nuevo Nodo.
    Nodo *nuevo = malloc( sizeof( Nodo ) );
    nuevo -> value = value;

    if( aux == NULL ) {
        nuevo -> siguiente = NULL;
        myStack -> inicio = nuevo;
    }
    else {
        nuevo -> siguiente = aux;
        myStack -> inicio = nuevo;
    }
    myStack -> tope++;
}
int pop( Pila *myStack ) {
    int uwu = -1;
    if( !isEmpty( myStack ) ) {
        Nodo *aux;
        
        aux = myStack -> inicio;
        uwu = aux -> value;

        myStack -> inicio = myStack -> inicio -> siguiente;

        free( aux ); 
        myStack -> tope--;
    }
    else {
        printf("La pila esta vacia\n");
    }
    return uwu;
}
void getNumber( Pila *myStack ) {
    char caracter;
    while( (caracter = getchar()) != '\n' ) {
        if( isdigit( caracter ) ) {
            push( myStack, atoi( &caracter ) );
        }
        else {
            printf("Escribe un numero valido animal :(");
            exit(0);
        }
    }
}
void showElements( Pila *myStack ) {
    if( !isEmpty( myStack ) ) {
        Nodo *aux = myStack -> inicio;
        while ( aux != NULL ) {
            printf("%d", aux -> value );
            aux = aux -> siguiente;
        } 
    }   
    else {
        printf("La pila esta vacia\n");
    }
}
void main() {
    // Leer los numeros grandes.
    Pila *numero1 = malloc( sizeof( Pila ) );
    Pila *numero2 = malloc( sizeof( Pila ) );

    printf("Ingrese el primer numero: ");
    getNumber( numero1 );
    
    printf("Ingrese el segundo numero: ");
    getNumber( numero2 );

    int aux = 0;

    Pila *resultado = (Pila*) malloc( sizeof( Pila ) );

    while( !isEmpty(numero1) && !isEmpty(numero2) ) {
        int res = pop( numero1 ) + pop( numero2 ) + aux;
        if( res > 9 ) {
            aux = 1;
            push( resultado, res - 10 );
        }
        else {
            aux = 0;
            push( resultado, res );
        }
    }
    
    while( !isEmpty(numero1) ) {
        int num = pop( numero1 ) + aux;
        aux = 0;
        push( resultado, num );
    }
    while( !isEmpty(numero2) ) {
        int num = pop( numero1 ) + aux;
        aux = 0;
        push( resultado, num );
    }
    printf("Resultado: \n");
    showElements( resultado );
}