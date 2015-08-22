/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool hasBefore(int* nums, bool *instack, int targetIndex) {
    int i;
    for (i = 0 ; i < targetIndex ; i++) {
        if (!instack[i] && (nums[i] == nums[targetIndex])) {
            return true;
        }
    }
    return false;
}
int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    int ** res = malloc(10000 * sizeof(int*));
    (* returnSize) = 0;
    int stack[numsSize];
    bool instack[numsSize];
    memset(instack, 0, numsSize * sizeof(bool));
    int top = 0, prePop = 0, i, k;
    
    for (k = 0 ; k < numsSize ; k++) {
        if (hasBefore(nums, instack, k)) {
            continue;
        }
    	stack[top++] = k;
    	instack[k] = 1;
        bool nextSubTree = true;
        while (top > 0) {
            if (nextSubTree) {
                nextSubTree = false;
                for (i = 0 ; i < numsSize ; i++) {
                    if (!instack[i]) {
                        stack[top++] = i;
                        instack[i] = true;
                    }
                }
                res[(* returnSize)] = malloc(sizeof(int) * numsSize);
                for (i = 0 ; i < top ; i++) {
                    res[(* returnSize)][i] = nums[stack[i]];
                }
                (* returnSize)++;
            }
            
            
            if (top < numsSize) {
                for (i = prePop + 1 ; i < numsSize ; i++) {
                    if (!instack[i]) {
                        if (hasBefore(nums, instack, i)) {
                            continue;
                        }
                        stack[top++] = i;
                        instack[i] = true;
                        nextSubTree = true;
                        break;
                    }
                }
                if (nextSubTree) {
                    continue;
                }
            }
            prePop = stack[--top];
            instack[prePop] = false;
        }
    }
    return res;
}