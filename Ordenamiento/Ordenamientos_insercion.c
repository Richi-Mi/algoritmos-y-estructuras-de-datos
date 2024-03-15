#include<stdio.h>
#include<stdlib.h>

void imprimirAlgo( char texto []) {
    printf("%s, ", texto );    
}

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

void ord_Insercion(float num[num_lenght]){

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

void mediana(float num[num_lenght]){

//Arreglo par
    if(!(num_lenght % 2)){

        int lenght_one, lenght_two;

        lenght_one = num_lenght / 2;
        lenght_two = lenght_one - 1;

        printf("\nLa mediana es: %0.1f",((num[lenght_one] + num[lenght_two])/2));

    }

//Arreglo impar
    if((num_lenght % 2)){

        int lenght = (num_lenght-1) / 2;

        printf("\nLa mediana es: %0.1f",num[lenght]);

    }

}

int main(){

    float num[num_lenght];

    //Llenar arreglo con numero del 1 al 99
        num_aleatorios(num);
    //Imprimir los datos desordenados
        printf("\nArreglo desordenado:");
        imprimir_num(num);
    //Ordenar los datos de entrada con el algortimo de ordenamiento por insercion
        ord_Insercion(num);
    //Imprimir los datos ordenados
        printf("\nArreglo ordenado:");
        imprimir_num(num);
    //Indicar el valor de la mediana
        mediana(num);

}