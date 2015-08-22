/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int midsearch(int * nums, int start, int end, int target) {
    if (start > end) {
        return -1;
    }
    if (start == end && nums[start] != target) {
        return -1;
    }
    int mid = (start + end) / 2;
    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] > target) {
        return midsearch(nums, start, mid-1, target);
    } else {
        return midsearch(nums, mid+1, end, target);
    }
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    (*returnSize) = 2;
    int * ret = malloc(2 * sizeof(int));
    int pos = midsearch(nums, 0, numsSize - 1, target);
    ret[0] = pos, ret[1] = pos;
    if (pos == -1) {
        return ret;
    }
    int i;
    for (i = pos - 1 ; i >= 0 ; i--) {
        if (nums[i] == target) {
            ret[0] = i;
        }
    }
    for (i = pos + 1 ; i < numsSize ; i++) {
        if (nums[i] == target) {
            ret[1] = i;
        }
    }
    return ret;
}