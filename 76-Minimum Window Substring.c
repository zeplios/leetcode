char* minWindow(char* s, char* t) {
    int count[128], needmatch = 0, min = INT_MAX;
    memset(count, 0, sizeof(int)*128);
    while (*t != '\0') {
        count[*t]--;
        needmatch++;
        t++;
    }
    if (needmatch == 0) return t;
    
    char* minstart = s, *minend = s;
    char* start = s, * end = s;
    while (*end != '\0') {
        if (needmatch == 0 && *end == *start) {
            start++;
            while (count[*start] > 0) {
                count[*start]--;
                start++;
            }
        } else {
            if (count[*end] < 0) {
                needmatch--;
            }
            count[*end]++;
        }
        if (needmatch == 0) {
            while (count[*start] > 0) {
                count[*start]--;
                start++;
            }
            if (end-start+1 < min) {
                minstart = start;
                minend = end;
                min = end - start + 1;
            }
        }
        end++;
    }
    char* res = malloc(minend - minstart + 2);
    if (min == INT_MAX) {
        res[0] = '\0';
    } else {
        memcpy(res, minstart, min);
        res[min] = '\0';
    }
    return res;
}