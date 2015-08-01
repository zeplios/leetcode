/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int *res = malloc((matrixRowSize*matrixColSize) * sizeof(int));
    int c = 0;
    int startM = 0, endM = matrixRowSize - 1, startN = 0, endN = matrixColSize - 1;
    int i, j;
    if (matrixRowSize <= 0 || matrixColSize <= 0) {
        return res;
    }
    while ((startM <= endM) && (startN <= endN)) {
        for (i = startN ; i <= endN ; i++) {
            res[c++] = matrix[startM][i];
        }
        for (i = startM + 1 ; i <= endM ; i++) {
            res[c++] = matrix[i][endN];
        }
        // make sure endM is still available
        if (startM == endM) break;
        for (i = endN - 1 ; i >= startN ; i--) {
            res[c++] = matrix[endM][i];
        }
        if (startN == endN) break;
        for (i = endM - 1 ; i >= startM + 1 ; i--) {
            res[c++] = matrix[i][startN];
        }
        startN++;
        startM++;
        endN--;
        endM--;
    }
    return res;
}