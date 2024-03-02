#include <stdio.h>
#include <stdlib.h>

struct Domicilio
{
    char calle[80];
    int mz;
    int lote;
};


struct Persona
{
    char nombre[80];
    int edad;
    struct Domicilio *domicilio;
};

void menu() {
    printf("Bienvenido a esta app.");  
}

void main() {
    menu();

}