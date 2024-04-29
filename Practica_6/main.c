#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//// Listas Estaticas 

typedef struct Persona{

    char rfc[12];
    char nombre[255];

} Persona;

// Variables globales estaticas.

#define sizeArr 10

// Variables globales dinamicas.

int sizeAct = 0;

// Definición de funciones.

int insertToEnd( Persona personas[] );

int insertTo( Persona personas[], Persona personToInsert, int position );

int searchPersonByRFC( Persona personas[], char rfc[] );

Persona searchPersonByIndex( Persona personas[], int index );

Persona deletePerson( Persona personas[], char rfc[] );

Persona getDataFromConsole();

void showAllElements( Persona personas[] );

int main(){

    Persona personas[ sizeArr ];
    int option, result, i;

    for( i = 0; i  < sizeArr; i++ ) {
        Persona emptyPerson;
        strcpy( emptyPerson.nombre, "-");
        strcpy( emptyPerson.rfc, "-");

        personas[i] = emptyPerson;
    }

    do {
        printf("\n*---------------------MENU----------------------*\n");
        printf("| 1. Dar de alta a una persona \t\t\t|\n| 2. Buscar a una persona por RFC \t\t|\n| 3. Borrar a una persona por RFC \t\t|\n| 4. Mostrar todos los elementos de la lista \t|\n| 0. Salir \t\t\t\t\t|");
        printf("\n*-----------------------------------------------*\n");

        scanf("%d",&option);

        switch (option){
        case 1:
            result = insertToEnd( personas );

            if( result == 0 ) {
                printf("Usuario registrado correctamente \n");
            }
            else {
                printf("Se ha alcanzado el numero maximo de usuarios \n");
            }
            break;
        case 2:
            // Get RFC.
            printf("Ingrese la RFC a buscar: \n");
            char rfc[12];
            scanf("%s", rfc );
            
            Persona foundedPerson = personas[ searchPersonByRFC( personas, rfc ) ];
            printf("Persona encontrada: %s", foundedPerson.nombre );

            break;
        case 3:
            //deletePerson();
            break;
        case 4:
            showAllElements( personas );
            break;
        default:
            break;
    }
    } while( option != 0 );


}

Persona getDataFromConsole() {
    Persona person;

    printf("Ingrese el nombre de la persona: \n");
    char nombre[255];
    scanf("%s", nombre);

    strcpy( person.nombre, nombre );
    fflush( stdin );

    printf("Ingrese el RFC de la persona: \n");
    char rfc[12];
    scanf("%s", rfc );

    strcpy( person.rfc, rfc );
    fflush( stdin );

    return person;
}

int insertToEnd( Persona personas[] ){
    Persona personToInsert = getDataFromConsole();

    if( personToInsert.nombre == NULL || personToInsert.rfc == NULL ) 
        return -1;

    if( sizeAct >= 10 )
        return -1;
    // Agregar persona.
    personas[sizeAct] = personToInsert;
    sizeAct++;

    return 0;
}

int insertTo(Persona personas[], Persona personToInsert, int position ){
    personas[position] = personToInsert;
}

int searchPersonByRFC(Persona personas[], char rfc[] ){
    int i, j; 

    for( i = 0; i < sizeAct; i++ ) {
        int bandera = 1;
        
        for( j = 0; j < 12; j++ ) {
            if(  personas[i].rfc[j] != rfc[j] ) {
                bandera = 0;
            }
        }

        if( bandera == 1 ) {
            return i;
        } 
    }
    return -1;
}

Persona searchPersonByIndex(Persona personas[], int index ) {
    return personas[index];
}

void showAllElements( Persona personas[] ){
    int i; 

    for( i = 0; i < sizeArr; i++ ) {
        printf("%d. - %s con RFC: %s\n", i, personas[i].nombre, personas[i].rfc );
    }
    printf("La cantidad total de usuarios registrados es: %d", sizeAct );
}
Persona deletePerson( Persona personas[], char rfc[] ) {
    Persona emptyPerson;
    strcpy( emptyPerson.nombre, "null");
    strcpy( emptyPerson.rfc, "null");

    int i = searchPersonByRFC( personas, rfc );
    personas[i] = emptyPerson;
}