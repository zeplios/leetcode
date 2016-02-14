char* add(char* num1, int size1, char* num2, int size2) {
    int size = size1 > size2 ? size1 + 1 : size2 + 1;
    char * res = malloc(size+1);
    res[size] = '\0';
    int carry = 0, i, j;
    for (i = size1-1, j = size2-1 ; i >= 0 || j >= 0 || carry > 0 ; i--, j--) {
        int n1 = (i >= 0) ? num1[i] - '0' : 0;
        int n2 = (j >= 0) ? num2[j] - '0' : 0;
        int sum = n1 + n2 + carry;
        res[--size] = (sum % 10) + '0';
        carry = sum / 10;
    }
    return &res[size];
}
bool equals(char* num1, char* num2, int size) {
    int i;
    for (i = 0 ; i < size && num1[i] == num2[i] ; i++);
    return i == size;
}
bool isAdditiveNumber(char* num) {
    int size = strlen(num), size1, size2;
    char* num1 = num;
    char* num2 = num + 1;
    while (num2 <= num + size/2) {
        size1 = num2 - num1;
        size2 = 1;
        while (size1 + size2 < size) {
            char* sum = add(num1, size1, num2, size2);
            int sumlen = strlen(sum);
            if (sumlen + size1 + size2 > size) {
                break;
            }
            if (equals(sum, num2+size2, sumlen)) {
                if (sumlen + size1 + size2 == size) {
                    return true;
                } else if (isAdditiveNumber(num2)) {
                    return true;
                }
            }
            if (size2 == 1 && *num2 == '0') {
                break;
            }
            size2++;
        }
        num2++;
    }
    return false;
}
