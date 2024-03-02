#include <stdio.h>
#include <stdlib.h>

void ordenamientoPorInsercion( int arr[] ) {
	int j, key, i;
	for(j = 1; j < 10; j++){
                key = arr[j];
                i = j - 1;

                while( i >= 0 && arr[i] > key ){
                        arr[i + 1] = arr[i];
                        i = i - 1;
                }
                arr[i+1] = key;
        }
}

void main() {
	// Datos a ordenar
        int arr[10] = {2, 4, 6, 8, 1, 3, 5, 7, 9, 10};
	int j;
	
	printf("Datos desordenados: \n");
	for( j = 0; j < 10; j++) {
		printf("%d, ", arr[j]);
	}

	ordenamientoPorInsercion(arr);

	printf("\nDatos Ordenados: \n");
	for( j = 0; j < 10; j++) {
                printf("%d, ", arr[j]);
        }
	printf("\n");
}
