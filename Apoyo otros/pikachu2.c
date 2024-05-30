#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Nodo{
	int valor; 
	struct Nodo*siguiente;
}Nodo;

typedef struct Cola {
    Nodo* frente;
    Nodo* atras;
} Cola;

Cola* crearCola() {
    Cola* nueva = (Cola*)malloc(sizeof(Cola));
    nueva->frente = NULL;
    nueva->atras = NULL;
    return nueva;
}

void encolar(Cola* nueva, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->valor = valor;
    nuevo->siguiente = NULL;
    if (nueva->atras == NULL) {
        nueva->frente = nuevo;
        nueva->atras = nuevo;
    } else {
        nueva->atras->siguiente = nuevo;
        nueva->atras = nuevo;
    }
}

int desencolar(Cola* nueva) {
    if (nueva->frente == NULL)
        return -1;
    Nodo* p = nueva->frente;
    int valor = p->valor;
    nueva->frente = nueva->frente->siguiente;
    if (nueva->frente == NULL)
        nueva->atras = NULL;
    free(p);
    return valor;
}

Cola* suma(char* n1, char* n2) {
    Cola* resultado = crearCola(); //pila para almacenar la suma
    int carry = 0;
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    int maxLen = len1 > len2 ? len1 : len2;

    int i = 0;
while (i < maxLen || carry != 0) {
    int digito1, digito2;

    if (i < len1) {
        digito1 = n1[len1 - 1 - i] - '0';
    } else {
        digito1 = 0;
    }

    if (i < len2) {
        digito2 = n2[len2 - 1 - i] - '0';
    } else {
        digito2 = 0;
    }

    int suma = digito1 + digito2 + carry;
    encolar(resultado, suma % 10);
    carry = suma / 10;

    i++;
}
    return resultado;
}

void impResultado(Cola* nueva) {
    int *digitos = (int *)malloc(sizeof(int) * MAX); //arreglo para almacenar temporalmente los digitos
    int indice = 0;

    while (nueva->frente != NULL) {//se transfieren los digitos de la cola al arreglo
        digitos[indice++] = desencolar(nueva);
    }
    
    for (int i = indice - 1; i >= 0; i--) {
        printf("%d", digitos[i]);
    }
    printf("\n");

    free(digitos);
}


int main(){
	
	char n1[MAX],n2[MAX];
	printf("\tBIENVENIDO GUERRERO DRAGON uwu \n");
	printf("Ingresa el primer numero: \n");
	scanf("%s",&n1);
	printf("Ingresa el segundo numero: \n");
	scanf("%s",&n2);
	Cola* sumaT = suma(n1, n2);
    printf("Papu la suma es: ");
    impResultado(sumaT);
    return 0;

}