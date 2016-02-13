char* removeDuplicateLetters(char* s) {
    int size = strlen(s), i, idx = 0;
    int last[128]; // 26 is enough, 128 make the code cleaner
    for (i = 0 ; i < size ; i++) {
        last[s[i]] = i;
    }
    
    char* res = malloc(size);
    bool have[128];
    memset(have, 0, 128 * sizeof(bool));
    for (i = 0 ; i < size ; i++) {
        char c = s[i];
        while (!have[c] && idx > 0 && last[res[idx-1]] > i && c < res[idx-1]) {
            have[res[idx-1]] = false;
            idx--;
        }
        if (!have[c]) {
            have[c] = true;
            res[idx++] = c;
        }
    }
    res[idx++] = '\0';
    return res;
}
