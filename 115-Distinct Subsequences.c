int numDistinct(char* s, char* t) {
    int slen = strlen(s), tlen = strlen(t), i, j;
    if (slen == 0 || tlen == 0) return 0;
    int count[slen][tlen];
    for (i = 0 ; i < slen ; i++) {
        for (j = 0 ; j < tlen ; j++) {
            if (i < j) count[i][j] = 0;
            else if (i == 0 && j == 0) count[i][j] = (s[i] == t[j]);
            else if (j == 0) count[i][j] = count[i-1][j] + (s[i] == t[j]);
            else {
                if (s[i] == t[j]) {
                    count[i][j] = count[i-1][j] + count[i-1][j-1];
                } else {
                    count[i][j] = count[i-1][j];
                }
            }
        }
    }
    return count[slen-1][tlen-1];
}