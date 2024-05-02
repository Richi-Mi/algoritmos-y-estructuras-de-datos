#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_ROW 5
#define MAX_COLUMN 5

int main() {

    srand( time( NULL ));


    // Programa 1.
    int matrixA[MAX_ROW][MAX_COLUMN], matrixB[MAX_ROW][MAX_COLUMN], matrixC[MAX_ROW][MAX_COLUMN];
    int matriz[MAX_COLUMN][MAX_ROW], i, j, bandera = 0, k = 0;

    // llenar la matriz de datos.
    for( i = 0; i < MAX_ROW; i++ ) {
        for( j = 0; j < MAX_COLUMN; j++ ) {
            matriz[i][j] = rand() % 100;

            matrixA[i][j] = rand() % 100;
            matrixB[i][j] = rand() % 100;
        }
    }
    // NOTA: La multiplicacion de matrices solo se da entre matrices n x n, o matrices m x n y n x p c = m x p
    for( i = 0; i < MAX_ROW; i++ ) {
        for( j = 0; j < MAX_COLUMN; j++ ) {
            matrixC[j][i] = matrixA[i][j] * matrixB[j][i];
        }
    }
    printf("\nMatriz C: \n");
    for( i = 0; i < MAX_ROW; i++ ) {
        for( j = 0; j < MAX_COLUMN; j++ ) {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // mostrar la matriz de datos.
    for( i = 0; i < MAX_ROW; i++ ) {
        for( j = 0; j < MAX_COLUMN; j++ ) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Recorrido en ZicZag: \n");
    // Recorrido en zigzag.
    for( j = 0; j < MAX_COLUMN; j++ ) {
        if( bandera == 0 ) {
            for( i = 0; i < MAX_ROW; i++ ) {
                printf("%d, ", matriz[i][j]);

                if( i == (MAX_ROW - 1) ) {
                    bandera = 1;
                }
            }
        }
        else {
            for( i = MAX_ROW - 1; i >= 0; i-- ) {
                printf("%d, ", matriz[i][j]);

                if( i == 0 ) {
                    bandera = 0;
                }
            }
        }
    }
    printf("\nRecorrido en Espiral\n");
    // Recorrido en espiral.
    int startRow = 0, startColumn = 0;
    int endRow = MAX_ROW - 1, endColumn = MAX_COLUMN - 1;

    while (startRow <= endRow && startColumn <= endColumn) {
        // Imprimir la primera fila de la matriz de la izquierda a la derecha
        for (i = startColumn; i <= endColumn; ++i) {
            printf("%d ", matriz[startRow][i]);
        }
        startRow++;

        // Imprimir la última columna de la matriz de arriba hacia abajo
        for (i = startRow; i <= endRow; ++i) {
            printf("%d ", matriz[i][endColumn]);
        }
        endColumn--;

        // Imprimir la última fila de la matriz de la derecha a la izquierda
        if (startRow <= endRow) {
            for (i = endColumn; i >= startColumn; --i) {
                printf("%d ", matriz[endRow][i]);
            }
            endRow--;
        }

        // Imprimir la primera columna de la matriz de abajo hacia arriba
        if (startColumn <= endColumn) {
            for (i = endRow; i >= startRow; --i) {
                printf("%d ", matriz[i][startColumn]);
            }
            startColumn++;
        }
    }
    return 0;
}