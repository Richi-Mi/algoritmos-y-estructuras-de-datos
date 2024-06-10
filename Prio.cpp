#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Función para intercambiar dos elementos
void cambio(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

// Función para obtener el índice del padre de un nodo
int parent(int i) {
    return (i - 1) / 2;
}

// Función para obtener el índice del hijo izquierdo de un nodo
int left(int i) {
    return (2 * i + 1);
}

// Función para obtener el índice del hijo derecho de un nodo
int right(int i) {
    return (2 * i + 2);
}

// Función para hacer que un subárbol con raíz en el nodo i sea un max-heap
void maxHeapify(int A[], int n, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < n && A[l] > A[largest])
        largest = l;

    if (r < n && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        cambio(&A[i], &A[largest]);
        maxHeapify(A, n, largest);
    }
}

// Build-Max-Heap
void buildMaxHeap(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(A, n, i);
}

// HeapSort
void heapSort(int A[], int n) {
    buildMaxHeap(A, n);

    for (int i = n - 1; i > 0; i--) {
        cambio(&A[0], &A[i]);
        maxHeapify(A, i, 0);
    }
}

// Heap-Increase-Key
void heapIncreaseKey(int A[], int i, int key) {
    if (key < A[i]) {
        printf("La nueva llave es menor que la anterior\n");
    } else {
        A[i] = key;
        while (i > 0 && A[parent(i)] < A[i]) {
            cambio(&A[i], &A[parent(i)]);
            i = parent(i);
        }
    }
}

// Max-Heap-Insert
void maxHeapInsert(int A[], int n, int key) {
    A[n] = INT_MIN;
    heapIncreaseKey(A, n, key);
}

// COLAS

// Función para imprimir el arreglo en orden ascendente
void valor(int A[], int n) {
    // Copiamos el arreglo para no modificar el original
    int *temp = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        temp[i] = A[i];

    // Ordenamos el arreglo copiado en orden ascendente
    heapSort(temp, n);

    // Imprimimos el arreglo ordenado
    for (int i = 0; i < n; i++)
        printf("%d ", temp[i]);
    printf("\n");

    // Liberamos la memoria del arreglo copiado
    free(temp);
}

int desencolar(int A[], int n) {
    int desencolarValor = A[0];
    int x = 1;
    int aux = A[x];

    for (int i = 0; i < n; i++) {
        A[i] = aux;
        x++;
        aux = A[x];
    }

    heapSort(A, n);

    return desencolarValor;
}

// Impresiones

int main(void) {
    int MAX, i, option, num, n;

    printf("\n*** B I E N V E N I D O S  A   *****\n");
    printf("      COLAS DE PRIORIDAD \n");

    printf("\n-> Ingrese el numero de elementos que desee para la cola: \n");

    srand(time(NULL)); // Obtener valores aleatorios
    scanf("%d", &MAX);

    int arbol[MAX];
    n = MAX - 1;
    for (i = 0; i < MAX; i++)
        arbol[i] = rand() % 100 + 1;

    printf("\n Elementos obtenidos aleatoriamente: \n");
    heapSort(arbol, n + 1);
    valor(arbol, MAX);
    printf("\n");

    do {
        printf("- - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf(".: MENU :.\n");
        printf(" 1. Encolar           \n");
        printf(" 2. Desencolar        \n");
        printf(" 3. Desencolar todo   \n");
        printf(" 4. Mostrar elementos \n");
        printf(" 0. Salir             \n");
        printf("\n");
       
        printf("- - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("-> SELECCIONE LA OPCION QUE DESEA: \n");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                if (n != (MAX - 1)) {
                    printf("\n( + )Ingresa el elemento a agregar en la cola: ");
                    scanf("%d", &num);

                    n++;
                    if (n == 0)
                        arbol[0] = num;
                    else
                        maxHeapInsert(arbol, n, num);
                } else {
                    printf("\nCola llena.\n");
                }
                break;
            case 2:
                if (n >= 0) {
                    int desencolarValor = desencolar(arbol, n);
                    printf("\n( - )Elemento desencolado: %d\n", desencolarValor);
                    n--;
                } else {
                    printf("\nCola vacia.\n");
                }
                break;
            case 3:
                for (int i = 0; i < MAX; i++) {
                    desencolar(arbol, n);
                    n--;
                }
                printf("\n( X )Elementos desencolados: \n");
                break;
            case 4:
            printf("\nMuestra de Elementos: ");
                valor(arbol, n + 1);
                break;
        }
    } while (option != 0);
    return 0;
}