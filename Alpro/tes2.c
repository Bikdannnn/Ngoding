#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int N;
    int capacity = 10; 
    int size = 0;      
    int* angka = (int*)malloc(capacity * sizeof(int));
    
    printf("Masukkan Angka yang akan diurutkan\n");
    
    while(scanf("%d", &N) == 1) {
        if (size >= capacity) {
            capacity *= 2;
            angka = (int*)realloc(angka, capacity * sizeof(int));
        }
        angka[size++] = N;
        
        if (getchar() == '\n') break;
    }
    
    quickSort(angka, 0, size - 1);
    
    printf("Hasilnya: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", angka[i]);
    }
    printf("\n");
    
    free(angka);
    return 0;
}