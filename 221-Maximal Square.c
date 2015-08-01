int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    // side length
    int side[matrixRowSize][matrixColSize];
    int i, j, k, max = 0;;
    for (i = 0 ; i < matrixRowSize ; i++) {
        side[i][0] = matrix[i][0] - '0';
        if (side[i][0] > max) {
            max = side[i][0];
        }
    }
    for (i = 0 ; i < matrixColSize ; i++) {
        side[0][i] = matrix[0][i] - '0';
        if (side[0][i] > max) {
            max = side[0][i];
        }
    }
    for (i = 1 ; i < matrixRowSize ; i++) {
        for (j = 1 ; j < matrixColSize ; j++) {
            if (matrix[i][j] == '0') {
                side[i][j] = 0;
            } else {
                for (k = 1 ; k <= side[i-1][j-1] ; k++) {
                    if (matrix[i-k][j] == '0' || matrix[i][j-k] == '0') {
                        break;
                    }
                }
                side[i][j] = (k - 1) + 1;
                if (side[i][j] > max) {
                    max = side[i][j];
                }
            }
        }
    }
    return max * max;
}