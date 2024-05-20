#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define Max 1000

// Definici�n de la estructura para un nodo de la lista
typedef struct Nodo {
    char dato[Max]; // Para soportar operandos con m�s de un d�gito
    struct Nodo *siguiente;
} Nodo;

// Nodo para la pila din�mica
typedef struct Pila {
    char dato[20]; // Para soportar operandos con m�s de un d�gito y operadores
    struct Pila *siguiente;
} Pila;

// Funciones para la lista din�mica
void insertar_nodo(Nodo **cabeza, const char* valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (!nuevo) {
        fprintf(stderr, "Error al asignar memoria\n");
        exit(EXIT_FAILURE);
    }
    strcpy(nuevo->dato, valor);//nuevo->dato = valor. Copia el valor del segundo al primero
    nuevo->siguiente = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        Nodo *tmp = *cabeza;
        while (tmp->siguiente != NULL) {
            tmp = tmp->siguiente;
        }
        tmp->siguiente = nuevo;
    }
}

void liberar_lista(Nodo *cabeza) {
    Nodo *tmp;
    while (cabeza != NULL) {
        tmp = cabeza;
        cabeza = cabeza->siguiente;
        free(tmp);
    }
}

// Funciones para la pila din�mica
void push(Pila **tope, const char* valor) {
    Pila *nuevo = (Pila *)malloc(sizeof(Pila));
    if (!nuevo) {
        fprintf(stderr, "Error al asignar memoria\n");
        exit(EXIT_FAILURE);
    }
    strcpy(nuevo->dato, valor);
    nuevo->siguiente = *tope;
    *tope = nuevo;
}

char* pop(Pila **tope) {
    if (*tope == NULL) {
        fprintf(stderr, "Error: pila vac�a\n");
        exit(EXIT_FAILURE);
    }
    char *valor = (char *)malloc(Max * sizeof(char));
    strcpy(valor, (*tope)->dato);
    Pila *tmp = *tope;
    *tope = (*tope)->siguiente;
    free(tmp);
    return valor;
}

char* peek(Pila *tope) {//Devuelve el elemento en el tope de la pila sin eliminarlo.
    if (tope == NULL) {
        return NULL;
    }
    return tope->dato;
}

int is_empty(Pila *tope) { //Verifica si la pila est� vac�a.
    return tope == NULL;
}

void liberar_pila(Pila *tope) {
    Pila *tmp;
    while (tope != NULL) {
        tmp = tope;
        tope = tope->siguiente;
        free(tmp);
    }
}

// Funci�n para verificar si los par�ntesis est�n balanceados
int verificar_parentesis(const char *expresion) {
    Pila *pila = NULL;
    for (int i = 0; expresion[i] != '\0'; i++) {
        if (expresion[i] == '(') {
            push(&pila, "(");
        } else if (expresion[i] == ')') {
            if (is_empty(pila)) {
                return 0;
            }
            pop(&pila);
        }
    }
    int balanceado = is_empty(pila);
    liberar_pila(pila);
    return balanceado;
}

// Funci�n para determinar la precedencia de los operadores
int precedencia(char op) {
    switch (op) {
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

// Funci�n para convertir de infijo a postfijo
void infijo_a_postfijo(const char *expresion, Nodo **postfijo) {
    Pila *pila = NULL;
    char token[Max];
    int i = 0;
    int j = 0;

    while (expresion[i] != '\0') {
        if (isdigit(expresion[i])) {
            // Capturar n�meros con m�s de un d�gito
            while (isdigit(expresion[i])) {
                token[j++] = expresion[i++];
            }
            token[j] = '\0';
            insertar_nodo(postfijo, token);
            j = 0;
        } else if (expresion[i] == '(') {
            push(&pila, "(");
            i++;
        } else if (expresion[i] == ')') {
            while (!is_empty(pila) && strcmp(peek(pila), "(") != 0) {
                insertar_nodo(postfijo, pop(&pila));
            }
            pop(&pila); // Quitar el par�ntesis izquierdo
            i++;
        } else if (strchr("+-*/^", expresion[i])) {//Compara si expresion i esta dentro del primer parametro
            while (!is_empty(pila) && precedencia(peek(pila)[0]) >= precedencia(expresion[i])) {
                insertar_nodo(postfijo, pop(&pila));
            }
            token[0] = expresion[i];
            token[1] = '\0';
            push(&pila, token);
            i++;
        } else {
            i++;
        }
    }//kkkkkkk

    while (!is_empty(pila)) {
        insertar_nodo(postfijo, pop(&pila));
    }
    liberar_pila(pila);
}

// Funci�n para evaluar la expresi�n postfija
int evaluar_postfija(Nodo *expresion) {
    Pila *pila = NULL;

    while (expresion != NULL) {
        if (isdigit(expresion->dato[0])) {
            push(&pila, expresion->dato); // Convertir cadena a n�mero
        } else {
            int val2 = atoi(pop(&pila));//atoi: Pasa un caractera a un entero
            int val1 = atoi(pop(&pila));
            int resultado;

            switch (expresion->dato[0]) {
                case '+':
                    resultado = val1 + val2;
                    break;
                case '-':
                    resultado = val1 - val2;
                    break;
                case '*':
                    resultado = val1 * val2;
                    break;
                case '/':
                    if (val2 == 0) {
                        printf("Error: divisi�n por cero\n");
                        liberar_pila(pila);
                        exit(EXIT_FAILURE);
                    }
                    resultado = val1 / val2;
                    break;
                case '^':
                    resultado = 1;
                    for (int i = 0; i < val2; i++) {
                        resultado *= val1;
                    }
                    break;
                default:
                    fprintf(stderr, "Error: operador desconocido %s\n", expresion->dato);
                    liberar_pila(pila);
                    exit(EXIT_FAILURE);
            }

            char res_str[20];
            sprintf(res_str, "%d", resultado);
            push(&pila, res_str);
        }
        expresion = expresion->siguiente;
    }

    int resultado = atoi(pop(&pila));
    if (!is_empty(pila)) {
        fprintf(stderr, "Error: la pila no est� vac�a despu�s de la evaluaci�n\n");//salida estand_imprime csrscter grsndes
        liberar_pila(pila);
        exit(EXIT_FAILURE);
    }

    return resultado;
}

// Funci�n para imprimir la expresi�n postfija
void imprimir_postfijo(Nodo *postfijo) {
    while (postfijo != NULL) {
        printf("%s ", postfijo->dato);
        postfijo = postfijo->siguiente;
    }
    printf("\n");
}

//*************** Funci�n principal

int main() {
    char input[100];//INPUT: Proporciona una entrada para una lectura interceptada, datos que llegan desde el exterior
    Nodo *postfijo = NULL;
    printf("\n***** Bienvenidos a Evaluacion de expresion en notacion postfija ***** \n");
    printf("\n");
    printf("\n -> Ingrese una expresion en notacion infija: ");
    fgets(input, sizeof(input), stdin);//Devuelve un puntero al almacenamiento
    input[strcspn(input, "\n")] = '\0'; // Eliminar el salto de l�nea

    // Verificar par�ntesis balanceados
    if (!verificar_parentesis(input)) {
        fprintf(stderr, "Error: los parentesis no estan balanceados\n");
        return EXIT_FAILURE;
    }

    // Convertir de infijo a postfijo
    infijo_a_postfijo(input, &postfijo);

    // Imprimir la expresi�n postfija
    printf("\n");
    printf("\n -> Expresion en notacion postfija: ");
    imprimir_postfijo(postfijo);

    // Evaluar la expresi�n postfija
    int resultado = evaluar_postfija(postfijo);
    printf("\n");
    printf("Resultado: %d\n", resultado);

    liberar_lista(postfijo);
    return 0;
}

