int s1size, s2size;
bool** judged;
bool dp(char* s1, char* s2, char* s3, int s1start, int s2start) {
    if (s1start == s1size && s2start == s2size) return true;
    if (judged[s1start][s2start]) return false;
    if (s1start < s1size && s1[s1start] == s3[s1start + s2start] && dp(s1, s2, s3, s1start+1, s2start)) {
        return true;
    }
    if (s2start < s2size && s2[s2start] == s3[s1start + s2start] && dp(s1, s2, s3, s1start, s2start+1)) {
        return true;
    }
    judged[s1start][s2start] = true;
    return false;
}
bool isInterleave(char* s1, char* s2, char* s3) {
    s1size = strlen(s1);
    s2size = strlen(s2);
    int s3size = strlen(s3), i, j;
    if (s1size + s2size != s3size) return false;
    judged = malloc(sizeof(bool*) * (s1size+1));
    for (i = 0 ; i <= s1size ; i++) {
        judged[i] = calloc((s2size+1), sizeof(bool));
    }
    return dp(s1, s2, s3, 0, 0);
}