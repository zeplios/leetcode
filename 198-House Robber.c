int max(int a, int b) {
    return (a > b) ? a : b;
}
int rob(int num[], int n) {
    if (n == 0) return 0;
    if (n == 1) return num[0];
    if (n == 2) return max(num[0], num[1]);
    
    int sum[n+1];
    int i;
    sum[0] = 0;
    sum[1] = num[0];
    sum[2] = max(num[0], num[1]);
    for (i = 3 ; i <= n ; i++) {
        sum[i] = max(num[i-1]+sum[i-2], sum[i-1]);
    }
    return sum[n];
}