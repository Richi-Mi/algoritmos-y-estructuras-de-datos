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
void merge(int *arr, int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    // Crear arrays temporales
    int L[n1], R[n2];

    // Copiar datos a los arrays temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    // Combinar los arrays temporales de vuelta en arr[p..r]
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia los elementos restantes de L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int p, int r) {
    if (p < r) {
        // Encuentra el punto medio del arreglo
        int q = p + (r - p) / 2;

        // Ordena la primera y segunda mitad del array
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);

        // Combina las mitades ordenadas
        merge(arr, p, q, r);
    }
}
void ordenamientoMezcla( struct Vector *vector ) {
    mergeSort( vector -> arreglo, 0, vector -> tamaño - 1 );
}

void showMenu(int *bandera)
{
    struct Vector vector;
    char metodo[64];

    do {
        // Menu de opciones.
        printf("--------------------------------------\n");
        printf("Seleccione el metodo de ordenamiento: \n 1. - Insercion\n 2. - Burbuja\n 3. - Seleccion\n 4. - Mezcla\n 0. Salir\n");
        printf("--------------------------------------\n");
        scanf("%d", bandera);

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