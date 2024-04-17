#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

struct Objeto {

    short int peso;
    short int precio;

};

typedef struct Objeto obj;

#define MaxWeight 16


void createAndShowAleatoryTable( obj objetos[], int nObjetos ) {

    int i;
    
    printf("*------------------------*\n");
    printf("| Objeto | Peso  | Valor |\n");
    printf("*------------------------*\n");

    for( i = 0; i < nObjetos; i++ ) {

        //Incializando valiables
        objetos[i].precio = rand() % 100;
        objetos[i].peso  = rand() % 10; 

        printf("| %d      |   %d   |  %d   |\n", i, objetos[i].peso, objetos[i].precio );
    }
    printf("*------------------------*\n");
}


void exhaustiveSearch(obj cosa[], int cant ){
    int i, j;
    int w;
    for( i = 0; i < cant; i++ ) {
        obj actual = cosa[i];
        int weight = 0;
        for( j = i; j < cant; j++ ) {
            weight += cosa[j].peso;
        }
    }


}

void createAllCombinations( int nObjetos ) {
    int sizeConjuntoPotencia = pow(2, nObjetos ), i;
    // TODO: Create all combinations about this.
}

void tablaVerdad(obj cosa[], int cant){



}



int main(){

    int cant;

    printf("¿Cuantos objetos desea poner?");
    scanf("%d",&cant);

    obj *p_thing = (obj*)calloc(cant,sizeof(obj));

    srand(time(NULL));

    createAndShowAleatoryTable(p_thing,cant);

    free(p_thing);
    
    return 0;
}


