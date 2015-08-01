bool mapping(char* haystack, char* needle) {
    char *c = needle;
    char *s = haystack;
    while (*c != '\0') {
        if (*s == '\0' || *s != *c) {
            return false;
        }
        c++;
        s++;
    }
    return true;
}
int strStr(char* haystack, char* needle) {
    char *s = haystack;
    int slen = strlen(s);
    int nlen = strlen(needle);
    while (slen >= nlen) {
        if (mapping(s, needle)) {
            return s - haystack;
        }
        s++;
        slen--;
    }
    return -1;
}