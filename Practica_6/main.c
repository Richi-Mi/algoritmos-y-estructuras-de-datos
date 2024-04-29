#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDAD_MAXIMA 10

// Definición de la estructura Persona
struct Persona {
    char nombre[ 50 ];
    char rfc[ 13 ]; // RFC tiene una longitud fija de 13 caracteres
};

// Definición de la lista de personas
struct ListaPersonas {
    struct Persona personas[ CAPACIDAD_MAXIMA ];
    int cantidad; // Para llevar un registro de la cantidad de personas en la lista
};

// Función para insertar una persona al final de la lista
void insertarAlFinal( struct ListaPersonas *lista, struct Persona persona ) {
    if ( lista -> cantidad < CAPACIDAD_MAXIMA ) {
        lista -> personas[ lista-> cantidad ] = persona;
        lista -> cantidad++;

        printf("Persona insertada correctamente.\n");
    } 
    else {
        printf("La lista está llena, no se puede insertar más personas.\n");
    }
}

// Función para insertar una persona en una posición específica de la lista
void insertarEnPosicion(struct ListaPersonas *lista, struct Persona persona, int posicion) {
    if ( posicion >= 0 && posicion < CAPACIDAD_MAXIMA && lista->cantidad < CAPACIDAD_MAXIMA ) {
        // Desplazar las personas hacia adelante para hacer espacio para la nueva persona
        for ( int i = lista -> cantidad; i > posicion; i-- ) {
            lista->personas[i] = lista->personas[i - 1];
        }
        lista->personas[posicion] = persona;
        lista->cantidad++;
        printf("Persona insertada correctamente en la posición %d.\n", posicion);
    } 
    else {
        printf("La posición especificada no es válida o la lista está llena.\n");
    }
}

// Función para buscar una persona por RFC en la lista
void buscarPersona(struct ListaPersonas lista, char rfc[13]) {
    int encontrada = 0;
    for (int i = 0; i < lista.cantidad; i++) {
        if (strcmp(lista.personas[i].rfc, rfc) == 0) {
            printf("Persona encontrada:\n");
            printf("Nombre: %s\n", lista.personas[i].nombre);
            printf("RFC: %s\n", lista.personas[i].rfc);
            encontrada = 1;
            break;
        }
    }
    if (!encontrada) {
        printf("Persona con RFC %s no encontrada.\n", rfc);
    }
}

// Función para borrar una persona por RFC de la lista
void borrarPersona(struct ListaPersonas *lista, char rfc[13]) {
    int encontrado = 0;
    for (int i = 0; i < lista->cantidad; i++) {
        if (strcmp(lista->personas[i].rfc, rfc) == 0) {
            for (int j = i; j < lista->cantidad - 1; j++) {
                lista->personas[j] = lista->personas[j + 1];
            }
            lista->cantidad--;
            printf("Persona con RFC %s borrada correctamente.\n", rfc);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Persona con RFC %s no encontrada para ser borrada.\n", rfc);
    }
}

// Función para mostrar todas las personas en la lista
void mostrarPersonas(struct ListaPersonas lista) {
    printf("Lista de personas:\n");
    for (int i = 0; i < lista.cantidad; i++) {
        printf("%d. Nombre: %s, RFC: %s\n", i + 1, lista.personas[i].nombre, lista.personas[i].rfc);
    }
    printf("Total de personas en la lista: %d\n", lista.cantidad);
}

// Función principal (menú)
int main() {
    struct ListaPersonas lista = {{}, 0}; // Inicializar la lista de personas

    while (1) {
        int opcion;
        printf("\nMenú:\n");
        printf("1. Dar de alta a una persona\n");
        printf("2. Buscar a una persona por RFC\n");
        printf("3. Borrar a una persona por RFC\n");
        printf("4. Mostrar todos los elementos de la lista\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                struct Persona nueva_persona;
                printf("Ingrese el nombre de la persona: ");
                scanf("%s", nueva_persona.nombre);
                printf("Ingrese el RFC de la persona: ");
                scanf("%s", nueva_persona.rfc);
                insertar_al_final(&lista, nueva_persona);
                break;
            }
            case 2: {
                char rfc[13];
                printf("Ingrese el RFC de la persona que desea buscar: ");
                scanf("%s", rfc);
                buscar_persona(lista, rfc);
                break;
            }
            case 3: {
                char rfc[13];
                printf("Ingrese el RFC de la persona que desea borrar: ");
                scanf("%s", rfc);
                borrar_persona(&lista, rfc);
                break;
            }
            case 4:
                mostrar_personas(lista);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                return 0;
            default:
                printf("Opción no válida. Por favor, seleccione una opción del menú.\n");
        }
    }

    return 0;
}
