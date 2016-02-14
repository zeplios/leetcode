bool canMap(long map[26], int key, long hash) {
    if (map[key] >= 0 && map[key] != hash) {
        return false;
    }
    if (map[key] < 0) {
        // abba match 'dog dog dog dog' should return false
        int i;
        for (i = 0 ; i < 26 && map[i] != hash ; i++);
        if (i < 26) return false;
    }
    return true;
}
bool wordPattern(char* pattern, char* str) {
    long map[26];
    char *curp = pattern, *curs = str;
    
    int i;
    for (i = 0 ; i < 26 ; i++) map[i] = -1;
    
    while (*curp != '\0' && *curs != '\0') {
        long hash = 0;
        if (*curs == ' ') {
            curs++;
            continue;
        }
        while (*curs != ' ' && *curs != '\0') {
            hash = (hash << 5) | (*curs - 'a');
            curs++;
        }
        if (!canMap(map, *curp-'a', hash)) {
            return false;
        }
        map[*curp-'a'] = hash;
        curp++;
    }
    return *curp == '\0' && *curs == '\0';
}
