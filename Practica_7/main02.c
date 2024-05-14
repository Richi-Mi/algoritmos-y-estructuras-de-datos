#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

typedef struct Pila {
    int tope;
    char values[MAX];
} Pila;

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

    int sizeExpression = 0, i, ep = 0, nc = 0;

    printf("Ingrese una expresión matematica en infijo: \n");

    // Leer la expresión infija
    while ((caracter = getchar()) != '\n') {
        expressionInfija[sizeExpression] = caracter;
        sizeExpression++;
    }
    expressionInfija[sizeExpression] = '\0';

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

    free(operadores);
    free(numberC);

    for (i = 0; i < ep; i++) {
        if (expressionPosfija[i].type == 1) {
            printf("%d ", expressionPosfija[i].valueI);
        } else {
            printf("%c ", expressionPosfija[i].valueC);
        }
    }
    free(expressionPosfija);
    return 0;
}
