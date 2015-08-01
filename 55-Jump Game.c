bool canJ(int* nums, bool* cannotj, int numsSize) {
    if (numsSize <= 1) return true;
    if (cannotj[numsSize]) return false;
    int i;
    for (i = numsSize - 2 ; i > -1 ; i--) {
        if (nums[i] + i >= numsSize - 1) {
            if (canJ(nums, cannotj, i+1)) {
                return true;
            }
        }
    }
    cannotj[numsSize] = true;
    return false;
}
bool canJump(int* nums, int numsSize) {
    bool cannotj[numsSize+1];
    memset(cannotj, 0, (numsSize+1)*sizeof(bool));
    return canJ(nums, cannotj, numsSize);
}