void swap(int* nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j]; nums[j] = tmp;
}
void quickSort(int* nums, int start, int end) {
    if (start >= end) return;
    int i, j = start-1;
    for (i = start ; i < end ; i++) {
        if (nums[i] < nums[end]) {
            j++;
            swap(nums, i, j);
        }
    }
    j++;
    swap(nums, j, end);
    quickSort(nums, start, j-1);
    quickSort(nums, j+1, end);
}
// how many coins will used to get amount with coins[0]~coins[coinsidx]
int dp(int* coins, int coinsidx, int amount, int limit) {
    if (coinsidx < 0) return -1;
    if (amount % coins[coinsidx] == 0) return amount / coins[coinsidx];
    int num = amount / coins[coinsidx], i, min = INT_MAX;
    for (i = num ; i >= 0 ; i--) {
        int remain = amount - i * coins[coinsidx];
        if (coinsidx > 0 && remain/coins[coinsidx-1] + i >= limit) {
            break;
        }
        int cnt = dp(coins, coinsidx-1, remain, limit-i);
        if (cnt > -1 && cnt + i < min) {
            min = cnt + i;
            limit = min;
        }
    }
    return min < INT_MAX ? min : -1;
}
int coinChange(int* coins, int coinsSize, int amount) {
    quickSort(coins, 0, coinsSize-1);
    return dp(coins, coinsSize-1, amount, INT_MAX/2);
}
