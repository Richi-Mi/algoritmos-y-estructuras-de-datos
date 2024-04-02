#include <stdio.h>
#include <stdlib.h>

#define archivo "SALIDA.txt"
#define abcSize 26

struct Lista {
    
};

// TODO: Terminar de crear las listas
void createIndexedSearch() {
    // Abrir archivo.
    FILE *file;
    file = fopen( archivo, "r");

    char linea[16];
    char letra = "";
    int listaIndexada[abcSize], i = 0, *listaNum;
    // Leer archivo y mostrar info
    while( fgets( linea, sizeof( linea ), file ) ) {
        char letraActual = linea[0];

        if( letraActual != letra ) {
            letra = letraActual;
            i++;
        }
	}
    fclose( file );
}

void main() {
    createIndexedSearch();
}