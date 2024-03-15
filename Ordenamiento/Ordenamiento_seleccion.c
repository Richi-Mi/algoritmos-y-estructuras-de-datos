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

void ord_Seleccion(float num[num_lenght]){

    int i,j;
    int dd=0;

    float min, aux;

    for(dd=0 ; dd<num_lenght-1 ; dd++){

        j = dd;
        min = num[dd];

        //Buscar el numero más pequeña
        for(i=dd+1 ; i<num_lenght ; i++){
        
            if(min>num[i]){
                min = num[i];
                j = i;
            }
    
        }
        //Pasar a la primera posicion el elemento más pequeño e intercambiarlo
        //con el otro numero en la posicion que tenía antes el número más pequeño
        num[j] = num[dd];
        num[dd] = min;
    
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
        ord_Seleccion(num);
    //Imprimir los datos ordenados
        printf("\nArreglo ordenado:");
        imprimir_num(num);



}