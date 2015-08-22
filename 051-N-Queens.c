/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* !!! I think the code is right, but leetcode throws a compile error even I just declear(malloc) the result and return it */
//int size_1 = 0;
void solve(char***res, int* returnSize, int* stack, int top, int n) {
    int i, j;
    if (top == n) {
        res[(* returnSize)] = malloc(n*sizeof(char*));
        for (i = 0 ; i < n ; i++) {
            res[(* returnSize)][i] = malloc(n);
            for (j = 0 ; j < n ; j++) res[(* returnSize)][i][j] = '.';
            res[(* returnSize)][i][stack[i]] = 'Q';
        }
        (* returnSize)++;
        return;
    }
    for (i = 0 ; i < n ; i++) {
        for (j = 0 ; j < top ; j++) {
            if (i == stack[j] || abs(i-stack[j]) == abs(top-j)) {
                break;
            }
        }
        if (j == top) {
            stack[top++] = i;
            solve(res, returnSize, stack, top, n);
            top--;
        }
    }
}
char*** solveNQueens(int n, int* returnSize) {
    (* returnSize) = 0;
    char *** res = malloc(10000*sizeof(char**));
    if (n == 0) return res;
    
    int stack[n], top = 0;
    
    solve(res, returnSize, stack, top, n);
    //size_1 = n;
    return res;
}