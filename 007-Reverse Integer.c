int reverse(int x) {
    int sign = x > 0 ? 1 : -1;
    x = x > 0 ? x : -x;
    if (x < 0) return 0;
    int y = 0, m;
    while (x != 0) {
        if (y > INT_MAX / 10) return 0;
        y = y * 10 + (x % 10);
        x /= 10;
    }
    return sign * y;
}