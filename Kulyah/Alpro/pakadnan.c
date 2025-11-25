#include <stdio.h>
#include <string.h>

// Mendefinisikan struct untuk mahasiswa
struct Mahasiswa {
    char nama[50];
    char nim[15];
    float ipk;
};

// Fungsi untuk menampilkan data mahasiswa
void tampilkanData(struct Mahasiswa mhs[], int jumlah) {
    printf("\nData Mahasiswa:\n");
    printf("-------------------------------------------------\n");
    printf("No. | Nama Mahasiswa | NIM        | IPK\n");
    printf("-------------------------------------------------\n");
    for(int i = 0; i < jumlah; i++) {
        printf("%-3d | %-14s | %-10s | %.2f\n", i+1, mhs[i].nama, mhs[i].nim, mhs[i].ipk);
    }
    printf("-------------------------------------------------\n");
}

// Fungsi untuk mengubah IPK mahasiswa
void ubahIPK(struct Mahasiswa *mhs) {
    printf("Masukkan IPK baru untuk %s (NIM: %s): ", mhs->nama, mhs->nim);
    scanf("%f", &mhs->ipk);
    printf("IPK berhasil diubah!\n");
}

int main() {
    // Inisialisasi data mahasiswa
    struct Mahasiswa mahasiswa[3] = {
        {"Wildan", "20230001", 3.75},
        {"Amar", "20230002", 3.50},
        {"Aisy", "20230003", 3.85}
    };
    
    int jumlah_mhs = 3;
    int pilihan;
    
    printf("Program Data Mahasiswa - Ubah IPK\n");
    
    do {
        tampilkanData(mahasiswa, jumlah_mhs);
        
        printf("\nMenu:\n");
        printf("1. Ubah IPK Mahasiswa\n");
        printf("2. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);
        
        if(pilihan == 1) {
            int nomor;
            printf("Masukkan nomor mahasiswa yang ingin diubah IPK-nya (1-%d): ", jumlah_mhs);
            scanf("%d", &nomor);
            
            if(nomor >= 1 && nomor <= jumlah_mhs) {
                ubahIPK(&mahasiswa[nomor-1]);
            } else {
                printf("Nomor mahasiswa tidak valid!\n");
            }
        } else if(pilihan != 2) {
            printf("Pilihan tidak valid!\n");
        }
        
    } while(pilihan != 2);
    
    printf("Program selesai. Terima kasih!\n");
    
    return 0;
}