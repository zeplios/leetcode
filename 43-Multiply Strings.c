char* multiply(char* num1, char* num2) {
    int size = 500;
    char* res = malloc(size);
    memset(res, 0, size);
    int end = size - 2, carry = 0;
    int l1 = strlen(num1), l2 = strlen(num2), i, j;
    res[end+1] = '\0';
    for (i = 0 ; i < l1 ; i++) {
        for (j = 0 ; j < l2 ; j++) {
            res[end-i-j] += (num1[l1-1-i]-'0') * (num2[l2-1-j]-'0') + carry;
            carry = res[end-i-j] / 10;
            res[end-i-j] %= 10;
        }
        if (carry > 0) {
            res[end-i-j] = carry;
        }
        carry = 0;
    }
    for (i = 0 ; i < size - 2 ; i++) { // size - 1 must be a digit
        if (res[i] > 0) {
            break;
        }
    }
    char *s = res + i;
    while (s < res + size - 1) {
        *s = *s + '0';
        s++;
    }
    return res + i;
}