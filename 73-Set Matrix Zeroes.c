void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    bool rows[matrixRowSize], cols[matrixColSize];
    memset(rows, 0, sizeof(bool) * matrixRowSize);
    memset(cols, 0, sizeof(bool) * matrixColSize);
    int i, j, k;
    for (i = 0 ; i < matrixRowSize ; i++) {
        for (j = 0 ; j < matrixColSize ; j++) {
            if (matrix[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }
    for (i = 0 ; i < matrixRowSize ; i++) {
        for (j = 0 ; j < matrixColSize ; j++) {
            matrix[i][j] *= !(rows[i] || cols[j]);
        }
    }
}