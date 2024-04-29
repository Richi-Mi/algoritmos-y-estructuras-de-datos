#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Nodo{

    float valor;
    struct Nodo *sig;

}Nodo;

void agregar(Nodo **p, float x){

    Nodo *new = (Nodo *)malloc(sizeof(Nodo));

    new->valor = x;
    new->sig = NULL;

    if (*p == NULL){
        *p = new;
    }
    else{
        
        // aux -> Accede al valor al que apunta 'p' (dirección de estructura)
        Nodo *aux = *p;

        // Pregunta sobre el nodo siguiente al que esta apunta
        while (aux->sig != NULL){
            // aux apunta al siguiente NODO
            aux = aux->sig;
        }
        // Lo enlazamos como siguiente de 'aux'
        aux->sig = new;
    }
}

void mostrar(Nodo *p){

    Nodo *aux = p;
    int i = 0;

    while (aux != NULL){

        printf("%d | %0.1f\n", i, aux->valor);
        i++;
        aux = aux->sig;
    }

    printf("\n");
}

Nodo* insertOrdenado(Nodo **p, float v){

    Nodo *new = (Nodo*)malloc(sizeof(Nodo));

    new->valor = v;
    new->sig = NULL;

    Nodo *aux = *p;     
    Nodo *ant = NULL;  

    while( aux != NULL && aux->valor < v ){

        ant = aux;
        aux = aux->sig;

    }

    if(ant != NULL)
        ant->sig = new;
    
    else
        *p = new;
    
    new->sig = aux;

    return new;

}

Nodo* listaOrdenada(Nodo **p){

    Nodo *nuevo = NULL;
    Nodo *aux = *p;

    while(aux != NULL){
        insertOrdenado(&nuevo,aux->valor);
        aux = aux->sig;
    }

    return nuevo;

}

void totalValores(Nodo *p, float *cant){

    *(cant) = 0;

    while(p != NULL){
        (*cant)++;
        p = p->sig;
    }

}

void media(Nodo *p, float cant, float *media){

    float sumaNum;

    while(p != NULL){
        sumaNum += p->valor;
        p = p->sig;
    }

    *(media) = sumaNum/cant;

}

void mediana(Nodo *p, int cant, float *mediana){

    Nodo *aux = p;
    int mid = cant/2;
    int i=0;

    while(p != NULL){
        i++;
        p = p->sig;

        if(!(cant%2)){//Pares

            if(i == mid-1){
        
                *(mediana) = p->valor;
                p=p->sig;
                *(mediana) += p->valor;
                *(mediana) /= 2;
                break;

            }

        }
        else{         //Impares
    
            if(i == mid){
        
                *(mediana) = p->valor;
                break;
        
            }

        }


    }

}

void moda(Nodo *p, float *modaa){

    Nodo *actual = p;
    int maximoFrecuencia = 0;
    *(modaa) = p->valor;

    while (actual != NULL) {
        int frecuenciaActual = 1;
        Nodo *temp = actual->sig;
        while (temp != NULL) {
            if (temp->valor == actual->valor){
                frecuenciaActual++;
            }

            temp = temp->sig;
        }
        if (frecuenciaActual > maximoFrecuencia) {
            maximoFrecuencia = frecuenciaActual;
            *(modaa) = actual->valor;
        }
        actual = actual->sig;
    }

}

void varinza(Nodo *p, float cant, float med, float *varz){

    *(varz) = 0;

    while(p != NULL){
        *(varz) += pow((p->valor-med),2);
        p = p->sig;
    }

    *(varz) /= cant;

}

void desvStandar(Nodo *p, float cant, float med, float *devStand){

    *(devStand) = 0;

    while(p != NULL){
        *(devStand) += pow(((p->valor)-med),2);
        p = p->sig;
    }

    *(devStand) = sqrtf(*(devStand) / cant);

}

int main(){
    
    Nodo *p = NULL;
    Nodo *new = NULL;
    float x;
    float cant, med, median, mod, varz, devEstandar;

    printf("Escriba numeros para hacer operaciones (Al escribir 0 se detiene)\n");

    while(1){

        scanf("%f",&x);

        if(!x)
            break;
        else{
            agregar(&p,x);
        
        }

    }

    printf("Lista desordenada:\n");
    mostrar(p);


    printf("Lista ordenada:\n");
    new = listaOrdenada(&p);
    mostrar(new);

    totalValores(new,&cant);
    media(new,cant,&med);
    mediana(new,cant,&median);
    moda(p,&mod);
    varinza(p,cant,med,&varz);
    desvStandar(p,cant,med,&devEstandar);

    printf("\nTotal de valores: %0.0f",cant);
    printf("\nMedia: %0.2f",med);
    printf("\nMediana: %0.2f",median);
    printf("\nModa: %0.2f",mod);
    printf("\nVarianza: %0.2f",varz);
    printf("\nDesviacion estandar: %0.2f",devEstandar);

    free(p);

}