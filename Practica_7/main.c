#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 50

typedef struct Pila {
    int tope;
    char values[MAX];
} Pila;

typedef struct PilaNumeros {
    int tope;
    int values[MAX];
} PilaNumeros;

typedef struct Lista {
    int type; // 1 para números, 2 para operadores
    int valueI;
    char valueC;
} Lista;

// Funciones para la pila de operadores
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

char pop(Pila *myPila) {
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

// Funciones para la pila de números
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
    return 0; // Devuelve 0 si la pila está vacía
}

int popNumeros(PilaNumeros *myPila) {
    if (!vaciaNumeros(myPila)) {
        myPila->tope--;
        return myPila->values[myPila->tope];
    } else {
        return 0; // Devuelve 0 si la pila está vacía
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

void convertirAExpresionPostfija(char* expressionInfija, Lista* expressionPosfija, int sizeExpression) {
    Pila operadores = {0, {0}};
    char* numberC = calloc(20, sizeof(char));
    int i, j, ep = 0, nc = 0;

    for (i = 0; i < sizeExpression; i++) {
        if (isdigit(expressionInfija[i])) {
            numberC[nc++] = expressionInfija[i];
        } else {
            if (nc > 0) {
                expressionPosfija[ep].type = 1;
                expressionPosfija[ep].valueI = atoi(numberC);
                for (j = 0; j < nc; j++) {
                    numberC[j] = ' ';
                }
                ep++;
                nc = 0;
            }

            if (expressionInfija[i] == '(') {
                push(&operadores, expressionInfija[i]);
            } else if (expressionInfija[i] == ')') {
                while (!vacia(&operadores) && tope(&operadores) != '(') {
                    expressionPosfija[ep].type = 2;
                    expressionPosfija[ep].valueC = pop(&operadores);
                    ep++;
                }
                pop(&operadores);
            } else {
                while (!vacia(&operadores) && ordenPrecedencia(tope(&operadores)) >= ordenPrecedencia(expressionInfija[i])) {
                    expressionPosfija[ep].type = 2;
                    expressionPosfija[ep].valueC = pop(&operadores);
                    ep++;
                }
                push(&operadores, expressionInfija[i]);
            }
        }
    }

    if (nc > 0) {
        expressionPosfija[ep].type = 1;
        expressionPosfija[ep].valueI = atoi(numberC);
        ep++;
    }

    while (!vacia(&operadores)) {
        expressionPosfija[ep].type = 2;
        expressionPosfija[ep].valueC = pop(&operadores);
        ep++;
    }

    free(numberC);
}

int evaluarExpresionPostfija(Lista* expressionPosfija, int sizeExpression) {
    PilaNumeros numeros = {0, {0}};
    int i;

    for (i = 0; i < sizeExpression; i++) {
        if (expressionPosfija[i].type == 1) {
            pushNumeros(&numeros, expressionPosfija[i].valueI);
        } else {
            int n2 = popNumeros(&numeros);
            int n1 = popNumeros(&numeros);
            int r;

            switch (expressionPosfija[i].valueC) {
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

            pushNumeros(&numeros, r);
        }
    }

    return popNumeros(&numeros);
}

int main(void) {
    
    char expressionInfija[MAX];
    char caracter;
    int sizeExpression = 0, pa = 0, pc = 0; 

    printf("Ingrese una expresión matemática en infijo: \n");

    while ((caracter = getchar()) != '\n' && sizeExpression < MAX - 1) {
        expressionInfija[sizeExpression] = caracter;

        if (caracter == '(') pa++;
        if (caracter == ')') pc++;

        sizeExpression++;
    }
    expressionInfija[sizeExpression] = '\0';

    if (pa != pc) {
        printf("Error en la expresión\n");
        return 1;
    }

    Lista* expressionPosfija = calloc(sizeExpression, sizeof(Lista));

    convertirAExpresionPostfija(expressionInfija, expressionPosfija, sizeExpression);

    printf("Expresión en notación polaca inversa: ");
    for (int i = 0; i < sizeExpression && (expressionPosfija[i].type != 0); i++) {
        if (expressionPosfija[i].type == 1) {
            printf("%d ", expressionPosfija[i].valueI);
        } else {
            printf("%c ", expressionPosfija[i].valueC);
        }
    }
    printf("\n");

    int resultado = evaluarExpresionPostfija(expressionPosfija, sizeExpression);
    printf("Resultado: %d\n", resultado);

    free(expressionPosfija);

    return 0;
}
