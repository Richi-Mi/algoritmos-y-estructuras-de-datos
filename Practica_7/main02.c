#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct Pila {

    int tope;
    char values[ MAX ];    

} Pila;

typedef struct Lista {
    int type;

    int valueI;
    char valueC;
} Lista;

int vacia( Pila *myPila ) {
    return myPila -> tope == 0;
}

// Vaciamos Pila.
void anula( Pila *myPila ) {
    if( !vacia( myPila ) ) {
        myPila -> tope = 0;
        for( int i = 0; i < MAX; i++ ) {
            myPila -> values[i] = 0;
        }
    }
}

char tope( Pila *myPila ) {
    return myPila -> values[ myPila -> tope ];
}
int pop( Pila *myPila ) {
    if( !vacia( myPila ) ) {
        myPila -> values[ myPila -> tope ] = 0;
        myPila -> tope--;

        return 1;
    }
    else {
        return 0;
    }
}
void push( Pila *myPila, char element ) {
    if( myPila -> tope < MAX ) { 
        myPila -> values[ myPila -> tope ] = element;
        myPila -> tope++;
    }
}
int ordenPrecedencia( char caracter ) {
    switch ( caracter ) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}


void main( void ) {
    char caracter, expressionInfija[255];
    char *numberC = calloc( 20, sizeof( char ) );

    int sizeExpression = 0, i, ep = 0, nc = 0;
    
    printf("Ingrese una expresión matematica en infijo: \n");

    // Leer la expresión infija
    while ( ( caracter = getchar() ) != '\n' ) {
        expressionInfija[ sizeExpression ] = caracter;
        sizeExpression++;
    }
    expressionInfija[ sizeExpression ] = '\0';

    Lista *expressionPosfija = calloc( sizeExpression, sizeof( Lista )); 
    Pila *operadores = malloc( sizeof( Pila ) );

    for( i = 0; i < sizeExpression; i++ ) {
        // Agregamos los numeros escritos a una cadena.
        if( isdigit( expressionInfija[i] ) ) {
            numberC[ nc ] = expressionInfija[i];
            nc++;
        }
        else {
            expressionPosfija[ ep ].type = 1;
            expressionPosfija[ ep ].valueI = atoi( numberC );

            ep++;

            nc = 0; 

            free( numberC );  
            numberC = calloc( 20, sizeof( char ) );
            
            // Orden de precedencia. 
            if( vacia( operadores ) || ordenPrecedencia( tope( operadores ) ) < ordenPrecedencia( expressionInfija[i] ) ) {
                push( operadores, expressionInfija[i] );
            }
            else {
                char aux = tope( operadores );
                pop( operadores );

                push( operadores, expressionInfija[i] );
                expressionInfija[ep] = aux;

                expressionPosfija[ ep ].type = 2;
                expressionPosfija[ ep ].valueI = aux;

                ep++;
            }
        }
    }
    
    expressionPosfija[ep].type = 1;
    expressionPosfija[ep].valueI = atoi(numberC);

    ep++;

    while ( pop( operadores ) ) {
        expressionPosfija[ ep ].type = 2;
        expressionPosfija[ ep ].valueC = tope( operadores );
        ep++;
    }
    free( operadores );
    for( i = 0; i < ep; i++ ) {
        if( expressionPosfija[i].type == 1 ) {
            printf("%d ", expressionPosfija[i].valueI );
        }
        else {
            printf("%c ", expressionPosfija[i].valueC );
        }
    }
    free( expressionPosfija );
}