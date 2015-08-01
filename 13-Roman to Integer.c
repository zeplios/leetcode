int ch2num(char a) {
    switch(a) {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
    }
}
int romanToInt(char* s) {
    int i = 0;
    int sum = 0, last = 0, cur = 0;
    char a;
    while((a = s[i++]) != '\0') {
        cur = ch2num(a);
        if (last != 0) {
            if (last < cur) {
                sum += cur - last;
                last = 0;
            } else {
                sum += last;
                last = cur;
            }
        } else {
            last = cur;
        }
    }
    sum += last;
    return sum;
}