int removeElement(int* nums, int numsSize, int val) {
    int i;
    for (i = 0 ; i < numsSize ; i++) {
        if (nums[i] == val) {
            nums[i] = nums[numsSize-1];
            i--;
            numsSize--;
        }
    }
    return numsSize;
}