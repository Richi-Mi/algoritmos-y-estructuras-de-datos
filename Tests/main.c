#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Nodo de la lista enlazada
typedef struct Nodo {
    char* data;
    struct Nodo* next;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crearNodo(char* data) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->data = strdup(data);
    nuevoNodo->next = NULL;
    return nuevoNodo;
}

// Función para agregar un nodo al final de la lista enlazada
void append(Nodo** head_ref, char* new_data) {
    Nodo* new_node = crearNodo(new_data);
    Nodo* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
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

// Función para convertir una expresión infija a una lista enlazada de notación posfija
void convertirAExpresionPostfija(char* infija, Nodo** posfija) {
    Nodo* pila = NULL;
    char buffer[100];
    int i, k = 0;

    for (i = 0; infija[i]; i++) {
        if (infija[i] == ' ')
            continue;

        if (esOperando(infija[i])) {
            buffer[k++] = infija[i];
            if (!esOperando(infija[i + 1])) {
                buffer[k] = '\0';
                append(posfija, buffer);
                k = 0;
            }
        } else if (infija[i] == '(') {
            buffer[k] = '\0';
            append(&pila, "(");
        } else if (infija[i] == ')') {
            while (pila != NULL && strcmp(pila->data, "(") != 0) {
                append(posfija, pila->data);
                Nodo* temp = pila;
                pila = pila->next;
                free(temp->data);
                free(temp);
            }

            if (pila != NULL && strcmp(pila->data, "(") == 0) {
                Nodo* temp = pila;
                pila = pila->next;
                free(temp->data);
                free(temp);
            }
        } else if (esOperador(infija[i])) {
            buffer[k] = '\0';
            while (pila != NULL && precedencia(pila->data[0]) >= precedencia(infija[i])) {
                append(posfija, pila->data);
                Nodo* temp = pila;
                pila = pila->next;
                free(temp->data);
                free(temp);
            }
            buffer[0] = infija[i];
            buffer[1] = '\0';
            append(&pila, buffer);
        }
    }

    while (pila != NULL) {
        append(posfija, pila->data);
        Nodo* temp = pila;
        pila = pila->next;
        free(temp->data);
        free(temp);
    }
}

// Función para imprimir una lista enlazada
void printLista(Nodo* head) {
    while (head != NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Función para verificar si los paréntesis están balanceados
int verificarParentesisBalanceados(char* expr) {
    Nodo* pila = NULL;
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(') {
            append(&pila, "(");
        } else if (expr[i] == ')') {
            if (pila == NULL) {
                return 0;
            } else {
                Nodo* temp = pila;
                pila = pila->next;
                free(temp->data);
                free(temp);
            }
        }
    }
    return pila == NULL;
}

// Función para convertir una expresión en notación posfija a infija
char* convertirAPosfijoAInfijo(Nodo* posfija) {
    Nodo* pila = NULL;
    while (posfija != NULL) {
        if (esOperando(posfija->data[0])) {
            append(&pila, posfija->data);
        } else if (esOperador(posfija->data[0])) {
            char* op2 = pila->data;
            Nodo* temp = pila;
            pila = pila->next;
            free(temp);

            char* op1 = pila->data;
            temp = pila;
            pila = pila->next;
            free(temp);

            int len = snprintf(NULL, 0, "(%s%c%s)", op1, posfija->data[0], op2);
            char* expr = (char*)malloc(len + 1);
            snprintf(expr, len + 1, "(%s%c%s)", op1, posfija->data[0], op2);

            append(&pila, expr);
            free(op1);
            free(op2);
            free(expr);
        }
        posfija = posfija->next;
    }

    char* infija = pila->data;
    free(pila);
    return infija;
}

// Función para evaluar una expresión infija
int evaluarExpresionInfija(char* infija) {
    Nodo* pila = NULL;
    char buffer[100];
    int i, k = 0;

    for (i = 0; infija[i]; i++) {
        if (infija[i] == ' ')
            continue;

        if (isdigit(infija[i])) {
            buffer[k++] = infija[i];
            if (!isdigit(infija[i + 1])) {
                buffer[k] = '\0';
                append(&pila, buffer);
                k = 0;
            }
        } else if (esOperador(infija[i])) {
            int op2 = atoi(pila->data);
            Nodo* temp = pila;
            pila = pila->next;
            free(temp->data);
            free(temp);

            int op1 = atoi(pila->data);
            temp = pila;
            pila = pila->next;
            free(temp->data);
            free(temp);

            int res;
            switch (infija[i]) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
            }
            snprintf(buffer, sizeof(buffer), "%d", res);
            append(&pila, buffer);
        }
    }
    int resultado = atoi(pila->data);
    free(pila->data);
    free(pila);
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
    Nodo* expressionPosfija = NULL;
    convertirAExpresionPostfija(expressionInfija, &expressionPosfija);

    // Imprimir la expresión posfija
    printf("Expresion posfija: ");
    printLista(expressionPosfija);

    // Convertir posfijo a infijo
    char* nuevaExpresionInfija = convertirAPosfijoAInfijo(expressionPosfija);

    if (nuevaExpresionInfija == NULL) {
        printf("Error al convertir a infijo.\n");
        return 0;
    }

    // Imprimir la nueva expresión infija
    printf("Expresion infija nuevamente: %s\n", nuevaExpresionInfija);

    // Evaluar la nueva expresión infija
    int resultado = evaluarExpresionInfija(nuevaExpresionInfija);
    printf("Resultado: %d\n", resultado);

    // Liberar memoria de la lista de expresión posfija y la expresión infija nueva
    while (expressionPosfija != NULL) {
        Nodo* temp = expressionPosfija;
        expressionPosfija = expressionPosfija->next;
        free(temp->data);
        free(temp);
    }
    free(nuevaExpresionInfija);

    return 0;
}