int search(int* nums, int numsSize, int target) {
    int i = 0;
    while (i < numsSize && nums[i] <= target) {
        if (nums[i] == target) {
            return i;
        } else {
            i++;
        }
    }
    i = numsSize - 1;
    while (i >= 0 && nums[i] >= target) {
        if (nums[i] == target) {
            return i;
        } else {
            i--;
        }
    }
    return -1;
}