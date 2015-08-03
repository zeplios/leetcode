char* longestPalindrome(char* s) {
    char* c = s, *start;
    int length = 0, i, newl;
    while (*c != '\0') {
        for (i = 0 ; i <= c-s ; i++) {
            if (*(c+i) == '\0' || *(c+i) != *(c-i)) break;
        }
        i--;
        newl = i * 2 + 1;
        if (newl > length) {
            length = newl;
            start = c - i;
        }
        for (i = 0 ; i <= c-s ; i++) {
            if (*(c+i+1) == '\0' || *(c+i+1) != *(c-i)) break;
        }
        i--;
        newl = i * 2 + 2;
        if (newl > length) {
            length = newl;
            start = c - i;
        }
        c++;
    }
    char* res = malloc(length+1);
    memcpy(res, start, length);
    res[length] = '\0';
    return res;
}