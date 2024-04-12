#include <stdio.h>
#include <stdlib.h>

#define archivo "SALIDA.txt"
#define abcSize 27

int arreglo[ 300000 ];

struct Indice {
    char letra;
    int i;
};
// Prototipo de la función
void createIndexedSearch(struct Indice indices[]);

int getNum( char linea[] ) {
    int i;
    char num[5];
    for( i = 1; i < 6; i++ ) {
        num[ i - 1 ] = linea[i];
    }
    return atoi( num );
}

void createIndexedSearch( struct Indice indices[] ) {
    // Abrir archivo.
    FILE *file;
    file = fopen( archivo, "r");

    char linea[16];
    char letra = ' ';
    int i = 0;
    int k = 0;

    // Leer archivo y mostrar info
    while( fgets( linea, sizeof( linea ), file ) != NULL ) {
        char letraActual = linea[0];
        int numActual = getNum( linea );
        if( letraActual != letra ) {
            // Guardamos letra e indice final que ocupa.
            struct Indice indice;
            indice.i = i;
            indice.letra = letra;
            indices[k] = indice;

            letra = letraActual;
            
            k++;
        }

        arreglo[i] = numActual;
        i++;
	}
    // Añadiendo la Z
    struct Indice indice;
    indice.i = 300000;
    indice.letra = 'Z';

    indices[k] = indice;

    fclose( file );
}

int searchKey( char clave[], struct Indice indices[] ) {
    char letra = clave[0];
    int i, num = getNum( clave );
    struct Indice indice;

    for( i = 0; i < abcSize; i++ ) {
        if( letra == indices[i].letra ) {
            indice = indices[i];
            break;
        }
    }
    int inicial = indices[i - 1].i;
    int final = indice.i;

    for( i = inicial; i < final; i++ ) {
        if( num == arreglo[i] ) {
            return i;
        }
    }
    return -1;
}

void main() {
    printf("Creando lista indexada... (buscando indices)\n\n");
    // Creamos la lista indexada.
    struct Indice indices[ abcSize ];
    createIndexedSearch( indices );

    char clave[6];
    int descicion = 1;
    printf(" ******************************************** \n");
    printf(" *****BUSCADOR DE INDICES POR INDEXACION***** \n");
    printf(" ******************************************** \n\n");
    
    do {
        printf("Que clave desea buscar?: ");
        scanf("%s", clave );

        fflush( stdin );

        int key = searchKey( clave, indices );
        if( key != -1 ) {
            printf("La clave se encontro en el indice: %d\n", key );
        }
        else {
            printf("La clave no se encontro. :(\n");
        }
        printf("Desea buscar otra clave? (y = 1/n = 0): ");
        scanf("%d", &descicion );

        fflush( stdin );

    } while( descicion == 1 );
}