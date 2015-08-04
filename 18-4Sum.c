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
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    sort(nums, 0, numsSize-1);
    int ** res = malloc(sizeof(int*)*1000);
    (* returnSize) = 0;
    int a, i, j, k;
    sort(nums, 0, numsSize-1);
    for (a = 0 ; a < numsSize - 3 ; a++) {
        for (i = a+1 ; i < numsSize - 2 ; i++) {
            j = i + 1, k = numsSize - 1;
            while (j < k) {
                int sum = nums[a] + nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    res[(* returnSize)] = malloc(sizeof(int)*4);
                    res[(* returnSize)][0] = nums[a];
                    res[(* returnSize)][1] = nums[i];
                    res[(* returnSize)][2] = nums[j];
                    res[(* returnSize)][3] = nums[k];
                    (* returnSize)++;
                }
                if (sum == target) {
                    while (j < k && nums[j] == nums[j+1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k-1]) {
                        k--;
                    }
                }
                sum > target ? k-- : j++;
            }
            while (i < numsSize - 2 && nums[i] == nums[i+1]) {
                i++;
            }
        }
        while (a < numsSize - 3 && nums[a] == nums[a+1]) {
            a++;
        }
    }
    return res;
}