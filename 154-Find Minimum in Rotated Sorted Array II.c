int findMin(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    int i;
    for (i = numsSize - 1 ; i > 0 ; i--) {
        if (nums[i-1] > nums[i]) {
            break;
        }
    }
    return nums[i];
}