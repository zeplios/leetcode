int titleToNumber(char *s) {
    int base = 1, i;
    int total = 0;
    for (i = strlen(s) - 1 ; i >= 0 ; i--) {
        total += (s[i] - 64) * base;
        base *= 26;
    }
    return total;
}