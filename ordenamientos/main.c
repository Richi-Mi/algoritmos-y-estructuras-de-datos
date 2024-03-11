#include <stdio.h>
#include <stdlib.h>

struct Vector
{
    int tamaño;
    int *arreglo;
};

void imprimirArreglo( struct Vector *vector ){

    int i;

    printf("\n");

    for( i = 0; i < vector -> tamaño; i++ ){

        printf("%d / ",*( vector -> arreglo + i));
    }

    printf("\n");

}
void numAleatorios( struct Vector *vector ){

    int i;

    for( i = 0; i < vector -> tamaño; i++ ){

        vector -> arreglo[i] = rand() % 100;

    }

}

void ordenamientoPorInsercion( struct Vector *vector ) {
    int j, key, i;
    int *arreglo; 
    arreglo = vector -> arreglo;

    for (j = 1; j < vector -> tamaño; j++)
    {
        key = *(arreglo + j);
        i = j - 1;

        while (i >= 0 && arreglo[i] > key)
        {
            arreglo[i + 1] = arreglo[i];
            i = i - 1;
        }
        arreglo[i + 1] = key;
    }
}
void ordenamientoBurbuja( struct Vector *vector ) {
    int i = 0, ordenado = 0, *arr, *aux;

    aux = malloc( sizeof( int ) );
    arr = vector -> arreglo;


    while ( !ordenado && i < vector -> tamaño ) {
        ordenado = 1;
        for( i = 0; i < vector -> tamaño - 1; i++ ) {
            if( *(arr + i) > *(arr + i + 1 ) ) {
                *aux = *(arr + i);
                *(arr + i) = *(arr + i + 1) ;
                *(arr + i + 1) = *aux; 
                ordenado = 0;
            }
        }
    } 
    free( aux );
    

}
void ordenamientoSeleccion( struct Vector *vector ) {
    int dd, i, j, aux;
    // Recorrido completo del arreglo.
    for( dd = 0; dd < vector -> tamaño - 1; dd++ ) {
        int posMin = dd;
        // Busqueda del minimo.
        for( i = dd; i < vector -> tamaño; i++ ) {
            if( *( vector -> arreglo + i ) < *( vector -> arreglo + posMin ) ) {
                posMin = i;
            }
        }
        aux = *(vector ->arreglo + posMin);
        *( vector ->arreglo+posMin) = *(vector ->arreglo + dd );
        *( vector -> arreglo+dd) = aux;
    }

}
void merge( int* arreglo, int p, int q, int r ) {
    int *n1, *n2, *arrL, *arrR, *i, *j, *k;
    n1 = malloc( sizeof( int )); 

}
void mergeSort( int* arreglo, int p, int r ) {
    if( p < r ) {
        int q = ( p + r ) / 2;
        mergeSort( arreglo, p, q );
        mergeSort( arreglo, q + 1, r);
        merge( arreglo, p, q, r );
    }
}
void ordenamientoMezcla( struct Vector *vector ) {
    //TODO Programar alogritmo cuando lo explique la profa
    int n, q;
    q = (vector -> tamaño) / 2;


}

void showMenu(int *bandera)
{
    struct Vector vector;
    char metodo[64];

    do {
        // Menu de opciones.
        printf("--------------------------------------\n");
        printf("\n| Selecciona el metodo de ordenamiento: |\n|\t\t\t\t\t|\n");
        printf("| 1.- Insercion\t\t\t\t|\n| 2.- Burbuja\t\t\t\t|\n| 3.- Seleccion\t\t\t\t|\n| 4.- Mezcla\t\t\t\t|\n| 0.- Salir\t\t\t\t|\n| Opcion: ");
        scanf("%d", bandera);
        printf("--------------------------------------\n");

        fflush( stdin ); // Limpieza del buffer

        // Si bandera se selecciona a 0, el programa debe terminar.
        if( *bandera == 0 ) {
            free( vector.arreglo );

            return;
        }

        printf("¿De que tamaño desea el arreglo? : ");
        scanf("%d", &vector.tamaño);

        fflush( stdin ); // Limpieza del buffer

        vector.arreglo = calloc( vector.tamaño, sizeof( int ));

        printf("\nArreglo desordenado: \n");
        numAleatorios( &vector );
        imprimirArreglo( &vector );

        switch ( *bandera )
        {
        case 1:
            ordenamientoPorInsercion( &vector );
            break;
        case 2:
            ordenamientoBurbuja( &vector );
        break;

        case 3:
            ordenamientoSeleccion( &vector );
        break;
        case 4:
            ordenamientoMezcla( &vector );
        break; 
        default:
            *bandera = 0;
            break;
        }
        printf("\nArreglo ordenado: \n" );
        imprimirArreglo( &vector );

    } while ( 1 );
}

void main()
{
    int *bandera;

    srand( time(NULL ) );

    bandera = malloc(sizeof(int)); // Asignación de bandera dinamica.

    showMenu( bandera ); // Ejecución del programa.

    free( bandera );
}