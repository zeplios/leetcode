char* getPermutation(int n, int k) {
    k--; // index start from 0
    char* res = malloc(n+1);
    
    int i, j, pos = 0;
    int nums[10];
    bool used[10];
    nums[0] = 1;
    for (i = 1 ; i <= 9 ; i++) {
        nums[i] = i * nums[i-1];
        used[i] = false;
    }
    
    for (i = n-1 ; i >= 0 ; i--) {
        int seq = k / nums[i] + 1;
        for (j = 1 ; j <= n ; j++) {
            if (!used[j] && --seq == 0) {
                break;
            }
        }
        used[j] = true;
        res[pos++] = j + '0';
        k = k % nums[i];
    }
    res[pos] = '\0';
    return res;
}