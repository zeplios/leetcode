/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int ** res = malloc(sizeof(int*) * n);
    int i, c = 1;
    for (i = 0 ; i < n ; i++) {
        res[i] = malloc(sizeof(int) * n);
    }
    if (n == 0) return res;
    int startM = 0, endM = n - 1, startN = 0, endN = n - 1;
    while ((startM <= endM) && (startN <= endN)) {
        for (i = startN ; i <= endN ; i++) {
            res[startM][i] = c++;
        }
        for (i = startM + 1 ; i <= endM ; i++) {
            res[i][endN] = c++;
        }
        // make sure endM is still available
        if (startM == endM) break;
        for (i = endN - 1 ; i >= startN ; i--) {
            res[endM][i] = c++;
        }
        if (startN == endN) break;
        for (i = endM - 1 ; i >= startM + 1 ; i--) {
            res[i][startN] = c++;
        }
        startN++;
        startM++;
        endN--;
        endM--;
    }
    return res;
}