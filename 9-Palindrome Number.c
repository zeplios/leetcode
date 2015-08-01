bool isPalindrome(int x) {
    if (x < 0) return false;
    int c = 0, t = x;
    while (t > 0) {
        c = c * 10 + t % 10;
        t /= 10;
    }
    return x == c;
}