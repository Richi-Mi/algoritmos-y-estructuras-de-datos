#include <stdio.h>
#include <stdlib.h>

#define archivo "SALIDA.txt"
#define abcSize 26

struct Indice {
    char letra;
    int i;
};
// Prototipo de la función
void createIndexedSearch(struct Indice indices[]);

// TODO: Terminar de crear las listas
void createIndexedSearch( struct Indice indices[] ) {
    // Abrir archivo.
    FILE *file;
    file = fopen( archivo, "r");

    char linea[16];
    char letra = 'A';
    int i = 0;
    int k = 0;

    // Leer archivo y mostrar info
    while( fgets( linea, sizeof( linea ), file ) != NULL ) {
        char letraActual = linea[0];

        if( letraActual != letra ) {
            // Guardamos letra e indice final que ocupa.
            struct Indice indice;
            indice.i = i;
            indice.letra = letra;
            indices[k] = indice;

            letra = letraActual;
            
            k++;
        }
        i++;
	}
    printf("%d", k);
    // Añadiendo la Z
    struct Indice indice;
            indice.i = i;
            indice.letra = 'Z';

            indices[k] = indice;

    fclose( file );
}

void main() {
    printf("Creando lista indexada... (buscando indices)");
    // Creamos la lista indexada.
    struct Indice indices[27];
    createIndexedSearch( indices );
}