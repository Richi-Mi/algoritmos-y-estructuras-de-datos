#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int count = 0;
    char texto[100];
    char *words[100]; // Se asume un máximo de 100 palabras para el ejemplo

    printf("Escriba un texto: ");
    fgets(texto,sizeof(texto),stdin);

    char *word = strtok(texto, " \n");

    while (word != NULL) {
        words[count++] = word;      //Guarda palabras en arreglo de apuntadores 'words'
        printf(" %s ",word);
        word = strtok(NULL, " \n");
        
    }
    

}