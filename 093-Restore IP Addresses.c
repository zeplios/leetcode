/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void ria(char* s, int slen, int* returnSize, char* cur, int curstart, int nums, char** res) {
    // cur is the current progress, '255.255.' means curstart == 8 and nums == 2
    if (nums == 4 && slen != 0) return;
    if (nums == 4) {
        cur[curstart-1] = '\0'; // replace the last '.'
        res[(* returnSize)] = malloc(curstart);
        memcpy(res[(* returnSize)], cur, curstart);
        (* returnSize)++;
        return;
    }
    int minl = slen - 3*(4-nums-1);
    minl = minl < 1 ? 1 : minl;
    int maxl = slen - (4-nums-1);
    maxl = maxl > 3 ? 3 : maxl;
    if (s[0] == '0') {
        if (minl > 1) return;
        minl = 1;
        maxl = 1;
    }
    int i, num = 0;
    for (i = 0 ; i < minl ; i++) {
        if (num * 10 + s[i] - '0' > 255) {
            break;
        }
        num = num * 10 + s[i] - '0';
        cur[curstart++] = s[i];
    }
    cur[curstart++] = '.';
    ria(s+i, slen-i, returnSize, cur, curstart, nums+1, res);
    curstart--;
    for (; i < maxl ; i++) {
        if (num * 10 + s[i] - '0' > 255) {
            break;
        }
        num = num * 10 + s[i] - '0';
        cur[curstart++] = s[i];
        cur[curstart++] = '.';
        ria(s+i+1, slen-i-1, returnSize, cur, curstart, nums+1, res);
        curstart--;
    }
}
char** restoreIpAddresses(char* s, int* returnSize) {
    char** res = malloc(sizeof(char*) * 1000);
    (* returnSize) = 0;
    ria(s, strlen(s), returnSize, malloc(16), 0, 0, res);
    return res;
}