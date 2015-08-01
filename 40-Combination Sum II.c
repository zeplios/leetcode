/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void recurFind(int* candidates, int start, int candidatesSize, int target, int **res, 
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
    int i, pre = 0;
    for (i = start ; i < candidatesSize ; i++) {
        if (pre == candidates[i]) {
            continue;
        } else {
            pre = candidates[i];
        }
        stack[top++] = candidates[i];
        recurFind(candidates, i + 1, candidatesSize, target, res, columnSizes, returnSize, stack, top, cursum + candidates[i]);
        top--;
    }
}
void quicksort(int * nums, int start, int end) {
    if (start >= end) return;
    int i = start-1, x = nums[end], j, tmp;
    for (j = start ; j < end ; j++) {
        if (nums[j] <= x) {
            i++;
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
    tmp = nums[i+1];
    nums[i+1] = nums[j];
    nums[j] = tmp;
    quicksort(nums, start, i);
    quicksort(nums, i+2, end);
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    quicksort(candidates, 0, candidatesSize-1);
    int stack[1000];
    int ** res = malloc(1000 * sizeof(int *));
    (* columnSizes) = malloc(1000 * sizeof(int));
    (* returnSize) = 0;
    int cursum = 0, top = 0;
    recurFind(candidates, 0, candidatesSize, target, res, columnSizes, returnSize, stack, top, cursum);
    return res;
}