#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Nodo de la lista enlazada
typedef struct Nodo {
    char data;
    struct Nodo* next;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crearNodo(char data) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->data = data;
    nuevoNodo->next = NULL;
    return nuevoNodo;
}

// Función para agregar un nodo al tope de la pila
void push(Nodo** top_ref, char new_data) {
    Nodo* new_node = crearNodo(new_data);
    new_node->next = *top_ref;
    *top_ref = new_node;
}

// Función para eliminar un nodo del tope de la pila
char pop(Nodo** top_ref) {
    if (*top_ref == NULL) {
        return '\0';
    }
    Nodo* temp = *top_ref;
    *top_ref = (*top_ref)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

// Función para ver el tope de la pila
char tope(Nodo* top) {
    if (top == NULL) {
        return '\0';
    }
    return top->data;
}

// Función para verificar si un carácter es un operador
int esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Función para verificar si un carácter es un operando
int esOperando(char c) {
    return isdigit(c) || isalpha(c);
}

// Función para obtener la precedencia de un operador
int precedencia(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Función para convertir una expresión infija a notación posfija
void convertirAExpresionPostfija(char* infija, char* posfija) {
    Nodo* pila = NULL;
    int k = 0;
    for (int i = 0; infija[i]; i++) {
        if (isspace(infija[i])) {
            continue;
        }
        if (esOperando(infija[i])) {
            while (esOperando(infija[i])) {
                posfija[k++] = infija[i++];
            }
            posfija[k++] = ' ';
            i--;
        } else if (infija[i] == '(') {
            push(&pila, infija[i]);
        } else if (infija[i] == ')') {
            while (tope(pila) != '(') {
                posfija[k++] = pop(&pila);
                posfija[k++] = ' ';
            }
            pop(&pila);
        } else if (esOperador(infija[i])) {
            while (pila != NULL && precedencia(tope(pila)) >= precedencia(infija[i])) {
                posfija[k++] = pop(&pila);
                posfija[k++] = ' ';
            }
            push(&pila, infija[i]);
        }
    }
    while (pila != NULL) {
        posfija[k++] = pop(&pila);
        posfija[k++] = ' ';
    }
    posfija[k - 1] = '\0';  // Eliminar el último espacio agregado
}

// Función para verificar si los paréntesis están balanceados
int verificarParentesisBalanceados(char* expr) {
    Nodo* pila = NULL;
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(') {
            push(&pila, '(');
        } else if (expr[i] == ')') {
            if (pila == NULL) {
                return 0;
            } else {
                pop(&pila);
            }
        }
    }
    return pila == NULL;
}

// Función para evaluar una expresión posfija
int evaluarExpresionPosfija(char* posfija) {
    Nodo* pila = NULL;
    char* token = strtok(posfija, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&pila, atoi(token));
        } else if (esOperador(token[0])) {
            if (pila == NULL || pila->next == NULL) {
                printf("Error: no hay suficientes operandos para el operador '%c'.\n", token[0]);
                exit(EXIT_FAILURE);
            }

            int op2 = pop(&pila);
            int op1 = pop(&pila);
            int res;
            switch (token[0]) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
                default:
                    printf("Error: operador desconocido '%c'.\n", token[0]);
                    exit(EXIT_FAILURE);
            }
            push(&pila, res);
        }
        token = strtok(NULL, " ");
    }

    if (pila == NULL || pila->next != NULL) {
        printf("Error: se introdujeron demasiados operandos.\n");
        exit(EXIT_FAILURE);
    }

    int resultado = pop(&pila);
    return resultado;
}

// Función principal
int main() {
    char expressionInfija[100];
    printf("Ingrese una expresion infija: ");
    fgets(expressionInfija, sizeof(expressionInfija), stdin);

    // Eliminar el salto de línea si está presente
    int len = strlen(expressionInfija);
    if (expressionInfija[len - 1] == '\n') {
        expressionInfija[len - 1] = '\0';
    }

    // Verificar paréntesis balanceados
    if (!verificarParentesisBalanceados(expressionInfija)) {
        printf("Error: Los parentesis no estan balanceados.\n");
        return 0;
    }

    // Convertir infijo a posfijo
    char expressionPosfija[100];
    convertirAExpresionPostfija(expressionInfija, expressionPosfija);

    // Imprimir la expresión posfija
    printf("Expresion posfija: %s\n", expressionPosfija);

    // Evaluar la expresión posfija
    int resultadoPosfija = evaluarExpresionPosfija(expressionPosfija);
    printf("Resultado de la expresion posfija: %d\n", resultadoPosfija);

    return 0;
}