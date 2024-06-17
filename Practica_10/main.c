#include <stdio.h>
#include <stdlib.h>

typedef struct Letter {
    char value;
    struct Letter *siguiente;
} Letter;

typedef struct Student {

    int boleta;

    struct Letter *name;
    struct Letter *lastnames;

    struct Student *before;
    struct Student *next;

} Student;

// METODOS PARA PODER MOSTRAR LA INFORMACIÓN.
void showString( Letter *inicio ) {
    Letter *aux = inicio;
    while( aux != NULL ) {
        printf("%c", aux -> value );
        aux = aux -> siguiente;
    }
}
void showStudentsByAsc( Student *s ) {
    Student *aux = s;
    while ( s != NULL ) {
        printf("\n Estudiante: ");
        showString( s -> name );
        printf(" ");
        showString( s -> lastnames );
        printf("\n Boleta: %d \n", s -> boleta );
        s = s -> next;
    }
}
void showStudentsByDesc( Student *s ) {
    Student *aux = s;
    while ( s != NULL ) {
        printf("\n Estudiante: ");
        showString( s -> name );
        printf(" ");
        showString( s -> lastnames );
        printf("\n Boleta: %d \n", s -> boleta );
        s = s -> before;
    }
}
Student* searchByBoleta( Student **inicio, int boleta ) {
    Student *aux = *inicio;
    while( aux != NULL && aux -> boleta != boleta ) {
        aux = aux -> next;
    }
    return aux;
}


//// METODOS DE NODOS.
void addCharacter( Letter **start, char c ) {
    // Creación de la nueva letra. 
    Letter *new = malloc( sizeof( Letter ) );
    new -> value = c;
    new -> siguiente = NULL;

    Letter *aux = *start;
    while( aux -> siguiente != NULL ) {
        aux = aux -> siguiente;
    }
    aux -> siguiente = new;
    
}

//// METODOS DE LISTA DOBLEMENTE ENLAZADA.
void addElementToStart( Student **inicio, Student **final, int boleta, Letter *name, Letter *lastnames ) {
    // Creación del Student a agregar.
    Student *new  = malloc( sizeof( Student ) );
    new -> boleta = boleta;
    new -> name   = name;
    new -> lastnames = lastnames;
    new -> before = NULL;
    new -> next  = NULL;

    // Comprobamos si es el primer elemento que se agrega a la lista
    if( *inicio == NULL ) {
        *inicio = new;
        *final  = new; 
    }

    else {
        Student *aux   = *inicio;
        new -> next    = aux;
        aux -> before  = new;

        *inicio = new;
    }
}

void addElementToEnd( Student **inicio, Student **final, int boleta, Letter *name, Letter *lastnames ) {
    
    // Creación del Student a agregar.
    Student *new  = malloc( sizeof( Student ) );
    new -> boleta = boleta;
    new -> name   = name;
    new -> lastnames = lastnames;
    new -> before = NULL;
    new -> next  = NULL;

    // Comprobamos si es el primer elemento que se agrega a la lista
    if( *inicio == NULL ) {
        *inicio = new;
        *final  = new; 
    }
    
    else {
        Student *aux = *final;
        new -> before = aux;
        aux -> next   = new;

        *final = new;
    }

}

void insertOrderedStudent( Student **inicio, Student **final, int boleta, Letter *name, Letter *lastnames ) {

    // Creación del Student a agregar.
    Student *new  = malloc( sizeof( Student ) );
    new -> boleta = boleta;
    new -> name   = name;
    new -> lastnames = lastnames;
    new -> before = NULL;
    new -> next  = NULL;

    // Creación de variable auxiliar.
    Student *aux = *inicio;
    Student *anterior = NULL;
    
    if( *inicio == NULL || *final == NULL ) {
        *inicio = new; 
        *final  = new; 

        return;
    }

    char caracterLastname = (*lastnames).siguiente -> value;

    if( caracterLastname >= (*final) -> lastnames -> siguiente -> value ) {
        (*final) -> next = new;
        new -> before = (*final);

        (*final) = new;

        return;
    }

    while( aux != NULL && caracterLastname >= aux -> lastnames -> siguiente -> value ) {
        anterior = aux;
        aux      = aux -> next;
    }
    if( aux != NULL ) {
        if( anterior == NULL ) {
            // Asignamos los apuntadores
            new -> next = aux;
            aux -> before = new;

            // Asignamos inicio al nuevo inicio
            *inicio = new;
        }
        if( anterior != NULL && aux != NULL ) {
            
            // Enlace del nodo before
            anterior -> next = new;
            new -> before    = anterior;
            
            // Enlace del nodo despuerior
            aux -> before = new;
            new -> next = aux;
        }
    }
}
void cleanString( Letter *inicio ) {
    while( inicio != NULL ) {
        Letter *aux = inicio;

        inicio = inicio -> siguiente;

        free( aux );
    }
}
void deleteStudentByHisBoleta( Student **inicio, Student **final, int boleta ) {
    // Creamos el Student auxiliar para poder referenciarlo al eliminarlo.
    Student *aux = *inicio;
    Student *anterior = NULL;
    Student *siguiente = NULL;

    // Recorremos el Nodo hasta encontrar el estudiante a eliminar.
    while( aux != NULL && aux -> boleta != boleta ) {
        aux = aux -> next;
    }
    if( aux != NULL ) {
        anterior  = aux -> before;
        siguiente = aux -> next;
        
        cleanString( aux -> name );
        cleanString( aux -> lastnames );

        // Significa que es el primer elemento a eliminar.
        if( anterior == NULL ) {
            (*inicio)           = aux -> next;
            siguiente -> before = aux -> before;
        }
        // Significa que es el ultimo elemento a eliminar.
        if( siguiente == NULL ) {
            (*final)         = aux -> before;
            anterior -> next = aux -> next;
        }
        // Significa que el elemento a eliminar se encuentra entre 1 < n < max - 1 
        if( anterior != NULL && siguiente != NULL ) {
            anterior -> next    = aux -> next;
            siguiente -> before = aux -> before;
        }

        free( aux );
    }
}

void getStringFromConsole( Letter **string ) {
    char caracter;
    // Si el puntero a string es NULL, asignar memoria para el primer nodo
    if (*string == NULL) {
        *string = malloc(sizeof(Letter));
        (*string)->siguiente = NULL;
    }
    Letter *current = *string;
    while( ( caracter = getchar() ) != '\n') {
        addCharacter( &current, caracter );
        current = current->siguiente;
    }
}
int main( void ) {
    // 1. Inicilaizamos el inicio y final de la lista.
    Student *inicio, *final;
    int opt, mode, boleta;

    inicio = NULL;
    final  = NULL;

    printf("* ---------------------- *\n");
    printf("| SAES 2.0 versión ESCOM |\n");
    printf("* ---------------------- *\n");

    do {
        printf("\t * - MENU \n");
        printf("\t - > 1. Dar de alta a un alumno. \n");
        printf("\t - > 2. Mostrar alumnos dados de alta. \n");
        printf("\t - > 3. Modificar registro de un alumno. \n");
        printf("\t - > 4. Eliminar a un alumno (p/boleta) \n");
        printf("\t - > 0. Salir \n\n");

        scanf("%d", &opt );

        // Dar de alta un alumno.
        if( opt == 1 ) {

            Letter *name = NULL;
            Letter *lastnames = NULL;
            getchar(); // Para tomar el ultimo '\n'

            printf("Ingrese el nombre del alumno: ");
            getStringFromConsole( &name );
            printf("\n");

            printf("Ingrese los apellidos del alumno: ");
            getStringFromConsole( &lastnames );
            printf("\n");

            printf("Ingrese la boleta del alumno: ");
            scanf("%d", &boleta);
            printf("\n");

            insertOrderedStudent( &inicio, &final, boleta, name, lastnames );

            fflush( stdin );
        }
        // Mostrar usuarios.
        if( opt == 2 ) {
            printf("Mostrar de forma: Ascendente (1), Descendente (2): ");
            scanf("%d", &mode);

            if( mode == 1 ) 
                showStudentsByAsc( inicio );
            if( mode == 2 ) 
                showStudentsByDesc( final );
            
            printf("\n");

        }
        if( opt == 3 ) {
            printf("\nIngrese la boleta del usuario a modificar: ");
            scanf("%d", &boleta);

            Student *update = searchByBoleta( &inicio, boleta );

            fflush( stdin );

            printf(" ** Datos ** \n\n Nombre: ");
            showString( update -> name );
            printf("\n Apellidos: ");
            showString( update -> lastnames );
            printf("\n\n");

            if( update != NULL ) {
                printf("\nIngresa que dato quieres modificar: \n 1) Nombre \n 2) Apellidos: \n");
                fflush( stdin );
                int toModify;
                scanf("%d", &toModify );

                getchar();

                if( toModify == 1 ) {
                    Letter *newName = NULL;
                    printf("\nIngrese el nombre nuevo: ");
                    getStringFromConsole( &newName );

                    // Limpiar anterior nombre.
                    cleanString( update -> name );

                    update -> name = newName;

                    fflush( stdin );
                }
                else {
                    Letter *newLastname = NULL;

                    printf("Ingrese el apellido nuevo: ");
                    getStringFromConsole( &newLastname );

                    Letter *newName = NULL;
                    printf("\nIngrese el nombre nuevo: ");
                    getStringFromConsole( &newName );

                    deleteStudentByHisBoleta( &inicio, &final, boleta );

                    insertOrderedStudent( &inicio, &final, boleta, newName, newLastname );

                    fflush( stdin );
                }
            }
            else 
                printf("X -  Estudiante no encontrado\n");
        }
        // Eliminar Usuario
        if( opt == 4 ) {

            printf("Ingrese la boleta: ");
            scanf("%d", &boleta );
            printf("\n");

            deleteStudentByHisBoleta( &inicio, &final, boleta );
            printf("Usuario con boleta %d Eliminado ", boleta );
            printf("\n");

        }
        fflush( stdin );
    } while ( opt != 0 );

    return 0;
}