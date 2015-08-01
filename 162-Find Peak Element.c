int findPeakElement(int* nums, int numsSize) {
    int i;
    if (numsSize == 0) return -1;
    if (numsSize == 1 || nums[0] > nums[1]) return 0;
    for (i = 1 ; i < numsSize - 1 ; i++) {
        if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
            return i;
        }
    }
    if (nums[i] > nums[i-1]) {
        return i;
    } else {
        return -1;
    }
}