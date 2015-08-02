/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int power4(int p) {
    int i, res = 1;
    for (i = 0 ; i < p ; i++) {
        res *= 4;
    }
    return res;
}
void letterHelper(char* digits, int digitslen, char** res, int* returnSize, char* stack, int top) {
    int i;
    if (top == digitslen) {
        res[(* returnSize)] = malloc(top+1);
        for (i = 0 ; i < top ; i++) {
            res[(* returnSize)][i] = stack[i];
        }
        res[(* returnSize)][i] = '\0';
        (* returnSize)++;
        return;
    }
    int start[] = {' ', '1', 'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'};
    int size[] = {1, 1, 3, 3, 3, 3, 3, 4, 3, 4};
    char digit = digits[top];
    for (i = 0 ; i < size[digit-'0'] ; i++) {
        stack[top++] = i + start[digit-'0'];
        letterHelper(digits, digitslen, res, returnSize, stack, top);
        top--;
    }
}
char** letterCombinations(char* digits, int* returnSize) {
    int length = strlen(digits);
    char** res = malloc(sizeof(char*) * power4(length));
    (* returnSize) = 0;
    
    char* stack = malloc(length+1);
    int top = 0;
    if (length > 0) {
        letterHelper(digits, length, res, returnSize, stack, top);
    }
    return res;
}