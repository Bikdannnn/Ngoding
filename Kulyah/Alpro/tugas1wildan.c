#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    char nim[20];
    int umur;
    float ipk;
};

struct Mahasiswa mahasiswa[5];

int main() {
    float nilai_baru;
    int sks_nilai_baru;
    char nim_user[20];
    int ditemukan = 0;

    strcpy(mahasiswa[3].nama, "Dzaky");
    strcpy(mahasiswa[3].nim, "D121241067");
    mahasiswa[3].umur = 19;
    mahasiswa[3].ipk = 3.0;

    strcpy(mahasiswa[1].nama, "Amar");
    strcpy(mahasiswa[1].nim, "D121241076");
    mahasiswa[1].umur = 18;
    mahasiswa[1].ipk = 2.7;

    strcpy(mahasiswa[2].nama, "Aisy");
    strcpy(mahasiswa[2].nim, "D121241037");
    mahasiswa[2].umur = 19;
    mahasiswa[2].ipk = 2.8;

    strcpy(mahasiswa[0].nama, "Wildan");
    strcpy(mahasiswa[0].nim, "D121241058");
    mahasiswa[0].umur = 18;
    mahasiswa[0].ipk = 2.9;

    printf("===== Program Ubah IPK Mahasiswa =====\n");

    printf("Masukkan NIM Anda: \n");
    fgets(nim_user, sizeof(nim_user), stdin);
    nim_user[strcspn(nim_user, "\n")] = '\0'; 

    for (int i = 0; i < 4; i++) {
        if (strcmp(mahasiswa[i].nim, nim_user) == 0) {
            ditemukan = 1;
            printf("Data ditemukan: %s, IPK: %.2f\n", mahasiswa[i].nama, mahasiswa[i].ipk);

            printf("Masukkan Nilai baru: \n");
            scanf("%f", &nilai_baru);

            printf("Masukkan SKS: \n");
            scanf("%d", &sks_nilai_baru);

            mahasiswa[i].ipk = (sks_nilai_baru * nilai_baru) / 20 + mahasiswa[i].ipk;

            printf("IPK baru anda: %.2f\n", mahasiswa[i].ipk);
        }
    }

    if (!ditemukan) {
        printf("Mahasiswa dengan NIM %s tidak ditemukan.\n", nim_user);
    }
}