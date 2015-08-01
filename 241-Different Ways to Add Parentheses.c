/* calculate里面为res开多大对结果有影响，设成1000会OOM，设成<=400会WrongAns */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* calculate(char* input, int start, int end, int *retSize) {
    int * res = malloc(500*sizeof(int));
    (*retSize) = 0;
    
    int i, j, k;
    for (i = start ; i <= end ; i++) {
        char c = input[i];
        if (c == '+' || c == '-' || c == '*') {
            int lsize, rsize;
            int * lres = calculate(input, start, i-1, &lsize);
            int * rres = calculate(input, i+1, end, &rsize);
            for (j = 0 ; j < lsize ; j++) {
                for (k = 0 ; k < rsize ; k++) {
                    if (c == '+') {
                        res[(*retSize)++] = lres[j] + rres[k];
                    } else if (c == '-') {
                        res[(*retSize)++] = lres[j] - rres[k];
                    } else {
                        res[(*retSize)++] = lres[j] * rres[k];
                    }
                }
            }
        }
    }
    if ((*retSize) == 0) {
        int num = 0;
        for (i = start ; i <= end ; i++) {
            num = num * 10 + input[i] - '0';
        }
        res[(*retSize)++] = num;
    }
    return res;
}
void sort(int* nums, int start, int end) {
    if (start >= end) return;
    int i = start-1, j;
    for (j = start ; j < end ; j++) {
        if (nums[j] <= nums[end]) {
            i++;
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
    i++;
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
    sort(nums, start, i-1);
    sort(nums, i+1, end);
}
int* diffWaysToCompute(char* input, int* returnSize) {
    int length = strlen(input);
    int * res = calculate(input, 0, length-1, returnSize);
    sort(res, 0, (*returnSize)-1);
    return res;
}