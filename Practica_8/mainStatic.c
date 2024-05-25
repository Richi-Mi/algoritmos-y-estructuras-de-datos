#include<stdio.h>
#include<stdlib.h>

#define queueLenght 5
typedef struct Elemento {
    int valor;
} Element;

typedef struct Queue {
    int head;
    int tail;

    struct Elemento elementos[ queueLenght ];
} Cola;

int isEmpty( Cola *myQueue ) {
    if( myQueue -> head == myQueue -> tail ) 
        return 1;
    else 
        return 0;
}
int isFull( Cola *myQueue ) {
    if( myQueue -> head == myQueue -> tail + 1 || ( myQueue -> head = 1 && myQueue -> tail == queueLenght ) ) 
        return 1;
    else 
        return 0;
}
int enQueue( Cola *myQueue, int element ) {
    if( !isFull( myQueue ) ) {
        Element newElement;
        newElement.valor = element;
        myQueue -> elementos[ myQueue -> tail ] = newElement;

        if( myQueue -> tail == queueLenght ) {
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
Element deQueue( Cola *myQueue ) {
    Element x = myQueue -> elementos[ myQueue -> head ];
    if ( myQueue -> head == queueLenght ) {
        myQueue -> head = 1;
    } 
    else  {
        myQueue -> head++;
    }
    return x;
}

int main() {
    Cola myCola = { 0, 0, {} };
    int option, num;

    do {
        printf("***********************************\n");
        printf("*Implementación de colas estaticas*\n");
        printf("***********************************\n");
        printf("1. Encolar \n2. Desencolar\n3. Frente\n4. Vaciar cola\n0. Salir\n");
        scanf("%d", &option );

        switch ( option ) {
            case 1:
                if( !isFull( &myCola ) ) {
                    printf("Ingresa el elemento a insertar: ");
                    scanf("%d", &num );

                    enQueue( &myCola, num );

                    printf("*--------------------*\n");
                    printf("| Elemento Insertado |\n");
                    printf("*--------------------*\n");
                }
                else {
                    printf("xxxxxxxxxxxxxx\n");
                    printf("x Cola llena x\n");
                    printf("xxxxxxxxxxxxxx\n");
                }
                break;
            case 2:
                if( !isEmpty( &myCola ) ) {
                    Element deletedElement = deQueue(&myCola);

                    printf("*------------------------*\n");
                    printf("| Elemento Eliminado: %d |\n", deletedElement.valor);
                    printf("*------------------------*\n");
                }
                else {
                    printf("xxxxxxxxxxxxxx\n");
                    printf("x Cola vacia x\n");
                    printf("xxxxxxxxxxxxxx\n");   
                }
                break;
            case 3:
                if( !isEmpty( &myCola ) ) {
                    int firstElement = myCola.elementos[ myCola.head ].valor;

                    printf("*------------ --------*\n");
                    printf("| Primer Elemento: %d |\n", firstElement );
                    printf("*---------------------*\n");
                }
                else {
                    printf("xxxxxxxxxxxxxx\n");
                    printf("x Cola vacia x\n");
                    printf("xxxxxxxxxxxxxx\n");   
                }
                break;
            case 4:
                while ( !isEmpty( &myCola )) {
                    deQueue( &myCola );
                }
                printf("*--------------*\n");
                printf("| Cola vaciada |\n");
                printf("*--------------*\n");
                break;
            
            default:
                option = 0;
                break;
        }
    } while( option != 0 );
}