struct NumMatrix {
    int ** nums;
    int rows;
    int cols;
};

/** Initialize your data structure here. */
struct NumMatrix* NumMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {
    struct NumMatrix* numMat = malloc(sizeof(struct NumMatrix));
    numMat->rows = matrixRowSize;
    numMat->cols = matrixColSize;
    numMat->nums = malloc(matrixRowSize * sizeof(int*));
    int i, j;
    for (i = 0 ; i < matrixRowSize ; i++) {
        numMat->nums[i] = malloc(matrixColSize * sizeof(int));
    }
    if (matrixRowSize <= 0 || matrixColSize <= 0) return numMat;
    numMat->nums[0][0] = matrix[0][0];
    for (i = 1 ; i < matrixRowSize ; i++) {
        numMat->nums[i][0] = numMat->nums[i-1][0] + matrix[i][0];
    }
    for (j = 1 ; j < matrixColSize ; j++) {
        numMat->nums[0][j] = numMat->nums[0][j-1] + matrix[0][j];
    }
    for (i = 1 ; i < matrixRowSize ; i++) {
        for (j = 1 ; j < matrixColSize ; j++) {
            numMat->nums[i][j] = numMat->nums[i-1][j] + numMat->nums[i][j-1] + matrix[i][j] - numMat->nums[i-1][j-1];
        }
    }
    return numMat;
}

int sumRegion(struct NumMatrix* numMatrix, int row1, int col1, int row2, int col2) {
    int left = 0, top = 0, lefttop = 0;
    if (row1 > 0) {
        top = numMatrix->nums[row1-1][col2];
    }
    if (col1 > 0) {
        left = numMatrix->nums[row2][col1-1];
    }
    if (row1 > 0 && col1 > 0) {
        lefttop = numMatrix->nums[row1-1][col1-1];
    }
    return numMatrix->nums[row2][col2] - top - left + lefttop;
}

/** Deallocates memory previously allocated for the data structure. */
void NumMatrixFree(struct NumMatrix* numMatrix) {
    int i;
    for (i = 0 ; i < numMatrix->rows ; i++) {
        free(numMatrix->nums[i]);
    }
    free(numMatrix->nums);
}

// Your NumMatrix object will be instantiated and called as such:
// struct NumMatrix* numMatrix = NumMatrixCreate(matrix, matrixRowSize, matrixColSize);
// sumRegion(numMatrix, 0, 1, 2, 3);
// sumRegion(numMatrix, 1, 2, 3, 4);
// NumMatrixFree(numMatrix);
