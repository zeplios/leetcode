int mySqrtHelper(int x, int s, int e) {
    if (s > e) return -1;
    int m = (s + e) / 2;
    unsigned int t = m * m;
    if (t > x) { 
        t = (m-1) * (m-1);
        if (t <= x) {
            return m-1;
        } else {
            return mySqrtHelper(x, s, m-1);
        }
    } else if (t == x) {
        return m;
    } else {
        t = (m+1) * (m+1);
        if (t == x) {
            return m+1;
        } else if (t > x) {
            return m;
        } else {
            return mySqrtHelper(x, m+1, e);
        }
    }
}
int mySqrt(int x) {
    return mySqrtHelper(x, 0, x > 65535 ? 65535 : x); // m > x^16, m*m will overflow
}