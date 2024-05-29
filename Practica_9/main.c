#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funciones para crear el monticulo.
int parent( int i ) {
    return i / 2;
}
int left( int i ) {
    return 2*i;
}
int right( int i ) {
    return 2*i + 1;
}
void heapshort( int arr[], int size ) {

}
void buildMaxHeap( int arr[], int size ) {
    int i;
    for( i = 1; i < size; i++ ) { 
        while ( arr[i] > arr[ parent(i) ] ) {
            int aux = arr[i];
            arr[i] = arr[ parent(i) ];
            arr[ parent(i) ] = aux;
        } 
    }
}
void showElements( int arr[], int size ) {
    int i;
    for( i = 0; i < size; i++ )
        printf("%d -> ", arr[i]);
    printf("\n");
}
void enQueue( int arr[], int element ) {

}
int deQueue( int arr[] ) {
    return 0;
}
int main( void ) {
    int MAX, i, option, element;

    srand( time( NULL ) );

    // 1. Solicitar al usuario la cantidad de elementos en la cola
    printf("*---------------------------------------------------------*\n");
    printf("| Escriba la cantidad de elementos disponibles en la cola |\n");
    printf("*---------------------------------------------------------*\n");

    scanf("%d", &MAX );

    // 2. Inicializar el arreglo con valores aleatorios
    int arbol[MAX];
    for( i = 0; i < MAX; i++ ) 
        arbol[i] = rand() % 100;


    // 3. Llamar a la función para inicializar el arbol y mostrar los elementos del arbol.
    int prueba[] = {10, 1, 5, 23, 12, 14, 7};

    showElements( prueba, 7 );
    printf("\n");
    buildMaxHeap( prueba, MAX );
    showElements( prueba, 7 );

/*
    do {
        printf("*----------------------*\n");
        printf("| 1. Encolar           |\n");
        printf("| 2. Desencolar        |\n");
        printf("| 3. Desencolar todo   |\n");
        printf("| 4. Mostrar elementos |\n");
        printf("| 0. Salir             |\n");
        printf("*----------------------*\n");

        scanf("%d", &option);

        switch ( option ) {
            case 1:
                printf("Ingresa el elemento a agregar en la cola\n");
                scanf("%d", &element );

                enQueue( arbol, element );
                break;
            case 2:
                int deQueueElement = deQueue( arbol );
                printf("Elemento desencolado: %d\n", deQueueElement );
                break;
            case 3:
                printf("Elementos desencolados. \n");
                break;
            case 4:
                showElements( prueba, MAX );
                break;
        }
    } while( option != 0 ); */
    return 0;
}