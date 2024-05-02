#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Persona {
    char nombre[255];
    char rfc[13];
} Persona;

typedef struct Cola {
    int head;
    int tail;

    Persona personas[MAX_SIZE];

} Cola;

void main( void ) {
    return;
}