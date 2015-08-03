int max(int a, int b) {
	return a > b ? a : b;
}
int maxProduct(int* nums, int numsSize) {
    int product[numsSize], i, maxp = INT_MIN, begin = 0; // first non-zero index
    int first = -1; // first neg num index after zero
    bool excludeFirst = false; // exclude the nums before first
    for (i = 0 ; i < numsSize ; i++) {
        if (nums[i] == 0) {
            begin = i + 1;
            product[i] = 0;
            first = -1;
            excludeFirst = false;
        } else if (nums[i] < 0 && first == -1) {
            product[i] = nums[i] * (i == begin ? 1 : product[i-1]);
            first = i;
        } else { // nums[i] > 0 || first != -1
            product[i] = nums[i] * (i == begin ? 1 : product[i-1]);
            if (product[i] < 0) {
                if (excludeFirst) {
                    product[i] *= product[first];
                    excludeFirst = false;
                } else {
                    product[i] /= product[first];
                    excludeFirst = true;
                }
            }
        }
        maxp = max(maxp, max(nums[i], product[i]));
    }
    return maxp;
}