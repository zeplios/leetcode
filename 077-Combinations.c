/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int** columnSizes, int* returnSize) {
    int ** res = malloc(10000 * sizeof(int*));
    (* columnSizes) = malloc(10000 * sizeof(int));
    (* returnSize) = 0;
    int stack[n];
    int top = 0, prePop = 0, i, rootSize;
    
    for (rootSize = 0 ; rootSize <= n-k ; rootSize++) {
    	stack[top++] = rootSize;
        bool nextSubTree = true;
        while (top > 0) {
            if (nextSubTree) {
                nextSubTree = false;
                for (i = stack[top-1]+1 ; i < n && top < k && (n-i)+top >= k ; i++) {
                    stack[top++] = i;
                }
                if (top == k) {
                    res[(* returnSize)] = malloc(sizeof(int) * k);
                    (* columnSizes)[(* returnSize)] = k;
                    for (i = 0 ; i < top ; i++) {
                        res[(* returnSize)][i] = stack[i]+1;
                    }
                    (* returnSize)++;
                } else {
                    prePop = stack[--top];
                }
            }
            
            
            if (top < k) {
                i = prePop + 1;
                if (i < n) {
                    stack[top++] = i;
                    nextSubTree = true;
                    continue;
                }
            }
            prePop = stack[--top];
        }
    }
    return res;
}