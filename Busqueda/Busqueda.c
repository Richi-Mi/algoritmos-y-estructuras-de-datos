#include <stdio.h>
#include <stdlib.h>

int busquedaSecuencial(int a[], int n, int dato){

    int i;

    for(i=0 ; i<n ; i++){

        if(a[i] == dato){
            return i;
        }

    }

    return -1;

}


int secuencialSimplificada( int arr[], int len, int v ){
    
	int i = 0;
	
    while( i < len && arr[i] != v ) 
        i++;
        
    return i < len? i : -1;
    
}

int busquedaBinaria( int arr[], int v, int i, int j ){
    
	int k = ( i + j ) / 2;
    // Condicion de corte
    if( i >= j ) return -i;

    if( arr[k] == v ) return k;
    
	else {
        if( arr[k] < v ) i = k+1;
        else j = k-1;

        // Invocación recursiva osi osi
        return busquedaBinaria( arr, v , i, j );
    } 
}
