/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void recurFind(int* candidates, int candidatesSize, int target, int **res, 
                int** columnSizes, int* returnSize, int stack[], int top, int cursum) {
    if (cursum > target) {
        return;
    }
    if (cursum == target) {
        res[(*returnSize)] = malloc(top * sizeof(int));
        (* columnSizes)[(*returnSize)] = top;
        int i;
        for (i = 0 ; i < top ; i++) {
            res[(*returnSize)][i] = stack[i];
        }
        (*returnSize)++;
        return;
    }
    int i;
    for (i = 0 ; i < candidatesSize ; i++) {
        if (top > 0 && candidates[i] < stack[top-1]) continue;
        stack[top++] = candidates[i];
        recurFind(candidates, candidatesSize, target, res, columnSizes, returnSize, stack, top, cursum + candidates[i]);
        top--;
    }
}
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int stack[1000];
    int ** res = malloc(1000 * sizeof(int *));
    (* columnSizes) = malloc(1000 * sizeof(int));
    (* returnSize) = 0;
    int cursum = 0, top = 0;
    recurFind(candidates, candidatesSize, target, res, columnSizes, returnSize, stack, top, cursum);
    return res;
}