/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void recurFind(int k, int start, int target, int **res, 
                int** columnSizes, int* returnSize, int stack[], int top, int cursum) {
    if (cursum > target || top > k) {
        return;
    }
    if (cursum == target) {
        if (top == k) {
            res[(*returnSize)] = malloc(top * sizeof(int));
            (* columnSizes)[(*returnSize)] = top;
            int i;
            for (i = 0 ; i < top ; i++) {
                res[(*returnSize)][i] = stack[i];
            }
            (*returnSize)++;
        }
        return;
    }
    int i, pre = 0;
    for (i = start ; i <= 9 ; i++) {
        if (pre == i) {
            continue;
        } else {
            pre = i;
        }
        stack[top++] = i;
        recurFind(k, i + 1, target, res, columnSizes, returnSize, stack, top, cursum + i);
        top--;
    }
}
int** combinationSum3(int k, int n, int** columnSizes, int* returnSize) {
    int stack[1000];
    int ** res = malloc(1000 * sizeof(int *));
    (* columnSizes) = malloc(1000 * sizeof(int));
    (* returnSize) = 0;
    int cursum = 0, top = 0;
    recurFind(k, 1, n, res, columnSizes, returnSize, stack, top, cursum);
    return res;
}