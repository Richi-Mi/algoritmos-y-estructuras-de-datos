
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(){

    char texto[] = "Buenas";
    char *pTexto;
    int i=1;

    pTexto = &texto[i];

    printf("Direcion de memoria: %p\nValor en la variable texto: %c\nTexto completo :%s",pTexto+2,*(pTexto+2), pTexto);

}