#include<stdio.h>
#include<stdlib.h>

void merge(int *arr, int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    // Crear arrays temporales
    int L[n1], R[n2];

    // Copiar datos a los arrays temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    // Combinar los arrays temporales de vuelta en arr[p..r]
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia los elementos restantes de L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int p, int r) {
    if (p < r) {
        // Encuentra el punto medio del arreglo
        int q = p + (r - p) / 2;

        // Ordena la primera y segunda mitad del array
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);

        // Combina las mitades ordenadas
        merge(arr, p, q, r);
    }
}

int main(){

    int arr[10] = {  3, 67, 32, 76, 12, 89, 1, 56, 32, 16 };
    mergeSort( arr, 0, 9 );

    int i;
    for( i = 0; i < 10; i++ ) {
        printf("%d, ", arr[i]);
    }

}