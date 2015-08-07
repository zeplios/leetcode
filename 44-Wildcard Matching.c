/*
我的代码很慢，别人10ms我100+ms，看了别人的解法，有一个很巧，线性时间复杂度（我自己又实现了一遍，跟原来的有写法上的改动：https://leetcode.com/discuss/10133/linear-runtime-and-constant-space-solution）：
bool isMatch(char* s, char* p) {
    char* star = NULL;
    char* ss = s;
    while (*s != '\0') {
        if (*s == *p || *p == '?') {
            p++;
            s++;
        } else if (*p == '*') {
            star = p;
            ss = s;
            p++;
        } else if (star) {
            p = star + 1;
            s = ++ss;
        } else {
            return false;
        }
    }
    // remain pattern need to be all '*'
    while (*p != '\0') {
        if (*p != '*') {
            return false;
        }
        p++;
    }
    return true;
}
*/



bool match(char* s, int slen, char* p, int plen, bool** judged) {
    if (judged[slen][plen]) return false; // if (slen, plen) can match, it will already return true
	if (plen == 0 && slen == 0) return true;
	if (plen == 0 && slen > 0) return false;
	if (slen == 0 && plen > 0 && *p != '*') return false;
	int originPlen = plen, originSlen = slen;
    if (*p == '*') {
        while (*p == '*') {
            p++; plen--;
        }
        if (plen == 0) return true;
    	int i;
        bool m = false;
        for (i = 0 ; i < slen ; i++) {
            if (*(s+i) == *p || *p == '?') {
                m |= match(s+i+1, slen-i-1, p+1, plen-1, judged);
                if (m) {
                    return true;
                }
            }
        }
        judged[originSlen][originPlen] = true;
        return false;
    }
    if (slen > 0 && plen > 0 && *p != '?' && *s != *p) {
        judged[originSlen][originPlen] = true;
        return false; //*p is not '*' and the first is not equal
    }
    while (slen > 0 && plen > 0 && (*p == '?' || *s == *p)) {
        s++; p++; slen--; plen--;
    }
    /*char* sEnd = s + slen - 1, * pEnd = p + plen - 1;
    while (slen > 0 && plen > 0 && (*pEnd == '?' || *sEnd == *pEnd)) {
        sEnd--; pEnd--; slen--; plen--;
    }*/
	return match(s, slen, p, plen, judged);
}
bool isMatch(char* s, char* p) {
    int slen = strlen(s), plen = strlen(p), i, j;
    bool** judged = malloc(sizeof(bool*) * (slen+1));
    for (i = 0 ; i < slen+1 ; i++) {
        judged[i] = malloc(sizeof(bool) * (plen+1));
        for (j = 0 ; j < plen+1 ; j++) {
            judged[i][j] = false;
        }
    }
    return match(s, strlen(s), p, strlen(p), judged);
}