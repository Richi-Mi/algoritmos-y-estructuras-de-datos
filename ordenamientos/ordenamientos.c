#include<stdio.h>
#include<stdlib.h>

void imprimirAlgo( char texto []) {
    printf("%s, ", texto );    
}

//Definiendo tamaño del arreglo
#define num_lenght 15

void showMenu(int *bandera, float *num ){

    printf("\nSelecciona el metodo de ordenamiento: \n\n 1. - Insercion\n 2.- Burbuja\n 3.- Seleccion \n 4. - Mezcla. \n 0. Salir\n");
    scanf("%d", bandera );

    if( *bandera ) {
        printf("\n * Arreglo deordenado:\n");
        imprimirArreglo( num );
    }

    switch ( *bandera )
    {
    case 1:
        ordenamientoInsercion( num );
        break;

    case 2:
        ordenamientoBurbuja( num );
        break;

    case 3:
        ordenamientoSeleccion( num );
        break;

    case 4:
        ordenamientoMezcla( num );
        break;
    
    default:
        return;
        break;
    }

    printf("\n * Arreglo ordenado:\n");
    imprimirArreglo( num );


}

void numAleatorios(float *num){

    int i;

    srand(time(NULL));

    for(i=0 ; i<num_lenght ; i++){

        num[i] = rand() % 100;

    }

}

void imprimirArreglo(float *num){

    int i;

    printf("\n");

    for(i=0 ; i<num_lenght ; i++){

        printf("%0.1f / ",*( num + i));

    }

    printf("\n");

}

void ordenamientoInsercion( float *num ){

    int i,j;
    float aux;

    for(j=1 ; j<num_lenght ; j++){

        aux = num[j];
        i = j-1;

            while(i>=0 && num[i]>aux){

                num[i+1] = num[i];
                i = i-1;

            }

        num[i+1] = aux;

    }

}
void ordenamientoBurbuja( float *num ) {
    int i, ordenado;
    float *aux;

    aux = malloc( sizeof( float ) );

    while ( !ordenado ) {
        for( i = 0; i < num_lenght - 1; i++ ) {
            if( *(num + i) > *(num + i + 1 ) ) {
                *aux = *(num + i);
                *(num + i) = *(num + i + 1) ;
                *(num + i + 1) = *aux; 
            }
        }
    } 
    free( aux );
    

}
void ordenamientoSeleccion( float *num ) {

}
void ordenamientoMezcla( float *num ) {

}

int main(){

    float *num;
    num = (float *) calloc( num_lenght, sizeof(float ) );

    int bandera;

    do {

        numAleatorios(num);
        showMenu( &bandera, num );

    } while( bandera != 0 );

    free( num );

}