bool isValidSerialization(char* preorder) {
    char * stack = malloc(strlen(preorder));
    int top = 0;
    while (*preorder != '\0') {
        stack[top++] = *preorder;
        while (top > 2 && stack[top-1] == '#' && stack[top-2] == '#') {
            top -= 2;
            if (stack[top-1] == '#') {
                return false;
            } else {
                stack[top-1] = '#';
            }
        }
        while (*preorder != '\0' && *preorder != ',') {
            preorder++;
        }
        if (*preorder != '\0') {
            preorder++;
        }
    }
    return top == 1 && stack[0] == '#';
}
