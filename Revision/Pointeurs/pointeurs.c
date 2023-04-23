#include <stdio.h>
#include <stdlib.h>

void create_matrix(int ***matrix, int m, int n) {
    int i, j;
    *matrix = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        (*matrix)[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            (*matrix)[i][j] = i * n + j;
        }
    }
}

int main() {
    int **matrix;
    int i, j;
    int m = 3, n = 4;
    create_matrix(&matrix, m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
