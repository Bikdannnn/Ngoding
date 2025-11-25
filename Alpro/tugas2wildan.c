#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa {
    char nim[20];
    char nama[50];
    float ipk;
    struct Mahasiswa* next;
} Mahasiswa;

Mahasiswa* buatBaru(const char* nim, const char* nama, float ipk) {
    Mahasiswa* mhs = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    strcpy(mhs->nim, nim);
    strcpy(mhs->nama, nama);
    mhs->ipk = ipk;
    mhs->next = NULL;
    return mhs;
}

void tambah(Mahasiswa** head) {
    char nim[20], nama[50];
    float ipk;

    printf("NIM  : ");
    scanf("%s", nim);
    printf("Nama : ");
    scanf(" %[^\n]", nama);
    printf("IPK  : ");
    scanf("%f", &ipk);

    Mahasiswa* baru = buatBaru(nim, nama, ipk);

    if (*head == NULL) {
        *head = baru;
    } else {
        Mahasiswa* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void ubahIPK(Mahasiswa* head, const char* nim) {
    Mahasiswa* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->nim, nim) == 0) {
            printf("Data ditemukan: %s - %s - IPK: %.2f\n", temp->nim, temp->nama, temp->ipk);
            printf("Masukkan IPK baru: ");
            scanf("%f", &temp->ipk);
            printf("IPK berhasil diperbarui!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Mahasiswa dengan NIM %s tidak ditemukan.\n", nim);
}

void hapus(Mahasiswa** head, const char* nim) {
    Mahasiswa* temp = *head;
    Mahasiswa* prev = NULL;

    while (temp != NULL && strcmp(temp->nim, nim) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Mahasiswa dengan NIM %s tidak ditemukan.\n", nim);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Data mahasiswa dengan NIM %s berhasil dihapus.\n", nim);
}

void tampil(Mahasiswa* head) {
    Mahasiswa* temp = head;
    if (temp == NULL) {
        printf("Belum ada data.\n");
        return;
    }
    printf("\nDaftar Mahasiswa:\n");
    while (temp != NULL) {
        printf("%s - %s - IPK: %.2f\n", temp->nim, temp->nama, temp->ipk);
        temp = temp->next;
    }
}

int main() {
    Mahasiswa* head = NULL;
    int menu, banyak, idx;
    char nimCari[20];

    do {
        printf("\n===== MENU UTAMA =====\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Ubah IPK\n");
        printf("3. Hapus Mahasiswa\n");
        printf("4. Lihat Semua Data\n");
        printf("5. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("Berapa mahasiswa yang ingin ditambah? ");
                scanf("%d", &banyak);
                for (idx = 0; idx < banyak; idx++) {
                    printf("\nMahasiswa ke-%d:\n", idx + 1);
                    tambah(&head);
                }
                break;
            case 2:
                printf("Masukkan NIM untuk update IPK: ");
                scanf("%s", nimCari);
                ubahIPK(head, nimCari);
                break;
            case 3:
                printf("Masukkan NIM yang akan dihapus: ");
                scanf("%s", nimCari);
                hapus(&head, nimCari);
                break;
            case 4:
                tampil(head);
                break;
            case 5:
                printf("Program selesai. Terima kasih.\n");
                break;
            default:
                printf("Pilihan tidak tersedia.\n");
        }

    } while (menu != 5);

    return 0;
}