/**
 * judge string s
 * @param rml the max number of '(' should be removed
 * @param rmr the max number of ')' should be removed
 * @param count('(') - count(')') in the result string
 */
void dfs(char** res, int* ressize, char* s, int rml, int rmr, int pair, char* stack, int top) {
    if (pair < 0) return;
    
    if (*s == '\0' && rml == 0 && rmr == 0 && pair == 0) {
        char* str = malloc(top+1);
        memcpy(str, stack, top);
        str[top] = '\0';
        res[(*ressize)++] = str;
        return;
    }
    if (*s == '\0') return;

    if (*s == '(') {
        int i = 0;
        while (s[i] == '(') {
            // use while loop to avoid duplicate result in DFS, instead of using HashSet
            stack[top++] = s[i];
            i++;
        }
        dfs(res, ressize, &s[i], rml, rmr, pair+i, stack, top);
        top -= i;
        
        if (rml > 0) {
            dfs(res, ressize, &s[1], rml-1, rmr, pair, stack, top);
        }
    } else if (*s == ')') {
        int i = 0;
        while (s[i] == ')') {
            // use while loop to avoid duplicate result in DFS, instead of using HashSet
            stack[top++] = s[i];
            i++;
        }
        dfs(res, ressize, &s[i], rml, rmr, pair-i, stack, top);
        top -= i;
        
        if (rmr > 0) {
            dfs(res, ressize, &s[1], rml, rmr-1, pair, stack, top);
        }
    } else {
        stack[top++] = *s;
        dfs(res, ressize, &s[1], rml, rmr, pair, stack, top);
    }
}
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** removeInvalidParentheses(char* s, int* returnSize) {
    char** res = malloc(1000 * sizeof(int*));
    (* returnSize) = 0;
    
    char* stack = malloc(strlen(s)), *c = s;
    int rml = 0, rmr = 0, top = 0;
    while (*c != '\0') {
        if(*c == '(') rml++;
        if(*c == ')') {
            if(rml != 0) rml--;
            else rmr++;
        }
        c++;
    }
    
    dfs(res, returnSize, s, rml, rmr, 0, stack, top);
    return res;
}
