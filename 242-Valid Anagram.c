bool isAnagram(char* s, char* t) {
    int a[26];
    memset(a, 0, sizeof(int)*26);
    
    while (*s != '\0') {
        a[*s-'a']++;
        s++;
    }
    while (*t != '\0') {
        a[*t-'a']--;
        t++;
    }
    int i;
    for (i = 0 ; i < 26 ; i++) {
        if (a[i] != 0) {
            return false;
        }
    }
    return true;
}