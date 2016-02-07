int minPatches(int* nums, int numsSize, int n) {
    int i, max = 0, patchnum = 0, edge = (INT_MAX-1)/2;
    for (i = 0 ; i < numsSize && max < n ; i++) {
        while (max < nums[i] - 1) {
            patchnum++;
            if (max >= edge) return patchnum;
            max = 2 * max + 1;
            // for nums[i] is larger than n
            if (max >= n) return patchnum;
        }
        if (max >= INT_MAX - nums[i]) return patchnum;
        max += nums[i];
    }
    while (max < n) {
        patchnum++;
        if (max >= edge) return patchnum;
        max = 2 * max + 1;
    }
    return patchnum;
}
