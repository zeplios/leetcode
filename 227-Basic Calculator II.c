void pushNum(int* stack, int* top, int num) {
    if (*top > 1 && stack[*top-1] == '*' || stack[*top-1] == '/') {
        char op = stack[--(*top)];
        int n = stack[--(*top)];
        stack[(*top)++] = op == '*' ? n * num : n / num;
    } else {
        // 1 + 2 + 3, when 3 will be pushed, 1 + 2 can be calculated
        if (*top > 3 && (stack[*top-3] == '+' || stack[*top-3] == '-')) {
        	char op2 = stack[--(*top)];
        	int n2 = stack[--(*top)];
            char op1 = stack[--(*top)];
            int n1 = stack[--(*top)];
            stack[(*top)++] = op1 == '+' ? n1 + n2 : n1 - n2;
            stack[(*top)++] = op2;
        }
    	stack[(*top)++] = num;
	}
}
int calcu(int* stack, int start, int top) {
    // all operators from start must be either '+' or '-'
    int n1 = stack[start++];
    while (start < top - 1) {
    	char op = stack[start++];
    	int n2 = stack[start++];
    	n1 = op == '+' ? n1 + n2 : n1 - n2;
	}
	return n1;
}
int calculate(char* s) {
    int size = 10000, top = 0, num = 0;
    bool hasNum = false;
    int stack[size];
    char op;
    
    while (*s != '\0') {
        if (!isdigit(*s) && *s != ' ') {
            if (hasNum) {
            	// if we use num != 0 instand of hasNum, when the input is 0, it will be confused
                pushNum(stack, &top, num);
            	num = 0;
            	hasNum = false;
            }
            if (*s == ')') {
                int start = top-2;
                while (stack[start] != '(') start -= 2;
                int n = calcu(stack, start+1, top);
                top = start;
                pushNum(stack, &top, n);
            } else {
                stack[top++] = *s;
            }
        } else if (isdigit(*s)) {
            num = num * 10 + *s - '0';
            hasNum = true;
        }
        s++;
    }
    if (hasNum) {
        pushNum(stack, &top, num);
    }
    return calcu(stack, 0, top);
}