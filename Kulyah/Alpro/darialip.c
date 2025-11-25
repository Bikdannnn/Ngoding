#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa {
    char nim[20];
    char nama[50];
    float ipk;
    struct Mahasiswa* next;
};

struct Mahasiswa* buatNode(char nim[], char nama[], float ipk) {
    struct Mahasiswa* baru = (struct Mahasiswa*)malloc(sizeof(struct Mahasiswa));
    strcpy(baru->nim, nim);
    strcpy(baru->nama, nama);
    baru->ipk = ipk;
    baru->next = NULL;
    return baru;
}

void tambahMahasiswa(struct Mahasiswa** head) {
    char nim[20], nama[50];
    float ipk;

    printf("NIM  : ");
    scanf("%s", nim);
    printf("Nama : ");
    scanf(" %[^\n]", nama);
    printf("IPK  : ");
    scanf("%f", &ipk);

    struct Mahasiswa* baru = buatNode(nim, nama, ipk);

    if (*head == NULL) {
        *head = baru;
    } else {
        struct Mahasiswa* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void ubahIPK(struct Mahasiswa* head, char nim[]) {
    struct Mahasiswa* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->nim, nim) == 0) {
            printf("Mahasiswa ditemukan: %s - %s - IPK: %.2f\n", temp->nim, temp->nama, temp->ipk);
            printf("Masukkan IPK baru: ");
            scanf("%f", &temp->ipk);
            printf("IPK berhasil diupdate!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Mahasiswa dengan NIM %s tidak ditemukan.\n", nim);
}

void hapusMahasiswa(struct Mahasiswa** head, char nim[]) {
    struct Mahasiswa* temp = *head;
    struct Mahasiswa* prev = NULL;

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

void tampilkanMahasiswa(struct Mahasiswa* head) {
    struct Mahasiswa* temp = head;
    if (temp == NULL) {
        printf("Data kosong.\n");
        return;
    }
    printf("\nData Mahasiswa:\n");
    while (temp != NULL) {
        printf("%s - %s - IPK: %.2f\n", temp->nim, temp->nama, temp->ipk);
        temp = temp->next;
    }
}

int main() {
    struct Mahasiswa* head = NULL;
    int pilihan, jumlah, i;
    char nimInput[20];

    do {
        printf("\n===== MENU =====\n");
        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Ubah IPK Mahasiswa\n");
        printf("3. Hapus Mahasiswa\n");
        printf("4. Tampilkan Semua Data\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan jumlah mahasiswa yang ingin ditambahkan: ");
                scanf("%d", &jumlah);
                for (i = 0; i < jumlah; i++) {
                    printf("\nMahasiswa ke-%d:\n", i + 1);
                    tambahMahasiswa(&head);
                }
                break;
            case 2:
                printf("Masukkan NIM mahasiswa yang ingin diubah IPK-nya: ");
                scanf("%s", nimInput);
                ubahIPK(head, nimInput);
                break;
            case 3:
                printf("Masukkan NIM mahasiswa yang ingin dihapus: ");
                scanf("%s", nimInput);
                hapusMahasiswa(&head, nimInput);
                break;
            case 4:
                tampilkanMahasiswa(head);
                break;
            case 5:
                printf("Terima kasih telah menggunakan program ini.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 5);

    return 0;
}