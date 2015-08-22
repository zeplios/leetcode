char* intToRoman(int num) {
    char *res = malloc(100);
    int size = 0;
    while (num >= 1000) {
        res[size++] = 'M';
        num -= 1000;
    }
    if (num >= 900) {
        res[size++] = 'C';
        res[size++] = 'M';
        num -= 900;
    }
    if (num >= 500) {
        res[size++] = 'D';
        num -= 500;
    }
    if (num >= 400) {
        res[size++] = 'C';
        res[size++] = 'D';
        num -= 400;
    }
    while (num >= 100) {
        res[size++] = 'C';
        num -= 100;
    }
    if (num >= 90) {
        res[size++] = 'X';
        res[size++] = 'C';
        num -= 90;
    }
    if (num >= 50) {
        res[size++] = 'L';
        num -= 50;
    }
    if (num >= 40) {
        res[size++] = 'X';
        res[size++] = 'L';
        num -= 40;
    }
    while (num >= 10) {
        res[size++] = 'X';
        num -= 10;
    }
    if (num == 9) {
        res[size++] = 'I';
        res[size++] = 'X';
        num -= 9;
    }
    if (num >= 5) {
        res[size++] = 'V';
        num -= 5;
    }
    if (num == 4) {
        res[size++] = 'I';
        res[size++] = 'V';
        num -= 4;
    }
    while (num >= 1) {
        res[size++] = 'I';
        num -= 1;
    }
    res[size++] = '\0';
    return res;
}