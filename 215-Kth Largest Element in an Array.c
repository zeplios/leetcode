int heapSort(int* nums, int numsSize, int top) {
    int i = top;
    while (i < numsSize / 2) {
        if (2*i+2 < numsSize && nums[2*i+1] < nums[2*i+2]) {
            if (nums[i] < nums[2*i+2]) {
                int t = nums[i];
                nums[i] = nums[2*i+2];
                nums[2*i+2] = t;
                i = 2 * i + 2;
            } else {
                break;
            }
        } else {
            if (nums[i] < nums[2*i+1]) {
                int t = nums[i];
                nums[i] = nums[2*i+1];
                nums[2*i+1] = t;
                i = 2 * i + 1;
            } else {
                break;
            }
        }
    }
    return nums[0];
}
void createHeap(int* nums, int numsSize) {
    int i;
    for (i = numsSize / 2 - 1 ; i >= 0 ; i--) {
        heapSort(nums, numsSize, i);
    }
}
int findKthLargest(int* nums, int numsSize, int k) {
    createHeap(nums, numsSize);
    int i, value;
    for (i = 0 ; i < k ; i++) {
        value = heapSort(nums, numsSize - i, 0);
        nums[0] = nums[numsSize - i - 1];
    }
    return value;
}