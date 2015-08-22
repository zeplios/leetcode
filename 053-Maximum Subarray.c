int maxSubArray(int* nums, int numsSize) {
    int lastmax = nums[0], newmax = 0, i;
    for (i = 0 ; i < numsSize ; i++) {
        newmax += nums[i];
        lastmax = newmax > lastmax ? newmax : lastmax;
        newmax = newmax > 0 ? newmax : 0;
    }
    return lastmax;
}