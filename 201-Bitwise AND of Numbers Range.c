int rangeBitwiseAnd(int m, int n) {
    if (m == INT_MAX && n == INT_MAX) return m;
    int count = 0;
    while (m & 1 == 0 || m + 1 <= n) {
        count++;
        m = m >> 1;
        n = n >> 1;
        if (m == 0) {
            break;
        }
    }
    return m << count;
}