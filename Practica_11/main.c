#include <stdio.h>
#include <stdlib.h>

#define m 311
#define keySize 16
#define keyArchiveSize 300
typedef struct Nodo {
    int valor;

    struct Nodo *next;
} Nodo;

void addElementToTable( Nodo **p, int value ) {
    // Creación del nuevo nodo.
    Nodo *new = malloc( sizeof( Nodo ) );
    new -> valor = value;
    new -> next  = NULL;

    if( *p == NULL ) {
        *p = new;
    }
    else {
        Nodo *aux = *p;
        while( aux -> next != NULL ) {
            aux = aux -> next;
        }
        aux -> next = new;
    }
}
int removeElementFromTable( Nodo **p, int key ) {
    if( (*p) -> next == NULL ) {
        free( *p );
        *p = NULL;

        return 1;
    }
    else {
        Nodo *anterior;
        Nodo *aux = *p;

        while( aux != NULL && aux -> valor != key ) {
            anterior = aux;
            aux = aux -> next;
        }   

        if( aux != NULL ) {
            anterior -> next = NULL;

            free( aux );

            return 1;
        }
        else 
            return 0;
    }
}
void getKeysFromFile( int arr[] ) {
    FILE *file = fopen("claves.txt", "r");

    char linea[ keySize ];
    int i = 0;

    while( fgets( linea, sizeof( linea ), file ) != NULL ) {
        arr[i] = atoi( linea );
        i++;
    }
    fclose( file );
}

int metodoDivision( int k ){
    return k % m;
}

// PROGRAMA 1.

int main(){

    // 1. Obtener las claves del archivo. 
    int keys[ keyArchiveSize ], i, option, valueToInsert, key;
    getKeysFromFile( keys );

    // 2. Crear tabla hash.
    struct Nodo* tablaHash[ m ];

    for( i = 0; i < m; i++ ) 
        tablaHash[i] = NULL;

    // 3. Inicializar la tabla Hash.
    for( i = 0; i < 300; i++ ) {
        int indice = metodoDivision( keys[i] );

        Nodo *new = malloc( sizeof( Nodo ) );
        new -> valor = keys[i];
        new -> next  = NULL;
        
        if( tablaHash[indice] == NULL ) {
            tablaHash[indice] = new;    
        } 
        else {
            Nodo *aux = tablaHash[indice];
            while( aux -> next != NULL ) {
                aux = aux -> next;
            }
            tablaHash[indice] -> next = new;
        }
    }
    do {
        printf("\n ---- Tablas Hash ---- \n");
        printf(" 1. Insertar elementos \n");
        printf(" 2. Eliminar elementos \n");
        printf(" 3. Busqueda elementos \n");
        printf(" 4. Imprimir Tabla Hash \n");
        printf(" 0. salir \n\n");

        scanf("%d", &option );
        
        if( option == 1 ) {
            printf("Ingrese la clave a ingresar (8 digitos): ");
            scanf("%d", &valueToInsert );

            int indice = metodoDivision( valueToInsert );
            Nodo *inicio = tablaHash[indice];

            addElementToTable( &tablaHash[indice], valueToInsert );
            printf("Elemento Insertado en el indice: %d\n", indice );
        }
        if( option == 2 ) {
            printf("Ingrese la clave a eliminar: ");
            scanf("%d", &valueToInsert );

            int indice = metodoDivision( valueToInsert );
            Nodo *inicio = tablaHash[ indice ];

            int deleted = removeElementFromTable( &inicio, valueToInsert );
            if( deleted ) {
                printf("Elemento eliminasdo del indice: %d", indice );
            }
            else {
                printf("Elemento no encontrado \n");
            }
        }
        if( option == 3 ) {
            printf("Ingrese la clave a buscar: ");
            scanf("%d", &key );

            int indice = metodoDivision( key );
            Nodo *inicio = tablaHash[ indice ];

            while( inicio != NULL && inicio -> valor != key )
                inicio = inicio -> next;

            if( inicio != NULL ) 
                printf("Clave encontrada en el indice: %d\n", indice );
            else 
                printf("La clave no se encuentra en la tabla hash\n");
        }

        if( option == 4 ) {            
            for( i = 0; i < m; i++ ) {
                Nodo *aux = tablaHash[i];
                if( aux != NULL ) {
                    printf("Indice: %d", i );

                    while( aux != NULL ) {
                        printf(" -> %d ", aux -> valor );
                        aux = aux -> next;
                    }

                }
                printf("\n");
            }
        }
    } while( option != 0 ); 


    return 0;
}