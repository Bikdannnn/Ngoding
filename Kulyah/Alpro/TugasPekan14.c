#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa {
    char NIM[10];
    char Nama[30];
    float ipk;
    struct Mahasiswa *next;
};
typedef struct Mahasiswa mhs;

int main(void) {
    mhs *head = NULL, *node = NULL, *tail = NULL, *temp = NULL;
    int jumlah;

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jumlah);

    for (int i = 0; i < jumlah; i++) {
        node = (mhs*)malloc(sizeof(mhs));
        node->next = NULL;

        printf("\nMasukkan nama mahasiswa ke-%d: ", i + 1);
        scanf("%s", node->Nama);
        printf("Masukkan NIM mahasiswa ke-%d: ", i + 1);
        scanf("%s", node->NIM);
        printf("Masukkan IPK mahasiswa ke-%d: ", i + 1);
        scanf("%f", &node->ipk);

        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int operator = -1;
    
    while (operator !=0) {
        printf("\nOperasi apa yang ingin Anda lakukan?: \n1. Create (Tambah)\n2. Read (Cari)\n3. Update (Ubah)\n4. Delete (Hapus)\n> ");
        scanf("%d", &operator);
    
        if (operator < 1 || operator > 4) {
            printf("Operasi tidak valid.\n");
            return 0;
        }
    
        if (operator == 1) {
            int ops;
            printf("\nDi mana kamu ingin memasukkan data baru?: \n1. Di akhir\n2. Di antara (setelah NIM tertentu)\n> ");
            scanf("%d", &ops);
    
            node = (mhs*)malloc(sizeof(mhs));
            node->next = NULL;
            printf("\nMasukkan nama mahasiswa baru: ");
            scanf("%s", node->Nama);
            printf("Masukkan NIM mahasiswa baru: ");
            scanf("%s", node->NIM);
            printf("Masukkan IPK mahasiswa baru: ");
            scanf("%f", &node->ipk);
    
            if (ops == 1) {
                if (head == NULL) {
                    head = tail = node;
                } else {
                    tail->next = node;
                    tail = node;
                }
            } else if (ops == 2) {
                char targetNIM[10];
                printf("Masukkan NIM setelah mana data baru ingin dimasukkan: ");
                scanf("%s", targetNIM);
    
                temp = head;
                while (temp != NULL && strcmp(temp->NIM, targetNIM) != 0) {
                    temp = temp->next;
                }
    
                if (temp == NULL) {
                    printf("NIM tidak ditemukan.\n");
                    free(node);
                } else {
                    node->next = temp->next;
                    temp->next = node;
                    if (temp == tail) {
                        tail = node;
                    }
                }
            } else {
                printf("Pilihan tidak valid.\n");
                free(node);
            }
        }
    
        if (operator == 2) {
            char cariNIM[10];
            printf("Masukkan NIM yang ingin dicari: ");
            scanf("%s", cariNIM);
    
            temp = head;
            while (temp != NULL) {
                if (strcmp(temp->NIM, cariNIM) == 0) {
                    printf("\nData ditemukan:\nNama: %s\nNIM: %s\nIPK: %.2f\n", temp->Nama, temp->NIM, temp->ipk);
                    break;
                }
                temp = temp->next;
            }
            if (temp == NULL) {
                printf("Data dengan NIM tersebut tidak ditemukan.\n");
            }
        }
    
        if (operator == 3) {
            char ubahNIM[10];
            printf("Masukkan NIM yang ingin diubah datanya: ");
            scanf("%s", ubahNIM);
    
            temp = head;
            while (temp != NULL) {
                if (strcmp(temp->NIM, ubahNIM) == 0) {
                    printf("Masukkan nama baru: ");
                    scanf("%s", temp->Nama);
                    printf("Masukkan IPK baru: ");
                    scanf("%f", &temp->ipk);
                    printf("Data berhasil diupdate.\n");
                    break;
                }
                temp = temp->next;
            }
            if (temp == NULL) {
                printf("Data tidak ditemukan.\n");
            }
        }
    
        if (operator == 4) {
            char hapusNIM[10];
            printf("Masukkan NIM yang ingin dihapus: ");
            scanf("%s", hapusNIM);
    
            mhs *prev = NULL;
            temp = head;
    
            while (temp != NULL && strcmp(temp->NIM, hapusNIM) != 0) {
                prev = temp;
                temp = temp->next;
            }
    
            if (temp == NULL) {
                printf("Data tidak ditemukan.\n");
            } else {
                if (temp == head) {
                    head = head->next;
                } else {
                    prev->next = temp->next;
                }
                if (temp == tail) {
                    tail = prev;
                }
                free(temp);
                printf("Data berhasil dihapus.\n");
            }
        }
    
        printf("\nData Mahasiswa:\n");
        temp = head;
        while (temp != NULL) {
            printf("Nama: %s | NIM: %s | IPK: %.2f\n", temp->Nama, temp->NIM, temp->ipk);
            temp = temp->next;
        }
    }
    while (head != NULL) {
    mhs *hapus = head;
    head = head->next;
    free(hapus);
}

    return 0;
}
