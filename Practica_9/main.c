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
void showElements( int arr[], int size, int i ) {
    if( i > size ) {
        return;
    }
    showElements( arr, size, left(i) );
    showElements( arr, size, right(i) );

    printf("%d - %d\n", left(i), right(i));
}
int main( void ) {
    int MAX, i, option;

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

    // 3. Llamar a la función para inicializar el arbol y mostrar los elementos del arreglo.
    heapshort( arbol, MAX );

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
            case 4:
                showElements( arbol, MAX, 1);
                break;
        }
    } while( option != 0 );
    return 0;
}