void handleDotsIfNeed(char* stack, int * top) {
    if (stack[*top-1] == '.') {
        int dotCount = 0;
        while (*top > 0 && stack[*top-1-dotCount] == '.') {
            dotCount++;
        }
        if (dotCount > 2) {
            return;
        }
        (*top) = (*top) - dotCount;
        while (*top > 0 && dotCount > 0) {
            if (stack[*top-1] == '/') {
                dotCount--;
            }
            (*top)--;
        }
    }
}
char* simplifyPath(char* path) {
    int length = strlen(path);
    char *stack = malloc(length+1);
    int top = 0;
    
    while (*path != '\0') {
        if (top > 0 && *path == '/') {
            handleDotsIfNeed(stack, &top);
            if (stack[top-1] == '/') {
                top--;
            }
        }
        stack[top++] = *path;
        path++;
    }
    if (top>1 && stack[top-1] == '/') {
        top--;
    }
    handleDotsIfNeed(stack, &top);
    if (top == 0) {
        stack[top++] = '/';
    }
    stack[top] = '\0';
    return stack;
}