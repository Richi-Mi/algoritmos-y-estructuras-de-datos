#include<stdio.h>
#include<stdlib.h>
#define MAX 21
int i; 
typedef struct Element{
	int valor; 
}Element;
struct colaEstatica{
	int colae[MAX];
	int tope;  
	int inicio; 
	
};	
struct colaEstatica cola; 
void inicializar(){
	cola.inicio=0; 
	cola.tope=-1; //elemnto ingresado primer elemto en -1
	for(i = 0; i < MAX; i++){//iterar los elemntos
		cola.colae[i]=' '; 
	}
}
int empty(){//ningun elemnto cola vacia
	return cola.tope==-1; 
	}
int full(){ 
	return cola.tope==MAX-1; //la cola ya esta llena 
	}
int push(int valor){//meter encolar
	if(full()){
		printf("Cola llena\n"); 
	}else{
		cola.tope++;
		cola.colae[cola.tope]=valor; 
	}
}
int pop(){//sacar desencolar
	if(empty()){
		printf("Cola vacia\n"); 
	}else{
		cola.colae[0]=' '; 
		cola.tope--; 
	}
}
void frente(){
	printf("Elemento en enfrente es: %d\n", cola.colae[cola.inicio]); 
}
void vaciar(){
	inicializar();
	
}
void ordenar(){
	for(i=0; i<MAX; i++){
		cola.colae[i]=cola.colae[i+1]; 
	}
}
void mostrar(){
	if(empty()){
	printf("Cola vacia"); 
	}else{
		for(i=cola.inicio; i<=cola.tope; i++){
		printf("Elemento %i de la cola es %i\n", i+1, cola.colae[i]); 
	    }
	}
		
}
int main(){
	printf("Bienvenido Guerrero Dragon Uwu\n");
	inicializar(); 
	int valor; 
	int op; 
	do{
		printf("\n--------------------------------\n");
        printf("1) Encolar (Inserta un elemento)\n");
        printf("2) Desencolar (Elimina un elemento) \n");
        printf("3) Frente (Elemento que esta al inicio) \n");
        printf("4) Vaciar cola (Elimina)\n");
        printf("5) Mostrar cola \n"); 
        printf("6) salir Zzz\n");
        printf("Ingrese una opcion \n");
        scanf("%d", &op);
        switch(op){
        	case 1:
			printf("Ingrese un elemento "); 
			scanf("%d", &valor);
			push(valor);  
			mostrar();  
        	break; 
        	case 2: 
        	pop(); 
        	ordenar(); 
        	mostrar(); 
        	break; 
        	case 3:  
			frente();  
        	break;
			case 4:
			vaciar(); 
        	case 5:
			mostrar(); 
        	break; 
        	case 6:
            printf("Que la fuerza te acompañe...\n");
            break;
            default:
            printf("ERROR zzz.\n");
		}
	}while(op!=6); 
	return 0; 

}