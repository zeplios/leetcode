int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int offset = 0, i, pre = nums[0];
    for (i = 1 ; i < numsSize ; i++) {
        if (nums[i] == pre) {
            offset++;
        } else {
            pre = nums[i];
            nums[i-offset] = nums[i];
        }
    }
    return numsSize - offset;
}