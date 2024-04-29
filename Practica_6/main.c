#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSONS 10

typedef struct Persona {
    char nombre[255];
    char rfc[13];
} Persona;

typedef struct ListaPersonas {
    Persona personas[ MAX_PERSONS ];
    int cantidad;
} ListaPersonas;

void insertToEnd( ListaPersonas *lista, Persona personToInsert );

void showPersons( ListaPersonas *lista );

int searchPersonByRFC( ListaPersonas *lista, char rfc[13]);

void deletePersonByRFC( ListaPersonas *lista, char rfc[13]);

int main() {
    int option;
    char nombre[ 255 ], rfc[ 13 ];
    ListaPersonas listaPersonas = { {}, 0 };

    do {
        printf("* ------ M.E.N.U \n");
        printf("* ---- 1. - Dar de alta a una persona.\n");
        printf("* ---- 2. - Mostrar los registros. .\n");
        printf("* ---- 3. - Buscar una persona por RFC.\n");
        printf("* ---- 4. - Borrar una persona por RFC.\n"); 
        printf("* ---- 0. - Salir.\n");

        printf("Seleccione una opción: \n");
        scanf("%d", &option );

        if( option == 1 ) {
            printf("Ingrese el nombre de la persona: ");
            scanf("%s", nombre );

            printf("Ingrese el RFC de la persona: ");
            scanf("%s", rfc );

            Persona nuevaPersona;
            strcpy( nuevaPersona.nombre, nombre );
            strcpy( nuevaPersona.rfc, rfc );

            insertToEnd( &listaPersonas, nuevaPersona );

            printf("Registro agregado correctamente. \n");
        }
        if( option == 2 ) {
            showPersons( &listaPersonas );
        }
        if( option == 3 ) {
            printf("Ingrese el RFC de la persona: ");
            scanf("%s", rfc );

            int index = searchPersonByRFC( &listaPersonas, rfc );

            if( index != -1 ) {
                printf("Persona encontrada: \n");
                printf("Nombre: %s\n", listaPersonas.personas[index].nombre );
            }
            else {
                printf("No hay registro :( \n");
            }
        }
        if( option == 4 ) {
            printf("Ingrese el RFC de la persona a eliminar: ");
            scanf("%s", rfc );

            deletePersonByRFC( &listaPersonas, rfc );

            printf("Usuario eliminado correctamente. ");
        }
    } while( option != 0 );
}
void insertToEnd( ListaPersonas *lista, Persona personToInsert ) {
    if( lista -> cantidad < MAX_PERSONS ) {
        lista -> personas[ lista -> cantidad ] = personToInsert;
        lista -> cantidad++;
    }
}
void showPersons( ListaPersonas *lista ) {
    int i;

    for( i = 0; i < lista -> cantidad; i++ ) {
        printf("%d. - %s con RFC: %s. \n", i+1, lista -> personas[i].nombre, lista -> personas[i].rfc );
    }
}
int searchPersonByRFC( ListaPersonas *lista, char rfc[13]) {
    for( int i = 0; i < lista -> cantidad; i++ ) {
        if( strcmp( lista -> personas[i].rfc, rfc ) == 0) {
            return i;
        }
    }
    return -1;
}
void deletePersonByRFC( ListaPersonas *lista, char rfc[13] ) {
    int start = searchPersonByRFC( lista, rfc );
    
    for( int i = start; i < lista -> cantidad - 1; i++ ) {
        lista -> personas[i] = lista -> personas[i + 1];
    }
    lista -> cantidad--;
}