#include <stdio.h>
#include <stdlib.h>

struct Objeto {

    short int peso;
    short int precio;

};

typedef struct Objeto Elemento;

// Función para imprimir una combinación de elementos
void printCombinations(Elemento *elementos, int cant, int *solucionActual){

    int valorTotal = 0;
    int pesoTotal = 0;
    int i;

    printf("Combinacion: ");

    for(i=0 ; i<cant ; i++){
        if(solucionActual[i]){

            printf("%d ", i + 1);
            valorTotal += elementos[i].precio;
            pesoTotal += elementos[i].peso;

        }
        else{
            printf("%d ",0);
        }
    }
    printf("(Peso: %d Kg, Precio: $ %d)\n", pesoTotal, valorTotal );

}

// Función para validar el peso y encontrar el mejor peso que no sobrepase el peso máximo
int ValidWeight(int *pesosValid, int numPesos, int pesoMax){

    int i,mejorPeso = 0;


    for(i=0 ; i<numPesos ; i++){
        if(pesosValid[i] > mejorPeso && pesosValid[i] <= pesoMax)
            mejorPeso = pesosValid[i];
    }

    return mejorPeso;

}

void addValues(Elemento *elementos, int cant){

    for(int i = 0; i < cant; i++) {

        printf("Elemento %d:\n", i + 1);
        printf("Peso: ");
        scanf("%d", &elementos[i].peso);
        printf("Precio: ");
        scanf("%d", &elementos[i].precio);

    }

}

// Función para buscar la mejor combinación de elementos que no sobrepase el peso máximo de la mochila
void BestCombination(Elemento *elementos, int cant, int pesoMax){

    int pesosValid[cant * cant];
    int numPesosValid = 0;
    int i,j;

    for(i=0 ; i<(1 << cant) ; i++){
        int valorTotal = 0;
        int pesoTotal = 0;

        for(j=0 ; j<cant ; j++){
            if((i >> j) & 1){

                valorTotal += elementos[j].precio;
                pesoTotal += elementos[j].peso;

            }
        }
        if(pesoTotal <= pesoMax)
            pesosValid[numPesosValid++] = pesoTotal;
    }

    printf("\nMejor combinacion que no sobrepasa el peso maximo:\n");
    int mejorPeso = ValidWeight(pesosValid, numPesosValid, pesoMax);
    printf("Peso: %d\n", mejorPeso);

}

int main(){

    int pesoMax, cant;
    int i,j;

    printf("Ingrese peso maximo de la mochila: ");
    scanf("%d",&pesoMax);

    printf("Ingrese la cantidad de elementos: ");
    scanf("%d",&cant);

    Elemento *elementos = (Elemento *)malloc(cant * sizeof(Elemento));

    addValues( elementos , cant );

    printf("\nTodas las combinaciones posibles:\n");

    int solucionActual[cant];
    for(i=0 ; i<(1 << cant) ; i++){
        for(j=0 ; j<cant ; j++){
            solucionActual[j] = (i >> j) & 1;
        }
        printCombinations( elementos , cant , solucionActual );
    }

    BestCombination( elementos , cant , pesoMax );

    free(elementos);

    return 0;
}