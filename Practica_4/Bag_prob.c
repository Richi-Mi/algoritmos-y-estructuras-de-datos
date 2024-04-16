#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct Objeto {
    int valor;
    int peso;
};

typedef struct Objeto Object;

// Prototipo de las funciones.

void createAndShowAleatoryTable( Object objetos[], int nObjetos );

void createAllCombinations( int nObjetos );

int main(){
    int nObjetos, pesoMaximo;
    srand( time( NULL ) );

    printf(" ******************************************** \n");
    printf(" ********* EL PROBLEMA DE LA MOCHILA ******** \n");
    printf(" ******************************************** \n\n");
    
    printf("¿Cuantos objetos desea generar? \n");
    scanf("%d", &nObjetos);

    Object objetos[ nObjetos ];

    createAndShowAleatoryTable( objetos, nObjetos );

    printf("¿Cual es el peso maximo de la mochila? \n");
    scanf("%d", &pesoMaximo);

    return 0;
}

void createAndShowAleatoryTable( Object objetos[], int nObjetos ) {
    int i;
    
    printf("*------------------------*\n");
    printf("| Objeto | Peso  | Valor |\n");
    printf("*------------------------*\n");

    for( i = 0; i < nObjetos; i++ ) {
        objetos[i].valor = rand() % 100;
        objetos[i].peso  = rand() % 10; 

        printf("| %d      |   %d   |  %d   |\n", i, objetos[i].peso, objetos[i].valor );
    }
    printf("*------------------------*\n");
}
void createAllCombinations( int nObjetos ) {
    int sizeConjuntoPotencia = pow(2, nObjetos ), i;
    // TODO: Create all combinations about this.
}