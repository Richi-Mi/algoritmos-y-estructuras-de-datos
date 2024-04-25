#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{

    int valor;
    struct Nodo *sig;

}Nodo;

// Apuntador doble
void agregar(Nodo **p, int x){

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
        while (aux->sig != NULL)
        {
            // aux apunta al siguiente NODO
            aux = aux->sig;
        }
        // Lo enlazamos como siguiente de 'aux'
        aux->sig = new;
    }
}

void mostrar(Nodo *p){

    // aux -> Accede al valor al que apunta 'p' (dirección de estructura)
    Nodo *aux = p;
    int i = 0;

    // Pregunta sobre el nodo al que apunta
    while (aux != NULL)
    {

        printf("%d | %d\n", i, aux->valor);
        i++;
        // aux apunta al siguiente NODO
        aux = aux->sig;
    }

    printf("Tetuan...");
    printf("\n");
}

int main(){

    Nodo *p = NULL;
    int x;

    printf("Escriba numeros para hacer operaciones (Al escribir 0 se detiene)");

    while(!x){

        scanf("%d",&x);

        agregar(&p,x);

    }

    mostrar(p);

    free(p);

}