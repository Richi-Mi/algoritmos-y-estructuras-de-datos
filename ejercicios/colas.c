#include <stdlib.h>
#include <stdio.h>

//// Implementacion estatica

#define MAX_SIZE 5

typedef struct Persona {
    char nombre[255];
    char rfc[13];
} Persona;

typedef struct Cola {

    int head;
    int tail;

    int personas[MAX_SIZE];

} Cola;

int isEmpty( Cola *myQueue ) {
    if( myQueue -> head == myQueue -> tail ) 
        return 1;
    else 
        return 0;
}
int isFull( Cola *myQueue ) {
    if( myQueue -> head == myQueue -> tail + 1 || ( myQueue -> head = 1 && myQueue -> tail == MAX_SIZE ) ) 
        return 1;
    else 
        return 0;
}
int enQueue( Cola *myQueue, int element ) {
    if( !isFull( myQueue ) ) {
        myQueue -> personas[ myQueue -> tail ] = element;

        if( myQueue -> tail == MAX_SIZE ) {
            myQueue -> tail = 1;
        } 
        else {
            myQueue -> tail = myQueue -> tail + 1;
        }
        return 1;
    }
    else 
        return 0;
}
int deQueue( Cola *myQueue ) {
    int x = myQueue -> personas[ myQueue -> head ];
    if ( myQueue -> head == MAX_SIZE ) {
        myQueue -> head = 1;
    } 
    else  {
        myQueue -> head++;
    }
    return x;
}


void main( void ) {
    printf("Hello, welcome to the queue\n");
    Cola myCola = { 0, 0, { 0 } };
    
    int i = 0;

    if( enQueue( &myCola, 10 ) ) {
        printf("Elemento en la cola");
    }
    enQueue( &myCola, 20 );
    enQueue( &myCola, 35 );
    enQueue( &myCola, 15 );
    enQueue( &myCola, 34 );
    if( !enQueue( &myCola, 35 ) ) {
        printf("\n Cola esta llenas");
    }


    return;
}