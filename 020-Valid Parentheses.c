bool isPair(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}
bool isValid(char* s) {
    char stack[100];
    int top = 0;
    while (*s != '\0') {
        if (*s == ')' || *s ==']' || *s == '}') {
            if (top == 0) return false;
            if (!isPair(stack[--top], *s)) {
                return false;
            }
        } else {
            stack[top++] = *s;
        }
        s++;
    }
    return top == 0 ? true : false;
}