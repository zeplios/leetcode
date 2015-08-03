// I find that the memcpy of leetcode will go wrong when handle the overlap,
// e.g. the input "   one.   +two three?   ~four   !five- ", so I implement it, 
void mymemcpy(char* d, char* s, int l) {
	if (s == d || l <= 0) return;
	int i;
	if (s > d) {
		for (i = 0 ; i < l ; i++) {
			*(d+i) = *(s+i);
		}
	} else {
		for (i = l - 1 ; i >= 0 ; i--) {
			*(d+i) = *(s+i);
		}
	}
}
void reverseWordsHelper(char *s, char *e) {
    if (s >= e) return;
    
    int len = e-s+1, i;
    int fp = 0, lp = 0;
    while (*(s+fp) != ' ' && s+fp <= e) fp++;
    if (fp == len) return;
    while (*(e-lp) != ' ' && s <= e-lp) lp++;
    
    if (fp >= lp) {
        char* buf = malloc(fp+1);
        mymemcpy(buf, s, fp);
        mymemcpy(s+lp, s+fp, len-fp-lp);
        mymemcpy(s, e-lp+1, lp);
        mymemcpy(e-fp+1, buf, fp);
        reverseWordsHelper(s+lp+1, e-fp-1);
    } else {
        char* buf = malloc(lp+1);
        mymemcpy(buf, e-lp+1, lp);
        mymemcpy(s+lp, s+fp, len-fp-lp);
        mymemcpy(e-fp+1, s, fp);
        mymemcpy(s, buf, lp);
        reverseWordsHelper(s+lp+1, e-fp-1);
    }
}
void reverseWords(char *s) {
    int len = strlen(s), i, offset = 0;
	char pre=' ';;
    for (i = 0 ; i < len ; i++) {
        if (pre == ' ' && s[i] == ' ') {
            offset++;
        } else {
            s[i-offset] = s[i];
            pre = s[i];
        }
    }
    if (s[i-offset-1] == ' ') {
        s[i-offset-1] = '\0';
    } else {
        s[i-offset] = '\0';
    }
    len = strlen(s);
    reverseWordsHelper(s, s+len-1);
}