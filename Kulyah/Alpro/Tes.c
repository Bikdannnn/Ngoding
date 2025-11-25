#include <stdio.h> 

//M. Wildan Humaidi S. Budi

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int terkecil = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[terkecil]) {
                terkecil = j;
            }
        }
        // Swap
        int temp = arr[i];
        arr[i] = arr[terkecil];
        arr[terkecil] = temp;
    }
}

int main() {
    int N;
    int angka[1000]; 

    printf("Masukkan data dengan rentang 1 - 1000\n");
    scanf("%d", &N);

    if (N < 1 || N > 1000) {
        printf("Hanya Bisa 1 - 1000\n");
        return 1;
    } else {
        printf("Masukkan datanya\n");
        for (int i = 0; i < N; i++) {
            scanf("%d", &angka[i]);
        }
    }

    selectionSort(angka, N);

    printf("Hasil:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", angka[i]);
    }
    printf("\n");

    return 0;
}

