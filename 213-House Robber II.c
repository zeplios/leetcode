int max(int a, int b) {
    return (a > b) ? a : b;
}
int rob(int* nums, int numsSize) {
    int n = numsSize, i;
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);
    
    int sum1[n+1], sum2[n+1];
    
    sum1[0] = 0;
    sum1[1] = nums[0];
    sum1[2] = max(nums[0], nums[1]);
    for (i = 3 ; i < n ; i++) {
        sum1[i] = max(nums[i-1]+sum1[i-2], sum1[i-1]);
    }
    sum1[n] = sum1[n-1];
    
    sum2[0] = 0;
    sum2[1] = 0;
    sum2[2] = nums[1];
    for (i = 3 ; i <= n ; i++) {
        sum2[i] = max(nums[i-1]+sum2[i-2], sum2[i-1]);
    }
    return max(sum1[n], sum2[n]);
}