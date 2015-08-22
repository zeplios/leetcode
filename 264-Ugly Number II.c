#define MIN(a, b, c) a < b ? (a < c ? a : c) : (b < c ? b : c);
int nthUglyNumber(int n) {
    if (n == 0) return 0;
    int* res = calloc(n+1, sizeof(int));
    int i;
    res[0] = 1;
    int lastMulti2 = 0, lastMulti3 = 0, lastMulti5 = 0;
    for (i = 1 ; i < n ; i++) {
        int m2 = res[lastMulti2] * 2;
        int m3 = res[lastMulti3] * 3;
        int m5 = res[lastMulti5] * 5;
        res[i] = MIN(m2, m3, m5);
        while (res[lastMulti2] * 2 <= res[i]) lastMulti2++;
        while (res[lastMulti3] * 3 <= res[i]) lastMulti3++;
        while (res[lastMulti5] * 5 <= res[i]) lastMulti5++;
    }
    return res[n-1];
}