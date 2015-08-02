int lengthOfLongestSubstring(char* s) {
    bool exist[128];
    int i, max = 0;
    for (i = 0 ; i < 128 ; i++) {
        exist[i] = false;
    }
    char* start = s, *c = s;
    if (*s == '\0') {
        return 0;
    }
    exist[*c] = true;
    c++;
    while (*c != '\0') {
        if (exist[*c]) {
            max = (c-start > max) ? c-start : max;
            while (*start != *c) {
                exist[*start] = false;
                start++;
            }
            start++; // char for *c is still in the exist table
        } else {
            exist[*c] = true;
        }
        c++;
    }
    max = (c-start > max) ? c-start : max;
    return max;
}