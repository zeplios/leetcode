void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    // n * n means matrixRowSize == matrixColSize
    int rs = (matrixRowSize + 1) / 2, cs = matrixColSize / 2, i, j, temp;
    for (i = 0 ; i < rs ; i++) {
        for (j = 0 ; j < cs ; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[matrixRowSize-1-j][i];
            matrix[matrixRowSize-1-j][i] = matrix[matrixRowSize-1-i][matrixColSize-1-j];
            matrix[matrixRowSize-1-i][matrixColSize-1-j] = matrix[j][matrixColSize-1-i];
            matrix[j][matrixColSize-1-i] = temp;
        }
    }
}