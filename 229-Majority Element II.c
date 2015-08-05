/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int* res = malloc(2);
    (* returnSize) = 0;
    
    int m1 = INT_MIN, m2 = INT_MAX, i, cm1 = 0, cm2 = 0;
    for (i = 0 ; i < numsSize ; i++) {
        if (nums[i] == m1) cm1++;
        else if (nums[i] == m2) cm2++;
        else if (cm1 == 0) {
            m1 = nums[i];
            cm1++;
        } else if (cm2 == 0) {
            m2 = nums[i];
            cm2++;
        } else {
            cm1--;
            cm2--;
        }
    }
    cm1 = 0, cm2 = 0;
    for (i = 0 ; i < numsSize ; i++) {
        if (nums[i] == m1) cm1++;
        else if (nums[i] == m2) cm2++;
    }
    if (cm1 > numsSize/3) res[(* returnSize)++] = m1;
    if (cm2 > numsSize/3) res[(* returnSize)++] = m2;
    return res;
}