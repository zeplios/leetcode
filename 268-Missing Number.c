int missingNumber(int* nums, int numsSize) {
    int i = 0, t;
    for (i = 0 ; i < numsSize ; i++) {
        if (nums[i] != i && nums[i] < numsSize) {
            int index = nums[i];
            if (nums[i] == nums[index]) continue;
            t = nums[i];
            nums[i] = nums[index];
            nums[index] = t;
            i--;
        }
    }
    for (i = 0 ; i < numsSize ; i++) {
        if (nums[i] != i) {
            break;
        }
    }
    return i;
}