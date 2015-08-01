void solveSub(int* returnSize, int* stack, int top, int n) {
    int i, j;
    if (top == n) {
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
            solveSub(returnSize, stack, top, n);
            top--;
        }
    }
}
int totalNQueens(int n) {
    int count = 0;
    if (n == 0) return 0;
    
    int stack[n], top = 0;
    solveSub(&count, stack, top, n);
    return count;
}