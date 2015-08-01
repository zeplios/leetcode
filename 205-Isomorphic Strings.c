bool isIsomorphic(char* s, char* t) {
    // paper -> 12134, title -> 12134
    int map1[128], map2[128];
    int i, map1cur = 0, map2cur = 0, h1, h2;
    for (i = 0 ; i < 128 ; i++) {
        map1[i] = -1;
        map2[i] = -1;
    }
    while (true) {
        // note says that 'You may assume both s and t have the same length'
        if (*s == '\0' && *t == '\0') {
            break;
        }
        h1 = map1[*s];
        if (h1 == -1) {
            h1 = map1cur;
            map1[*s] = map1cur++;
        }
        h2 = map2[*t];
        if (h2 == -1) {
            h2 = map2cur;
            map2[*t] = map2cur++;
        }
        if (h1 != h2) {
            return false;
        }
        s++;
        t++;
    }
    return true;
}