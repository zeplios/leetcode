void sortColors(int* nums, int numsSize) {
    int twoStart = 0, twoEnd = numsSize - 1, i;
    while (nums[twoStart] == 0 && twoStart < numsSize) twoStart++;
    while (nums[twoEnd] == 2 && twoEnd >= 0) twoEnd--;
    for (i = twoStart ; i <= twoEnd ; i++) {
        if (nums[i] == 0 || nums[i] == 2) {
            if (nums[i] == 0) {
                nums[i] = nums[twoStart];
                nums[twoStart++] = 0;
            } else {
                nums[i] = nums[twoEnd];
                nums[twoEnd--] = 2;
            }
            
            while (nums[twoStart] == 0 && twoStart < numsSize) twoStart++;
            while (nums[twoEnd] == 2 && twoEnd >= 0) twoEnd--;
            if (i < twoStart) {
                i = twoStart;
            } else {
                i--;
            }
        }
    }
}