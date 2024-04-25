#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{

    int valor;
    struct Nodo *sig;

}Nodo;

/*
void f(int *x){
    *x = 3;
}

void asingMemory(int **p){

    *p = (int*)malloc(sizeof(int));

}
*/

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

void liberar(Nodo **p){
    
    Nodo *aux = *p;

    while ( *p != NULL ) {

        aux = (*p)->sig; 
        free( *p );
        *p = aux;

    }
}

Nodo* buscar(Nodo *p, int search){

    Nodo *aux = p;

    // (aux->valor != search) == if(aux->valor != search)s
    while ((aux != NULL) && (aux->valor != search))        
        aux = aux->sig;

    return aux;

}

//Eliminar un elemento
void erease(Nodo **p, int v){

    Nodo *aux, *ant;
    aux = *p;
    ant = NULL;
    
    while (aux != NULL && aux->valor != v){

        ant = aux;
        aux = aux->sig;

    }    

    if(aux!=NULL){

        //Comprobar que no esté en la primera posición
        if(ant != NULL)
            ant->sig = aux->sig;
        else
            p = aux->sig;
        
        free(aux);

    }

}
//Insertar un valor donde sea
//Condición: La lista debe de estar ordenada
Nodo* insertOrdenado(Nodo **p, int v){

    //Nodo que se insertará
    Nodo *new = (Nodo*)malloc(sizeof(Nodo));

    //Necesiramos la direccion del valor anterio y
    //el siguiente de donde queremos poner un nuevo elemento
    new->valor = v;
    new->sig = NULL;

    Nodo *aux = *p;     //siguiente
    Nodo *ant = NULL;   //annterio

    //Recorre lista hasta que encuentre un valor en la lista mayor o igual al que busca
    while( aux != NULL && aux->valor < v){

        ant = aux;
        aux = aux->sig;

    }

    //Insertan un elemnto en cualquier posición diferente del primero (incluyendo la última posición)
    if(ant != NULL)
        ant->sig = new;
    
    //Cuando se inserta un elemento al inicio
    else
        *p = new;
    
    new->sig = aux;

    return new;

}

/*

//Insetar valores no repetidos
Nodo* insertarElemento(Nodo **p, int v, int* enc){

    Nodo *r = buscar(*p,v);
    *enc = r! = NULL;       //Vale 1 si lo encuetra y 0 si no lo encuentra

    if(!*enc){
        r = insertOrdenado(p,v);
    }

    return r;

}

*/

//Tests
int main() {

    Nodo *p = NULL;
    Nodo *luca;

    // Funcion agregar valor a la lista
    agregar(&p, 5);
    agregar(&p, 8);

    // Imprimir elementos de la lista
    mostrar(p);

    agregar(&p, 7);
    agregar(&p, 10);

    mostrar(p);

    // Quitar todos los elementos de una lista
    liberar(&p);

    mostrar(p);

    agregar(&p, 5);
    agregar(&p, 8);
    agregar(&p, 7);
    agregar(&p, 10);

    mostrar(p);
/*
    luca = buscar(p,7);
    printf("Valor encontrado: %d\n",luca->valor);
*/

    free(p);
}