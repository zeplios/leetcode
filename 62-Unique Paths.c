int uniquePaths(int m, int n) {
    /*int a = m - 1, b = n - 1;
    int little = a > b ? b : a;
    int big = a > b ? a : b;
    int res = 1, i;
    for (i = a+b ; i > big ; i--) {
        res *= i;
    }
    for (i = little ; i > 0 ; i--) {
        res /= i;
    }*/
    int total = m * n;
    int res[total], i;
    for (i = 0 ; i < total ; i++) {
        if (i < n || i % n == 0) {
            res[i] = 1;
        } else {
            res[i] = res[i-1] + res[i-n];
        }
    }
    return res[total-1];
}