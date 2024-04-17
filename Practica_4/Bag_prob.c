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

void inicializar(obj cosa[], int cant){

    int i;

    for(i=0 ; i<cant ; i++){

        cosa[i].peso = rand()%10;
        cosa[i].precio = rand()%10;

    }
    

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

void tablaVerdad(obj cosa[], int cant){



}

void imprimirTabla(obj cosa[],int cant){

    int i;

    printf("*--------------------------*\n");
    printf("| Objeto   | Peso | Precio |\n");
    printf("*--------------------------*\n\n");

    for(i=0 ; i<cant ; i++){

        printf("| Objeto %d |  %d   |   %d    |\n", i, cosa[i].peso, cosa[i].precio);

    }
    printf("\n*--------------------------*\n\n");

}


int main(){

    int cant;

    printf("¿Cuantos objetos desea poner?");
    scanf("%d",&cant);

    obj *p_thing = (obj*)calloc(cant,sizeof(obj));

    srand(time(NULL));

    inicializar(p_thing, cant);

    imprimirTabla(p_thing, cant);

    free(p_thing);
    
    return 0;
}
