/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char ** res = malloc((numsSize+2)/2);
	(*returnSize) = 0;
	if (numsSize == 0) {
		return res;
	}
    int rangeStart = nums[0], i, maxLen = 30;
    for (i = 1 ; i <= numsSize ; i++) {
    	if (i == numsSize || nums[i] - nums[i-1] != 1) {
			res[(*returnSize)] = malloc(maxLen);
    		if (nums[i-1] == rangeStart) {
    			snprintf(res[(*returnSize)], maxLen, "%d", rangeStart);
			} else {
    			snprintf(res[(*returnSize)], maxLen, "%d->%d", rangeStart, nums[i-1]);
			}
			(*returnSize)++;
    		rangeStart = nums[i];
		}
	}
	return res;
}