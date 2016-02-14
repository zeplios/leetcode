struct NumArray {
    int * nums;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    struct NumArray* numArr = malloc(sizeof(struct NumArray));
    numArr->nums = malloc(numsSize * sizeof(int));
    if (numsSize <= 0) return numArr;
    numArr->nums[0] = nums[0];
    int i;
    for (i = 1 ; i < numsSize ; i++) {
        numArr->nums[i] = numArr->nums[i-1] + nums[i];
    }
    return numArr;
}

int sumRange(struct NumArray* numArray, int i, int j) {
    if (i <= 0) return numArray->nums[j];
    else return numArray->nums[j] - numArray->nums[i-1];
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    free(numArray->nums);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);
