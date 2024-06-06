
void showElements(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
}
int deQueue( int arr[], int n ) {
    int deQueueElement = arr[0];
    int k = 1;
    int aux = arr[k];

    for( int i = 0; i < n; i++ ) {
        arr[i] = aux;

        k++;
        aux = arr[ k ];

    }

    heapSort( arr, n );
    
    return deQueueElement;
}