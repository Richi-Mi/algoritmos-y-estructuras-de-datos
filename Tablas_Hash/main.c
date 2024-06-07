#include<stdio.h>
#include<stdlib.h>

typedef struct Tabla{
    
    int indice;
    char nombre;
    struct tabla *sig;
    struct tabla *ant;

}tabla;


directAddressSearch(tabla *t, int x){

    return (t->indice = x);

}

directAddressInsertS(tabla *t, int x){

}

directAddressDelete(tabla *t, int x){

}

//Busqueda eliminar elementos
chainedHashInsert(tabla *t, int x){
    
}

chainedHashSearch(tabla *t, int x){

}

chainedHashDelete(tabla *t, int x){

}


//Aplicación --> busquedas
int main(){



}