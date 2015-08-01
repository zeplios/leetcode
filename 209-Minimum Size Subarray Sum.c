int minSubArrayLen(int s, int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int startIndex = 0, curSum = 0, i, minLength = numsSize;
    bool find = false;
    for (i = 0 ; i < numsSize ; i++) {
        curSum += nums[i];
        while (curSum >= s) {
            find = true;
            minLength = i - startIndex + 1 < minLength ? i - startIndex + 1 : minLength;
            curSum -= nums[startIndex++];
        }
    }
    return find ? minLength : 0;
}