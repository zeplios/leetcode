int longestValidParentheses(char* s) {
    int stack[100000];
    int sum = 0, top = 0, max = 0, i, j;
    stack[top++] = 0;
    while (*s != '\0') {
        if (*s == '(') {
            stack[top++] = ++sum;
        } else {
            stack[top++] = --sum;
        }
        if (sum < 0) {
            top = 1;
            sum = 0;
        }
        if (*s == ')') {
            for (i = top-2 ; i >= 0 ; i--) {
                if (stack[i] < stack[top-1]) {
                    int newLen = top - 2 - i;
                    max = newLen > max ? newLen : max;
                    break;
                }
            }
            if (i == -1 && stack[0] == stack[top-1]) {
                int newLen = top - 1;
                max = newLen > max ? newLen : max;
            }
        }
        s++;
    }
    return max;
}