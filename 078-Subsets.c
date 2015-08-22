/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int* nums, int numsSize, int** columnSizes, int* returnSize, int * stack, int top, int **res) {
    if (numsSize == top) {
        int i, count = 0;
        (* columnSizes)[* returnSize] = 0;
        for (i = 0 ; i < top ; i++) {
            (* columnSizes)[(* returnSize)] += stack[i];
        }
        res[(* returnSize)] = malloc((* columnSizes)[(* returnSize)]*sizeof(int));
        for (i = 0 ; i < top ; i++) {
            if (stack[i] == 1) res[(* returnSize)][count++] = nums[i];
        }
        (* returnSize)++;
        return;
    }
    stack[top++] = 0;
    dfs(nums, numsSize, columnSizes, returnSize, stack, top, res);
    top--;
    stack[top++] = 1;
    dfs(nums, numsSize, columnSizes, returnSize, stack, top, res);
    top--;
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
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int **res = malloc(10000*sizeof(int *));
    (* columnSizes) = malloc(10000*sizeof(int));
    (* returnSize) = 0;
    int stack[numsSize], top = 0;
    quicksort(nums, 0, numsSize-1);
    dfs(nums, numsSize, columnSizes, returnSize, stack, top, res);
    return res;
}