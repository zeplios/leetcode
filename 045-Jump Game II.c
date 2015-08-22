int jump(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;
    int revindex[numsSize];
    int i, j, pos = 1;
    for (i = 0 ; i < numsSize ; i++) {
        for ( ; pos <= nums[i] + i && pos < numsSize; pos++) {
            revindex[pos] = i;
        }
    }
    pos = numsSize - 1;
    for (i = 0 ; i < numsSize ; i++) {
        pos = revindex[pos];
        if (pos <= 0) {
            break;
        }
    }
    return i + 1;
}