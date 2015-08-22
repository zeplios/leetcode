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
int threeSumClosest(int* nums, int numsSize, int target) {
    int i, j, k, min = INT_MAX, minsum;
    sort(nums, 0, numsSize-1);
    for (i = 0 ; i < numsSize - 2 ; i++) {
        j = i + 1, k = numsSize - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            int diff = abs(sum - target);
            if (diff < min) {
                minsum = sum;
                min = diff;
            }
            if (min == 0) {
                return minsum;
            }
            sum > target ? k-- : j++;
        }
    }
    return minsum;
}