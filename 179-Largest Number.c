char* itoa(int i) {
    char* res = malloc(20);
    int pos = 19;
    res[pos--] = '\0';
    if (i == 0) {
        res[pos--] = '0';
    }
    while (i != 0) {
        res[pos--] = i % 10 + '0';
        i /= 10;
    }
    return res+pos+1;
}
void swap(int* nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
bool greater(int* nums, int i, int j) {
    // 3 should be less than 34, but greater than 32, so regard 3 as 33 when
    // compare with 3x
    char* left = itoa(nums[i]);
    char* right = itoa(nums[j]);
    char* l = left, *r = right;
    int lsize = strlen(left), rsize = strlen(right);
    while (*l != '\0' && *r != '\0') {
        if (*l < *r) {
            return false;
        }
        if (*l > *r) {
            return true;
        }
        l++;
        r++;
        if (*l == '\0' && *r != '\0') l = left;
        if (*l != '\0' && *r == '\0') r = right;
    }
    return true;
}
void sort(int* nums, int start, int end) {
    if (start >= end) return;
    int i = start-1, j;
    for (j = start ; j < end ; j++) {
        if (greater(nums, j, end)) {
            i++;
            swap(nums, i, j);
        }
    }
    i++;
    swap(nums, i, j);
    sort(nums, start, i-1);
    sort(nums, i+1, end);
}
char* largestNumber(int* nums, int numsSize) {
    sort(nums, 0, numsSize - 1);
    char* res = malloc(1000);
    int pos = 0, i;
    for (i = 0 ; i < numsSize ; i++) {
        char* t = itoa(nums[i]);
        int len = strlen(t);
        memcpy(res+pos, t, len);
        pos += len;
    }
    res[pos] = '\0';
    while (*res == '0' && *(res+1) == '0') res++;
    return res;
}