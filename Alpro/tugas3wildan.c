#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 3
#define N_SQUARED (N * N)
#define MAX_DEPTH 40
#define MAX_STATES 362880

int goal_board[N_SQUARED] = {1, 2, 3, 4, 5, 6, 7, 8, 0};

typedef struct Node {
    int board[N_SQUARED];
    int blank_pos;
    int depth;
    struct Node* parent;
    char move_made;
} Node;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char move_chars[] = {'U', 'D', 'L', 'R'};

int factorial[N_SQUARED];

void faktorial() {
    factorial[0] = 1;
    for (int i = 1; i < N_SQUARED; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
}

bool visited_state_flags[MAX_STATES];

Node** all_created_nodes = NULL;
int created_nodes_count = 0;
int created_nodes_capacity = 1000;

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

void printBoard(int board[N_SQUARED]) {
    for (int i = 0; i < N_SQUARED; i++) {
        if (board[i] == 0) {
            printf("  ");
        } else {
            printf("%2d", board[i]);
        }
        if ((i + 1) % N == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

bool isGoalState(int board[N_SQUARED]) {
    for (int i = 0; i < N_SQUARED; i++) {
        if (board[i] != goal_board[i]) {
            return false;
        }
    }
    return true;
}

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

void dfs(Node* current_node, bool* found_solution) {
    if (*found_solution) {
        return;
    }

    if (current_node->depth > MAX_DEPTH) {
        return;
    }

    if (isGoalState(current_node->board)) {
        printf("Solusi ditemukan pada kedalaman: %d\n", current_node->depth);
        printf("Jalur solusi:\n");

        Node* path[MAX_DEPTH + 1];
        int path_idx = 0;
        Node* temp = current_node;
        while (temp != NULL) {
            path[path_idx++] = temp;
            temp = temp->parent;
        }

        for (int i = path_idx - 1; i >= 0; i--) {
            printf("Langkah %d: ", path_idx - 1 - i);
            if (path[i]->move_made != '\0') {
                printf("Pindah %c\n", path[i]->move_made);
            } else {
                printf("Keadaan Awal\n");
            }
            printBoard(path[i]->board);
        }
        *found_solution = true;
        return;
    }

    int current_board_id = getUniqueBoardID(current_node->board);

    visited_state_flags[current_board_id] = true;

    int r = current_node->blank_pos / N;
    int c = current_node->blank_pos % N;

    for (int i = 0; i < 4; i++) {
        int new_r = r + dr[i];
        int new_c = c + dc[i];

        if (new_r >= 0 && new_r < N && new_c >= 0 && new_c < N) {
            int new_blank_pos = new_r * N + new_c;

            int new_board[N_SQUARED];
            memcpy(new_board, current_node->board, N_SQUARED * sizeof(int));

            int temp_tile = new_board[current_node->blank_pos];
            new_board[current_node->blank_pos] = new_board[new_blank_pos];
            new_board[new_blank_pos] = temp_tile;

            int new_board_id = getUniqueBoardID(new_board);

            if (!visited_state_flags[new_board_id]) {
                Node* next_node = createNode(new_board, new_blank_pos, current_node->depth + 1, current_node, move_chars[i]);
                dfs(next_node, found_solution);
                if (*found_solution) {
                    return;
                }
            }
        }
    }
}

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
    faktorial();

    memset(visited_state_flags, 0, sizeof(visited_state_flags));

    int initial_board[N_SQUARED] = {1, 2, 3, 0, 4, 6, 7, 5, 8};

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

    all_created_nodes = (Node**)malloc(created_nodes_capacity * sizeof(Node*));
    if (all_created_nodes == NULL) {
        perror("Alokasi memori awal gagal untuk list simpul");
        return 1;
    }

    Node* initial_node = createNode(initial_board, blank_pos_initial, 0, NULL, '\0');

    bool found_solution = false;

    printf("Memulai pencarian DFS dengan kedalaman maksimum %d...\n", MAX_DEPTH);
    dfs(initial_node, &found_solution);

    if (!found_solution) {
        printf("Tidak ada solusi yang ditemukan dalam kedalaman %d.\n", MAX_DEPTH);
    }

    freeAllNodes();

    return 0;
}
