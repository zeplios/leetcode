char* longestCommonPrefix(char** strs, int strsSize) {
    char * res = malloc(1000);
    
    if (strsSize == 0) {
        res[0] = '\0';
        return res;
    }
    int i;
    char * c = strs[0];
    int pos = 0;
    while (*c != NULL) {
        for (i = 1 ; i < strsSize ; i++) {
            if (*c != strs[i][pos]) {
                break;
            }
        }
        if (i != strsSize) {
            break;
        }
        res[pos++] = *c;
        c++;
    }
    res[pos] = '\0';
    return res;
}