#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heaps.h"
  
int main( void ) {
    int MAX, i, option, element, n;

    srand( time( NULL ) );

    // 1. Solicitar al usuario la cantidad de elementos en la cola
    printf("*---------------------------------------------------------*\n");
    printf("| Escriba la cantidad de elementos disponibles en la cola |\n");
    printf("*---------------------------------------------------------*\n");

    scanf("%d", &MAX );

    // 2. Inicializar el arreglo con valores aleatorios
    int arbol[MAX];
    n = MAX - 1;
    for( i = 0; i < MAX; i++ ) 
        arbol[i] = rand() % 100;
    // 3. Llamar a la función para inicializar el arbol y mostrar los elementos del arbol.
    printf("Elementos en el arbol: \n");
    heapSort( arbol, n );

    showElements( arbol, MAX );
    printf("\n");


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

                if( n != (MAX - 1) ) {
                    printf("Ingresa el elemento a agregar en la cola\n");
                    scanf("%d", &element );

                    n++;
                    if( n == 0 )
                        arbol[0] = element;
                    else 
                        maxHeapInsert( arbol, n, element );
                }
                else {
                    printf("Cola llena. \n");
                }

                break;
            case 2:
                
                if( n >= 0 ) {
                    int deQueueElement = deQueue( arbol, n );
                    printf("Elemento desencolado: %d\n", deQueueElement );
                    n--;
                }
                else {
                    printf("Cola vacia. \n");
                }

                break;
            case 3:
                printf("Elementos desencolados. \n");
                for(int i = 0; i < n; i++ ) {
                    int l = deQueue( arbol, n );
                    n--;
                    printf("%d, ", l);
                } 
                printf("\n");
                break;
            case 4:
                showElements( arbol, n + 1 );
                break;
        }
    } while( option != 0 ); 
    return 0;
}