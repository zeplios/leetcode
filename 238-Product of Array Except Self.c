/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int i, left = 1, right = 1;
    int * res = malloc(sizeof(int) * numsSize);
    for (i = 0 ; i < numsSize ; i++) {
        res[i] = left;
        left *= nums[i];
    }
    for (i = numsSize - 1 ; i >= 0 ; i--) {
        res[i] *= right;
        right *= nums[i];
    }
    (*returnSize) = numsSize;
    return res;
}