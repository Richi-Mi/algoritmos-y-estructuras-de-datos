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
    
    // Comprobamos que no existan elementos en el Nodo.
    if( *start == NULL ) {
        *start = new;
    }
    // Si si hay elementos
    else {
        Letter *aux = *start;
        while( aux -> siguiente != NULL ) {
            aux = aux -> siguiente;
        }
        aux -> siguiente = new;
    }
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
void showStudents( Student *s ) {
    Student *aux = s;
    while ( s != NULL ) {
        printf("%d, ", s -> boleta );
        s = s -> next;
    }
}
void showString( Letter *inicio ) {
    Letter *aux = inicio;
    while( aux != NULL ) {
        printf("%c", aux -> value );
        aux = aux -> siguiente;
    }
}
int main( void ) {
    // 1. Inicilaizamos el inicio y final de la lista.
    Student *inicio, *final;
    int opt, i = 0;

    inicio = NULL;
    final  = NULL;

    Letter *c = malloc( sizeof( Letter ) );
    c -> value = 'c';
    c -> siguiente = NULL;

    char l;

    while ( (l = getchar()) != '\n' ) {
        addCharacter( &c, l );               
    }

    printf("* ---------------------- *\n");
    printf("| SAES 2.0 versión ESCOM |\n");
    printf("* ---------------------- *\n");

    do {
        printf("\t * - MENU \n");
        printf("\t - > 1. Dar de alta a un alumno. \n");
        printf("\t - > 2. Mostrar alumnos dados de alta. \n");
        printf("\t - > 3. Modificar registro de un alumno. \n");
        printf("\t - > 4. Eliminar a un alumno (p/boleta) \n");
        printf("\t - > 0. Salir \n");

        scanf("%d", &opt );

        fflush( stdin );

        if( opt == 1 ) {

            addElementToStart( &inicio, &final, 2024 + i, c, c );
            i++;
        }
        if( opt == 2 ) {
            showString( c );
            showStudents( inicio );
        }
        if( opt == 3 ) {

        }
        if( opt == 4 ) {

        }
    } while ( opt != 0 );
    return 0;
}