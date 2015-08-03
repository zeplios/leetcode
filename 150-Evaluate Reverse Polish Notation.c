int evalRPN(char** tokens, int tokensSize) {
    int numStack[10000];
    int top = 0, i;
    for (i = 0 ; i < tokensSize ; i++) {
        if (tokens[i][0] == '+') {
            int ln = numStack[--top]; // last number
            int fn = numStack[--top]; // front number
            numStack[top++] = fn + ln;
        } else if (tokens[i][0] == '-' && tokens[i][1] == '\0') {
            int ln = numStack[--top]; // last number
            int fn = numStack[--top]; // front number
            numStack[top++] = fn - ln;
        } else if (tokens[i][0] == '*') {
            int ln = numStack[--top]; // last number
            int fn = numStack[--top]; // front number
            numStack[top++] = fn * ln;
        } else if (tokens[i][0] == '/') {
            int ln = numStack[--top]; // last number
            int fn = numStack[--top]; // front number
            numStack[top++] = fn / ln;
        } else {
            numStack[top++] = atoi(tokens[i]);
        }
    }
    // assert top == 0
    return numStack[--top];
}