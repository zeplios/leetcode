int numTrees(int n) {
    if (n <= 1) {
        return 1;
    }
    int num[n+1];
    num[0] = num[1] = 1;
    int i, j;
    for (i = 2 ; i <= n ; i++) {
        int sum = 0;
        for (j = 1 ; j <= i ; j++) {
            sum += num[j-1] * num[i-j];
        }
        num[i] = sum;
    }
    return num[n];
}