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
void cleanString( Letter *inicio ) {
    printf("Usuario Eliminado: ");
    while( inicio != NULL ) {
        Letter *aux = inicio;

        inicio = inicio -> siguiente;

        printf("%c", aux -> value );

        free( aux );
    }
    printf("\n");
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
            (*inicio)        = aux -> before;
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


// METODOS PARA PODER MOSTRAR LA INFORMACIÓN.
void showString( Letter *inicio ) {
    Letter *aux = inicio;
    while( aux != NULL ) {
        printf("%c", aux -> value );
        aux = aux -> siguiente;
    }
}
void showStudents( Student *s ) {
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

int main( void ) {
    // 1. Inicilaizamos el inicio y final de la lista.
    Student *inicio, *final;
    int opt, i = 0;

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

        fflush( stdin );

        // Dar de alta un alumno.
        if( opt == 1 ) {

            Letter *name = NULL;
            Letter *lastnames = NULL;
            int boleta;

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

            addElementToStart( &inicio, &final, boleta, name, lastnames );

            i++;
            fflush( stdin );
        }
        if( opt == 2 ) {
            showStudents( inicio );
        }
        if( opt == 3 ) {

        }
        if( opt == 4 ) {
            int boleta;
            printf("Ingrese la boleta: ");
            scanf("%d", &boleta );
            printf("\n");

            deleteStudentByHisBoleta( &inicio, &final, boleta );
        }
    } while ( opt != 0 );
    return 0;
}