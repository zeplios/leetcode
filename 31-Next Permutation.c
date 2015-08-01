/*===========快速排序的实现==============*/
void quicksort(int * nums, int start, int end) {
    if (start >= end) return;
    int i = start-1, x = nums[end], j, tmp;
    for (j = start ; j < end ; j++) {
        if (nums[j] <= x) {
            i++;
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
    tmp = nums[i+1];
    nums[i+1] = nums[j];
    nums[j] = tmp;
    quicksort(nums, start, i);
    quicksort(nums, i+2, end);
}
void nextPermutation(int* nums, int numsSize) {
    if (numsSize < 2) return;
    int cur = numsSize-2;
    while (cur >= 0) {
        if (nums[cur] < nums[cur+1]) {
            int swap = cur+1, i = swap;
            for (; i < numsSize ; i++) {
                if (nums[i] < nums[swap] && nums[i] > nums[cur]) {
                    swap = i;
                }
            }
            int tmp = nums[cur];
            nums[cur] = nums[swap];
            nums[swap] = tmp;
            break;
        }
        cur--;
    }
    quicksort(nums, cur+1, numsSize-1);
}