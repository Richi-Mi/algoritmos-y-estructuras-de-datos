#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int i = 1;
    char word[50];
    char *pWord_1, *pWord_2;

    printf("Escriba una palabra: ");
    fgets(word,sizeof(word),stdin);

    pWord_1 = &word[0];
    pWord_2 = word[0];

    printf("%c\t%s\n",pWord_1+i, pWord_1+i);    //Escribe palabra completa
    printf("%c\t%s\n",pWord_2+i, pWord_2+i);    //Escribe un solo caracter

}