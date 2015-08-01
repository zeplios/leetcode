/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) {
    int **res = malloc((numRows > 0 ? numRows : 1)*sizeof(int*));
    (*columnSizes) = malloc((numRows > 0 ? numRows : 1)*sizeof(int));
    (*returnSize) = numRows;
    int i, j;
    if (numRows == 0) return res;
    (*columnSizes)[0] = 1;
    res[0] = malloc((1)*sizeof(int));
    res[0][0] = 1;
    for (i = 1 ; i < numRows ; i++) {
        (*columnSizes)[i] = i + 1;
        res[i] = malloc((i + 1)*sizeof(int));
        res[i][0] = 1;
        for (j = 0 ; j < (*columnSizes)[i-1] - 1 ; j++) {
            res[i][j+1] = res[i-1][j] + res[i-1][j+1];
        }
        res[i][j+1] = 1;
    }
    return res;
}