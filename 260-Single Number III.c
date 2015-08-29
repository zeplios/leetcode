/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int i, j;
    int xorres = 0;
    for (i = 0 ; i < numsSize ; i++) {
        xorres ^= nums[i];
    }
    j = 0;
    while (true) {
        if (((1 << j) & xorres) != 0) {
            break;
        }
        j++;
    }
    int * res = malloc(sizeof(int) * 2);
    (* returnSize) = 2;
    res[0] = 0, res[1] = 0;
    for (i = 0 ; i < numsSize ; i++) {
        if ((nums[i] & (1 << j)) == 0) {
            res[0] ^= nums[i];
        } else {
            res[1] ^= nums[i];
        }
    }
    return res;
}