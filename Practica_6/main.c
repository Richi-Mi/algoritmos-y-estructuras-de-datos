#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//// Listas Estaticas 

typedef struct Persona{

    char rfc[12];
    char nombre[255];

} Persona;

#define sizeArr 10

int insertToEnd( Persona personas[], Persona personToInsert );

int insertTo( Persona personas[], Persona personToInsert, int position );

Persona searchPersonByRFC( Persona personas[], char rfc[] );

Persona searchPersonByIndex( Persona personas[], int index );

void showAllElements( Persona personas[], Persona personToInsert);

int main(){

    Persona personas[ sizeArr ];

    printf("\n*---------------------MENU----------------------*\n");
    printf("| 1. Dar de alta a una persona \t\t\t|\n| 2. Buscar a una persona por RFC \t\t|\n| 3. Borrar a una persona por RFC \t\t|\n| 4. Mostrar todos los elementos de la lista \t|");
    printf("\n*-----------------------------------------------*\n");

}


int insertToEnd( Persona personas[], Persona personToInsert ){

}

int insertTo(Persona personas[], Persona personToInsert, int position ){

}

Persona searchPersonByRFC(Persona personas[], char rfc[] ){

}

Persona searchPersonByIndex(Persona personas[], int index ){

}

void showAllElements(Persona personas[], Persona personToInsert){



}