/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    int ls = 0, rs = 0, i;
    char stack[2*n];
    int top = 0;
    char ** res = malloc(10000*sizeof(char*));
    (* returnSize) = 0;
    while (true) {
        if (top == 2 * n) {
            res[(* returnSize)] = malloc(top+1);
            for (i = 0 ; i < top ; i++) {
                res[(* returnSize)][i] = stack[i];
            }
            res[(* returnSize)][i] = '\0';
            (* returnSize)++;
            while (true) {
                if (top == 0) {
                    break;
                }
                while (stack[top-1] == ')') {
                    rs--;
                    top--;
                }
                // stack[top-1] == '('
                ls--;
                top--;
                if (ls <= rs) {
                    continue;
                } else {
                    stack[top++] = ')';
                    rs++;
                    break;
                }
            }
        }
        if ((* returnSize) != 0 && top == 0) {
            break;
        }
        if (ls < n) {
            stack[top++] = '(';
            ls++;
        } else {
            stack[top++] = ')';
            rs++;
        }
    }
    return res;
}