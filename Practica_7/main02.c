#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

typedef struct Pila {
    int tope;
    char values[MAX];
} Pila;
typedef struct PilaNumeros {
    int tope;
    char values[MAX];
} PilaNumeros;

typedef struct Lista {
    int type;
    int valueI;
    char valueC;
} Lista;

int vacia(Pila *myPila) {
    return myPila->tope == 0;
}

void anula(Pila *myPila) {
    if (!vacia(myPila)) {
        myPila->tope = 0;
        for (int i = 0; i < MAX; i++) {
            myPila->values[i] = 0;
        }
    }
}

char tope(Pila *myPila) {
    if (!vacia(myPila)) {
        return myPila->values[myPila->tope - 1];
    }
    return '\0'; // Devuelve un carácter nulo si la pila está vacía
}

int pop(Pila *myPila) {
    if (!vacia(myPila)) {
        myPila->tope--;
        return myPila->values[myPila->tope];
    } else {
        return '\0'; // Devuelve un carácter nulo si la pila está vacía
    }
}

void push(Pila *myPila, char element) {
    if (myPila->tope < MAX) {
        myPila->values[myPila->tope] = element;
        myPila->tope++;
    }
}
int vaciaNumeros(PilaNumeros *myPila) {
    return myPila->tope == 0;
}

void anulaNumeros(PilaNumeros *myPila) {
    if (!vaciaNumeros(myPila)) {
        myPila->tope = 0;
        for (int i = 0; i < MAX; i++) {
            myPila->values[i] = 0;
        }
    }
}

int topeNumeros(PilaNumeros *myPila) {
    if (!vaciaNumeros(myPila)) {
        return myPila->values[myPila->tope - 1];
    }
    return 0; // Devuelve un carácter nulo si la pila está vacía
}

int popNumeros(PilaNumeros *myPila) {
    if (!vaciaNumeros(myPila)) {
        myPila->tope--;
        return myPila->values[myPila->tope];
    } else {
        return 0; // Devuelve un carácter nulo si la pila está vacía
    }
}

void pushNumeros(PilaNumeros *myPila, int element) {
    if (myPila->tope < MAX) {
        myPila->values[myPila->tope] = element;
        myPila->tope++;
    }
}

int ordenPrecedencia(char caracter) {
    switch (caracter) {
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

int main(void) {
    char caracter, expressionInfija[MAX];
    char *numberC = calloc(20, sizeof(char));

    int sizeExpression = 0, i, ep = 0, nc = 0, j, pa = 0, pc = 0; 

    printf("Ingrese una expresión matematica en infijo: \n");

    // Leer la expresión infija
    while ((caracter = getchar()) != '\n') {
        expressionInfija[sizeExpression] = caracter;

        if( caracter == '(') pa++;
        if( caracter == ')') pc++;

        sizeExpression++;
    }
    expressionInfija[sizeExpression] = '\0';
    if( pa != pc ) {
        printf("Error en la expresion");
        exit(0);
    }

    Lista *expressionPosfija = calloc(sizeExpression, sizeof(Lista));
    Pila *operadores = malloc(sizeof(Pila));

    for (i = 0; i < sizeExpression; i++) {
        // Agregamos los numeros escritos a una cadena.
        if (isdigit(expressionInfija[i])) {
            numberC[nc] = expressionInfija[i];
            nc++;
        } else {
            if (nc > 0) {
                expressionPosfija[ep].type = 1;
                expressionPosfija[ep].valueI = atoi(numberC);
                for( j = 0; j < nc; j++) {
                    numberC[j] = ' ';
                }
                ep++;
                nc = 0;
            }

            if (expressionInfija[i] == '(' || vacia(operadores) || ordenPrecedencia(tope(operadores)) < ordenPrecedencia(expressionInfija[i])) {
                push(operadores, expressionInfija[i]);
            } else if (expressionInfija[i] == ')') {
                char operator = ' ';
                do {
                    operator = pop(operadores);

                    if( operator == '(')
                        break;
                    expressionPosfija[ep].type = 2;
                    expressionPosfija[ep].valueC = operator;

                    ep++;
                } while (operator != '(');
            } else {
                while (!vacia(operadores) && ordenPrecedencia(tope(operadores)) >= ordenPrecedencia(expressionInfija[i])) {
                    char aux = pop(operadores);

                    expressionPosfija[ep].type = 2;
                    expressionPosfija[ep].valueC = aux;

                    ep++;
                }

                push(operadores, expressionInfija[i]);
            }
        }
    }

    if (nc > 0) {
        expressionPosfija[ep].type = 1;
        expressionPosfija[ep].valueI = atoi(numberC);
        ep++;
    }

    while (!vacia(operadores)) {
        expressionPosfija[ep].type = 2;
        expressionPosfija[ep].valueC = pop(operadores);
        ep++;
    }

    for (i = 0; i < ep; i++) {
        if (expressionPosfija[i].type == 1) {
            printf("%d ", expressionPosfija[i].valueI);
        } else {
            printf("%c ", expressionPosfija[i].valueC);
        }
    }

    PilaNumeros *numeros = malloc( sizeof( Pila ) );
    for (i = 0; i < ep; i++) {
        if (expressionPosfija[i].type == 1) {
            pushNumeros( numeros, expressionPosfija[i].valueI );
        } else {
            int n2 = popNumeros( numeros );
            int n1 = popNumeros( numeros );
            int r;

            switch( expressionPosfija[i].valueC ) {
                case '+':
                    r = n1 + n2;
                    break;
                case '-':
                    r = n1 - n2;
                    break;
                case '*':
                    r = n1 * n2;
                    break;
                case '/':
                    r = n1 / n2;
                    break;
            }

            pushNumeros( numeros, r );
        }
    }
    int res = popNumeros( numeros );
    printf("\n - Resultado: %d", res );
    
    free(expressionPosfija);
    free(operadores);
    free(numberC);
    free(numeros);

    return 0;
}
