#include<stdio.h>
#include<stdlib.h>

//Definiendo tamaño del arreglo
#define num_lenght 15

void num_aleatorios(float num[num_lenght]){

    int i;

    srand(time(NULL));

    for(i=0 ; i<num_lenght ; i++){

        num[i] = rand() % 100;

    }
}

void imprimir_num(float num[num_lenght]){

    int i;

    printf("\n");

    for(i=0 ; i<num_lenght ; i++){

        printf("%0.1f / ",num[i]);

    }

}

void ord_Burbuja(float num[num_lenght]){

    int i, cond = 0;
    int pass = 0;
    float aux;

    while(!cond){

        cond = 1;

        for(i=0 ; i<num_lenght-pass-1 ; i++){

            if(num[i] > num[i+1]){

                cond = 0;

                aux = num[i];
                num[i] = num[i+1];
                num[i+1] = aux;

            }

        }

        pass++;

    }

}

int main(){


    float num[num_lenght];

    //Llenar arreglo con numero del 1 al 99
        num_aleatorios(num);
    //Imprimir los datos desordenados
        printf("\nArreglo desordenado:");
        imprimir_num(num);
    //Ordenar los datos de entrada con el algortimo de ordenamiento de burbuja
        ord_Burbuja(num);
    //Imprimir los datos ordenados
        printf("\nArreglo ordenado:");
        imprimir_num(num);

}