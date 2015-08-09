/*
基本思路：
1. 在最大值前面的那些数没有成为最大值的机会，后续不用再考虑
2. 不用对k个数排序，求最大值只要从上次最大值的后一个遍历一遍就可以
3. 平均状况还好，最坏情况就是碰上递减序列，复杂度为O(k*n)
*/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int* res = malloc(sizeof(int) * numsSize);
    (* returnSize) = 0;
    if (k == 0) return res;
    int maxindex = -1, i, j, max;
    for (i = k-1 ; i < numsSize ; i++) {
        if (maxindex != -1 && nums[i] >= nums[maxindex]) {
            max = nums[i];
            maxindex = i;
        }
        if (maxindex < i-k+1) {
            max = INT_MIN;
            for (j = maxindex + 1 ; j <= i ; j++) {
                if (nums[j] >= max) {
                    max = nums[j];
                    maxindex = j;
                }
            }
        }
        
        res[(* returnSize)++] = max;
    }
    return res;
}