/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    (* returnSize) = 1;
    int i, j;
    for (i = 0 ; i < n ; i++) {
        (* returnSize) *= 2;
    }
    int * res = malloc((* returnSize) * sizeof(int));
    memset(res, 0, (* returnSize) * sizeof(int));
    if (n == 0) {
        res[0] = 0;
        return res;
    }
    res[0] = 0;
    res[1] = 1;
    int cursor = 2;
    for (i = 1 ; i < n ; i++) {
        for (j = cursor - 1 ; j >=0 ; j--) {
            res[cursor++] = 1 << i | res[j];
        }
    }
    return res;
}