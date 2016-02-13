// reference : https://leetcode.com/discuss/75756/share-my-greedy-solution
// for [6,7] and [6,0,7], we should choose the 6 in [6,7] first, so [6,7] > [6,0,7]
bool gt(int* nums1, int size1, int* nums2, int size2) {
    int i;
    for (i = 0 ; i < size1 && i < size2 && nums1[i] == nums2[i] ; i++);
    return (i < size1) && (i == size2 || nums1[i] > nums2[i]);
}
int* merge(int* nums1, int size1, int* nums2, int size2) {
    int ressize = size1 + size2;
    int* res = malloc(ressize * sizeof(int));
    int i = 0, j = 0, idx = 0;
    while (idx < ressize)
        res[idx++] = gt(&nums1[i], size1-i, &nums2[j], size2-j) ? nums1[i++] : nums2[j++];
    return res;
}
int* extract(int* nums, int size, int k) {
    int* res = malloc(k * sizeof(int));
    int i, idx = 0;
    for (i = 0 ; i < size; i++) {
        while (size - i > k - idx && idx > 0 && res[idx - 1] < nums[i]) idx--;
        if (idx < k) res[idx++] = nums[i];
    }
    return res;
}
int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    int* res = malloc(k * sizeof(int));
    memset(res, 0, k * sizeof(int));
    int i = (k - nums2Size > 0) ? k - nums2Size : 0;
    for ( ; i <= k && i <= nums1Size; i++) {
        int* subarr1 = extract(nums1, nums1Size, i);
        int* subarr2 = extract(nums2, nums2Size, k-i);
        int* candidate = merge(subarr1, i, subarr2, k-i);
        if (gt(candidate, k, res, k)) res = candidate;
    }
    (* returnSize) = k;
    return res;
}
