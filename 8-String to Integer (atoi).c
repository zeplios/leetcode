/*=============================================
这个也能过…………感觉挺奇怪的
int myAtoi(char* str) {
    long result = 0;
    int sign = 1;
    //discard the first sequence of whitespace characters.
    while(isspace(*str))
    {
        str++;
    }
    if((*str == '+') || (*str == '-'))
    {
        sign = (*str == '+') ? 1:0;
        str++;
    }
    if(!isdigit(*str))
    {
        return 0;
    }
    while(isdigit(*str) && (result <= INT_MAX))
    {
        result = result * 10 + *str - '0' + 0;
        str++;
    }
    if(result > INT_MAX)
    {
        return sign == 1 ? INT_MAX : INT_MIN;
    }
    return sign == 1 ? result : -result;
}
===============================================*/


int myAtoi(char* str) {
    if (str == NULL) return 0;
    int num = 0;
    int pre = 1; // + or -
    bool preIsNum = true;
    bool begin = false;
    char* c = str;
    while (*c != '\0') {
        if (*c == '+' || *c == '-') {
            if (!preIsNum) {
                return 0;
            }
            preIsNum = false;
            begin = true;
            pre = (*c == '-') ? -1 : 1;
        } else if (*c >= '0' && *c <= '9') {
            preIsNum = true;
            begin = true;
            if (num > INT_MAX / 10) {
                num = -1;
                break;
            }
            num = num * 10 + *c - '0';
            if (num > INT_MAX || num < 0) break;
        } else if (*c == ' ' && !begin) {
        } else {
            return pre * num;
        }
        c++;
    }
    if (num > INT_MAX || num < 0 && pre == 1) {
        return INT_MAX;
    } else if (num > INT_MAX || num < 0) {
        return INT_MIN;
    }
    return pre * num;
}