/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
void sort(int* nums, int start, int end) {
    if (start >= end) return;
    int i = start-1, j, tmp;
    for (j = start ; j < end ; j++) {
        if (nums[j] <= nums[end]) {
            i++;
            swap(nums, i, j);
        }
    }
    i++;
    swap(nums, i, j);
    sort(nums, start, i-1);
    sort(nums, i+1, end);
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int ** res = malloc(sizeof(int*)*1000);
    (* returnSize) = 0;
    int i, j, k;
    sort(nums, 0, numsSize-1);
    for (i = 0 ; i < numsSize - 2 ; i++) {
        j = i + 1, k = numsSize - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                res[(* returnSize)] = malloc(sizeof(int)*3);
                res[(* returnSize)][0] = nums[i];
                res[(* returnSize)][1] = nums[j];
                res[(* returnSize)][2] = nums[k];
                (* returnSize)++;
            }
            if (sum == 0) {
                while (j < k && nums[j] == nums[j+1]) {
                    j++;
                }
                while (j < k && nums[k] == nums[k-1]) {
                    k--;
                }
            }
            sum >= 0 ? k-- : j++;
        }
        while (i < numsSize - 2 && nums[i] == nums[i+1]) {
            i++;
        }
    }
    return res;
}