char* addBinary(char* a, char* b) {
    int l1 = 0, l2 = 0, c1, c2;
    
    char *c = a;
    while (*c != '\0') c++;
    l1 = c - a;
    c = b;
    while (*c != '\0') c++;
    l2 = c - b;
    
    int resSize = l1 > l2 ? l1+2 : l2+2;
    char * res = malloc(resSize);
    res[--resSize] = '\0';
    int carry = 0;
    while (l1 > 0 || l2 > 0 || carry > 0) {
        c1 = l1 > 0 ? a[--l1]-'0' : 0;
        c2 = l2 > 0 ? b[--l2]-'0' : 0;
        int c = c1 + c2 + carry;
        if (c >= 2) {
            res[--resSize] = c - 2 + '0';
            carry = 1;
        } else {
            res[--resSize] = c + '0';
            carry = 0;
        }
    }
    return res + resSize;
}