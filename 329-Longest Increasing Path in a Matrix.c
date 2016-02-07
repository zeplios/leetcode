int dfs(int** matrix, int** lip, int rows, int cols, int m, int n) {
    if (lip[m][n] >= 0) {
        return lip[m][n];
    }
    int max = 0, tmp;
    if (m > 0 && matrix[m-1][n] > matrix[m][n]) {
        tmp = dfs(matrix, lip, rows, cols, m-1, n);
        max = tmp > max ? tmp : max;
    }
    if (n > 0 && matrix[m][n-1] > matrix[m][n]) {
        tmp = dfs(matrix, lip, rows, cols, m, n-1);
        max = tmp > max ? tmp : max;
    }
    if (m < rows-1 && matrix[m+1][n] > matrix[m][n]) {
        tmp = dfs(matrix, lip, rows, cols, m+1, n);
        max = tmp > max ? tmp : max;
    }
    if (n < cols-1 && matrix[m][n+1] > matrix[m][n]) {
        tmp = dfs(matrix, lip, rows, cols, m, n+1);
        max = tmp > max ? tmp : max;
    }
    lip[m][n] = max + 1;
    return max + 1;
}
int longestIncreasingPath(int** matrix, int matrixRowSize, int matrixColSize) {
    // lip stands for longest increasing path
    int** lip = malloc(matrixRowSize * sizeof(int*));
    int i, j, max = 0, tmp;
    for (i = 0 ; i < matrixRowSize ; i++) {
        lip[i] = malloc(matrixColSize * sizeof(int));
        for (j = 0 ; j < matrixColSize ; j++) {
            lip[i][j] = -1;
        }
    }
    for (i = 0 ; i < matrixRowSize ; i++) {
        for (j = 0 ; j < matrixColSize ; j++) {
            tmp = dfs(matrix, lip, matrixRowSize, matrixColSize, i, j);
            max = tmp > max ? tmp : max;
        }
    }
    return max;
}
