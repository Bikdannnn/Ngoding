#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // Untuk memcpy
#include <stdbool.h>  // Untuk tipe bool

#define N 3
#define N_SQUARED (N * N)
#define MAX_DEPTH 40 // Maksimum kedalaman pencarian untuk mencegah loop tak terbatas
#define MAX_STATES 362880 // 9! = Jumlah total permutasi untuk 9 ubin (8 ubin + 1 kosong)

// Mendefinisikan keadaan tujuan untuk 8-puzzle
// 0 mewakili ruang kosong
int goal_board[N_SQUARED] = {1, 2, 3, 4, 5, 6, 7, 8, 0};

// Struktur untuk merepresentasikan keadaan puzzle
typedef struct Node {
    int board[N_SQUARED]; // Papan puzzle
    int blank_pos;        // Posisi ubin kosong (indeks 0-8)
    int depth;            // Kedalaman simpul dalam pohon pencarian
    struct Node* parent;  // Pointer ke simpul induk untuk merekonstruksi jalur
    char move_made;       // Karakter yang mewakili langkah yang dibuat untuk mencapai keadaan ini ('U', 'D', 'L', 'R')
} Node;

// Arah untuk memindahkan ubin kosong (perubahan baris dan kolom)
// dr: Perubahan baris (-1=Atas, 1=Bawah, 0=Tidak ada)
// dc: Perubahan kolom (0=Tidak ada, -1=Kiri, 1=Kanan)
int dr[] = {-1, 1, 0, 0}; // Atas, Bawah, Kiri, Kanan
int dc[] = {0, 0, -1, 1}; // Atas, Bawah, Kiri, Kanan
char move_chars[] = {'U', 'D', 'L', 'R'}; // Karakter representasi gerakan

// Array global untuk menyimpan faktorial untuk fungsi ID unik papan
int factorial[N_SQUARED];

// Fungsi untuk menghitung faktorial yang akan digunakan dalam getUniqueBoardID
void faktorial() {
    factorial[0] = 1;
    for (int i = 1; i < N_SQUARED; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
}

// Array global untuk menyimpan tanda bahwa suatu keadaan telah dikunjungi
// Ukuran MAX_STATES (9!) memastikan ruang yang cukup untuk semua permutasi
bool visited_state_flags[MAX_STATES];

// List semua simpul yang dibuat untuk manajemen memori
Node** all_created_nodes = NULL;
int created_nodes_count = 0;
int created_nodes_capacity = 1000; // Kapasitas awal, akan diperluas jika diperlukan

// Fungsi untuk membuat simpul baru
Node* createNode(int board[N_SQUARED], int blank_pos, int depth, Node* parent, char move_made) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Alokasi memori gagal untuk simpul baru");
        exit(EXIT_FAILURE);
    }
    memcpy(newNode->board, board, N_SQUARED * sizeof(int));
    newNode->blank_pos = blank_pos;
    newNode->depth = depth;
    newNode->parent = parent;
    newNode->move_made = move_made;

    // Tambahkan simpul ke list semua simpul yang dibuat untuk nanti dibebaskan
    if (created_nodes_count == created_nodes_capacity) {
        created_nodes_capacity *= 2;
        all_created_nodes = (Node**)realloc(all_created_nodes, created_nodes_capacity * sizeof(Node*));
        if (all_created_nodes == NULL) {
            perror("Re-alokasi memori gagal untuk list simpul");
            exit(EXIT_FAILURE);
        }
    }
    all_created_nodes[created_nodes_count++] = newNode;

    return newNode;
}

// Fungsi untuk mencetak papan puzzle
void printBoard(int board[N_SQUARED]) {
    for (int i = 0; i < N_SQUARED; i++) {
        if (board[i] == 0) {
            printf("  "); // Cetak spasi untuk ubin kosong
        } else {
            printf("%2d", board[i]);
        }
        if ((i + 1) % N == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Fungsi untuk memeriksa apakah keadaan papan saat ini adalah keadaan tujuan
bool isGoalState(int board[N_SQUARED]) {
    for (int i = 0; i < N_SQUARED; i++) {
        if (board[i] != goal_board[i]) {
            return false;
        }
    }
    return true;
}

// Fungsi untuk mendapatkan representasi integer unik dari papan
// Ini menggunakan konsep sistem angka faktoradik untuk permutasi
// Mengembalikan ID unik dari 0 hingga (N_SQUARED!-1)
int getUniqueBoardID(int board[N_SQUARED]) {
    int id = 0;
    int temp_board[N_SQUARED];
    memcpy(temp_board, board, N_SQUARED * sizeof(int));

    for (int i = 0; i < N_SQUARED; i++) {
        int count_smaller_after = 0;
        for (int j = i + 1; j < N_SQUARED; j++) {
            if (temp_board[i] > temp_board[j]) {
                count_smaller_after++;
            }
        }
        id += count_smaller_after * factorial[N_SQUARED - 1 - i];
    }
    return id;
}

// Fungsi DFS rekursif
// current_node: simpul saat ini yang sedang dieksplorasi
// found_solution: pointer ke flag boolean untuk menghentikan pencarian setelah solusi ditemukan
void dfs(Node* current_node, bool* found_solution) {
    if (*found_solution) {
        return; // Jika solusi sudah ditemukan oleh cabang lain, hentikan
    }

    if (current_node->depth > MAX_DEPTH) {
        return; // Mencapai kedalaman maksimum, mundur
    }

    // Periksa apakah keadaan tujuan tercapai
    if (isGoalState(current_node->board)) {
        printf("Solusi ditemukan pada kedalaman: %d\n", current_node->depth);
        printf("Jalur solusi:\n");

        // Rekonstruksi dan cetak jalur dari simpul tujuan ke simpul awal
        Node* path[MAX_DEPTH + 1]; // +1 untuk simpul awal (kedalaman 0)
        int path_idx = 0;
        Node* temp = current_node;
        while (temp != NULL) {
            path[path_idx++] = temp;
            temp = temp->parent;
        }

        for (int i = path_idx - 1; i >= 0; i--) {
            printf("Langkah %d: ", path_idx - 1 - i);
            if (path[i]->move_made != '\0') { // Lewati untuk keadaan awal
                printf("Pindah %c\n", path[i]->move_made);
            } else {
                printf("Keadaan Awal\n");
            }
            printBoard(path[i]->board);
        }
        *found_solution = true; // Set flag bahwa solusi telah ditemukan
        return;
    }

    // Dapatkan ID unik untuk papan saat ini
    int current_board_id = getUniqueBoardID(current_node->board);

    // Tandai keadaan saat ini sebagai telah dikunjungi
    visited_state_flags[current_board_id] = true;

    // Temukan posisi kosong saat ini
    int r = current_node->blank_pos / N;
    int c = current_node->blank_pos % N;

    // Jelajahi kemungkinan langkah (Atas, Bawah, Kiri, Kanan)
    for (int i = 0; i < 4; i++) {
        int new_r = r + dr[i];
        int new_c = c + dc[i];

        // Periksa apakah posisi baru valid (dalam batas papan)
        if (new_r >= 0 && new_r < N && new_c >= 0 && new_c < N) {
            int new_blank_pos = new_r * N + new_c;

            // Buat keadaan papan baru
            int new_board[N_SQUARED];
            memcpy(new_board, current_node->board, N_SQUARED * sizeof(int));

            // Tukar ubin kosong dengan ubin di (new_r, new_c)
            int temp_tile = new_board[current_node->blank_pos];
            new_board[current_node->blank_pos] = new_board[new_blank_pos];
            new_board[new_blank_pos] = temp_tile;

            // Dapatkan ID unik untuk papan baru
            int new_board_id = getUniqueBoardID(new_board);

            // Jika keadaan papan baru belum dikunjungi, lanjutkan pencarian DFS
            if (!visited_state_flags[new_board_id]) {
                Node* next_node = createNode(new_board, new_blank_pos, current_node->depth + 1, current_node, move_chars[i]);
                dfs(next_node, found_solution);
                if (*found_solution) {
                    return; // Hentikan jika solusi ditemukan di cabang rekursif
                }
            }
        }
    }
}

// Fungsi untuk membebaskan semua simpul yang dialokasikan
void freeAllNodes() {
    for (int i = 0; i < created_nodes_count; i++) {
        free(all_created_nodes[i]);
    }
    if (all_created_nodes != NULL) {
        free(all_created_nodes);
        all_created_nodes = NULL;
    }
}

int main() {
    // Inisialisasi faktorial untuk getUniqueBoardID
    faktorial();

    // Inisialisasi flag visited_state_flags menjadi false (0)
    memset(visited_state_flags, 0, sizeof(visited_state_flags));

    // Keadaan puzzle awal (contoh)
    // Keadaan ini dapat dipecahkan (jumlah inversi genap)
    int initial_board[N_SQUARED] = {1, 2, 3, 0, 4, 6, 7, 5, 8};
    // Untuk menguji puzzle yang tidak dapat dipecahkan, Anda bisa mencoba:
    // int initial_board[N_SQUARED] = {1, 2, 3, 4, 5, 6, 8, 7, 0}; // Tidak dapat dipecahkan

    int blank_pos_initial = -1;
    for (int i = 0; i < N_SQUARED; i++) {
        if (initial_board[i] == 0) {
            blank_pos_initial = i;
            break;
        }
    }

    if (blank_pos_initial == -1) {
        printf("Papan awal tidak valid: Tidak ada ubin kosong (0).\n");
        return 1;
    }

    printf("Keadaan Awal:\n");
    printBoard(initial_board);

    printf("Keadaan Tujuan:\n");
    printBoard(goal_board);

    // Alokasikan list simpul awal
    all_created_nodes = (Node**)malloc(created_nodes_capacity * sizeof(Node*));
    if (all_created_nodes == NULL) {
        perror("Alokasi memori awal gagal untuk list simpul");
        return 1;
    }

    // Buat simpul awal
    Node* initial_node = createNode(initial_board, blank_pos_initial, 0, NULL, '\0');

    bool found_solution = false;

    printf("Memulai pencarian DFS dengan kedalaman maksimum %d...\n", MAX_DEPTH);
    dfs(initial_node, &found_solution);

    if (!found_solution) {
        printf("Tidak ada solusi yang ditemukan dalam kedalaman %d.\n", MAX_DEPTH);
    }

    freeAllNodes(); // Bebaskan semua memori yang dialokasikan

    return 0;
}
