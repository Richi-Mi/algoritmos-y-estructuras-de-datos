int parent( int i ) {
  return i / 2;
}
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
void heapIncreaseKey( int arr[], int i, int key ) {
  if( key < arr[ i ] ) {
    printf("La nueva llave es menor que la anterior");
  }
  else {
    arr[i] = key;
    while( i >= 0 && (arr[ parent(i) ] > arr[i]) ) {
      changeAtoB( &arr[i], &arr[parent(i)] );
      i = parent(i);
    }
  }
}
void maxHeapInsert( int arr[], int max, int key ) {
  arr[ max ] = -1000;
  heapIncreaseKey( arr, max, key );
}