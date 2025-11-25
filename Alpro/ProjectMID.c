#include <stdio.h>
#include <string.h>

#define MAX 10
#define WAKTU 15 

typedef struct {
    char nama[50];
} Pasien;

int main() {
    char cariNama[50];
    int ketemu = 0;

    Pasien antrian[MAX] = {
        {"Wildan"}, {"Amar"}, {"Winny"}, {"Suci"}, {"Aisy"},
        {"Fahrul"}, {"Randy"}, {"Nue"}, {"Alif"}, {"Imam"}
    };
    

    printf("=== Sistem Antrian Rumah Sakit ===\n");
    printf("Daftar Antrian Hari Ini:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d. %s\n", i + 1, antrian[i].nama);
    }

    printf("\nMasukkan nama yang ingin dicari: "); 
       scanf("%s", cariNama);

    for (int i = 0; i < MAX; i++) {
        if (strcmp(antrian[i].nama, cariNama) == 0) {
            ketemu = 1;
            int jam = 10 + (i * WAKTU) / 60;
            int menit = (i * WAKTU) % 60;
            printf("\n%s berada di antrian ke-%d\n", cariNama, i + 1);
            printf("Perkiraan waktu konsultasi: %02d:%02d\n", jam, menit);
            break;
        }
    }

    if (!ketemu) {
        printf("\nNama tidak ditemukan dalam antrian, silahkan daftar ulang dan datang besok hari.\n");
    }

    return 0;
}
