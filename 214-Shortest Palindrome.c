char* shortestPalindrome(char* s) {
    char* end = s + strlen(s) - 1;
    char* c = (char*)(((int)s + (int)end) / 2 + 1);
    char* res;
    int i, j;
    while (true) {
        for (i = 0 ; i <= end - c ; i++) {
            if (c - i >= s && *(c+i) != *(c-i)) break;
        }
        if (i == end - c + 1 && c - i < s) {
            int l = 2 * (end - c) + 1;
            res = malloc(l + 1);
            for (j = 0 ; j <= end - c ; j++) {
                res[j] = *(end-j);
            }
            memcpy(res+j, c+1, l-j+1); // +1 include '\0'
            return res;
        }
        for (i = 0 ; i <= end - c ; i++) {
            if (c - i - 1 >= s && *(c+i) != *(c-i-1)) break;
        }
        if (i == end - c + 1 && c - i - 1 < s) {
            int l = 2 * (end - c) + 2;
            res = malloc(l + 1);
            for (j = 0 ; j <= end - c ; j++) {
                res[j] = *(end-j);
            }
            memcpy(res+j, c, l-j+1); // +1 include '\0'
            return res;
        }
        c--;
    }
    return res;
}