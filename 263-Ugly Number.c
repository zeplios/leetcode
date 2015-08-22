bool isUgly(int num) {
    while (num >= 2 && num % 2 == 0) num /= 2;
    while (num >= 3 && num % 3 == 0) num /= 3;
    while (num >= 5 && num % 5 == 0) num /= 5;
    return num == 1;
}