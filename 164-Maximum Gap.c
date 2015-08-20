int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;
    int min = INT_MAX, max = INT_MIN, i;
    for (i = 0 ; i < numsSize ; i++) {
        min = nums[i] < min ? nums[i] : min;
        max = nums[i] > max ? nums[i] : max;
    }
    double bucketSize = (max - min) * 1.0 / (numsSize + 1);
    int bucketMin[numsSize+1], bucketMax[numsSize+1];
    bool empty[numsSize+1];
    for (i = 0 ; i < numsSize + 1 ; i++) {
        empty[i] = true;
    }
    for (i = 0 ; i < numsSize ; i++) {
        int index = (int)((nums[i] - min) / bucketSize);
        if (index == numsSize + 1) index--;
        if (empty[index]) {
            empty[index] = false;
            bucketMin[index] = nums[i];
            bucketMax[index] = nums[i];
        } else {
            bucketMin[index] = nums[i] < bucketMin[index] ? nums[i] : bucketMin[index];
            bucketMax[index] = nums[i] > bucketMax[index] ? nums[i] : bucketMax[index];
        }
    }
    
    int maxgap = 0, lastMax = bucketMax[0];
    for (i = 1 ; i < numsSize + 1 ; i++) {
        if (empty[i]) continue;
        int gap = bucketMin[i] - lastMax;
        maxgap = gap > maxgap ? gap : maxgap;
        lastMax = bucketMax[i];
    }
    return maxgap;
}