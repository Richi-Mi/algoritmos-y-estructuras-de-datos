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


void exhaustiveSearch(obj objetos[], int nObjetos ){
   
   /*

    int i, j;
    int w;
    for( i = 0; i < nObjetos; i++ ) {
        obj actual = objetos[i];
        int weight = 0;
        for( j = i; j < nObjetos; j++ ) {
            weight += objetos[j].peso;
        }
    }

    */

}


void tablaVerdad(obj thing[], int nObjetos){

        int w[nObjetos];
        int i,j;
        int cond;

        for(i=0 ; i<(pow(2,nObjetos)) ; i++){

            for(j=0 ; j<nObjetos ; j++){

                if((i/powf(2,j))){
                    cond = 1;
                }

            }


        }

}




int main(){

    int cant;

    printf("Cuantos objetos desea poner?");
    scanf("%d",&cant);

    obj *p_thing = (obj*)calloc(cant,sizeof(obj));

    srand(time(NULL));

    createAndShowAleatoryTable(p_thing,cant);

    free(p_thing);
    
    return 0;
}


