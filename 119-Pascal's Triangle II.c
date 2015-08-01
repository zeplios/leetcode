/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int *res = malloc((rowIndex+2)*sizeof(int));
    (*returnSize) = rowIndex + 1;
    int i, j, pre;
    res[0] = 1;
    for (i = 1 ; i <= rowIndex ; i++) {
        pre = res[0];
        for (j = 1 ; j < i ; j++) {
            int t = res[j];
            res[j] = res[j] + pre;
            pre = t;
        }
        res[j] = 1;
    }
    return res;
}