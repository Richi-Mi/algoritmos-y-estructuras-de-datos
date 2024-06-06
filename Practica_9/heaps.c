void changeAtoB(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}
  
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      changeAtoB(&arr[i], &arr[largest]);
      maxHeapify(arr, n, largest);
    }
}
void buildMaxHeap( int MAX, int arr[] ) {
    for (int i = MAX / 2 - 1; i >= 0; i--)
        maxHeapify(arr, MAX, i);
}
void heapSort(int arr[], int n) {
    buildMaxHeap( n, arr );
  
    for (int i = n - 1; i >= 0; i--) {
      changeAtoB( &arr[0], &arr[i]);
      maxHeapify(arr, i, 0);
    }
  }
  
void showElements(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
}
void enQueue( int arr[], int n, int m, int element ) {
    arr[n] = element;
    maxHeapify(arr, m, n);
}
int deQueue( int arr[], int n ) {
    int deQueueElement = arr[0], aux = arr[1];

    for( int i = 0; i < n; i++ ) {
        arr[i] = aux;
        aux = arr[ i + 1];
    }
    buildMaxHeap( n, arr );
    
    return deQueueElement;
}