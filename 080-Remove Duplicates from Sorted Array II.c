int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 2) return numsSize;
    int offset = 0, i;
    for (i = 2 ; i < numsSize ; i++) {
        if (nums[i] == nums[i-1-offset] && nums[i] == nums[i-2-offset]) {
            offset++;
        } else {
            nums[i-offset] = nums[i];
        }
    }
    return numsSize - offset;
}