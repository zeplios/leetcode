char* numberToWords(int num) {
    char * res = malloc(100);
    int pos = 0, len;
    char *ones[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
                "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char *tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    if (num == 0) return ones[0];
    if (num < 1000) {
        int h = num / 100;
        if (h > 0) {
            len = strlen(ones[h]);
            memcpy(res, ones[h], len);
            pos += len;
            memcpy(&res[pos], " Hundred ", 9);
            pos += 9;
        }
        num %= 100;
        if (num == 0) {
            // do nothing
        } else if (num < 20) {
            len = strlen(ones[num]);
            memcpy(&res[pos], ones[num], len);
            pos += len;
        } else {
            h = num / 10;
            len = strlen(tens[h]);
            memcpy(&res[pos], tens[h], len);
            pos += len;
            res[pos++] = ' ';
            h = num % 10;
            if (h > 0) {
                len = strlen(ones[h]);
                memcpy(&res[pos], ones[h], len);
                pos += len;
            }
        }
    } else if (num < 1000000) {
        char * high = numberToWords(num / 1000);
        char * low;
        if (num % 1000 > 0) {
            low = numberToWords(num % 1000);
        } else {
            low = malloc(1);
            low[0] = '\0';
        }
        len = strlen(high);
        memcpy(&res[pos], high, len);
        pos += len;
        memcpy(&res[pos], " Thousand ", 10);
        pos += 10;
        len = strlen(low);
        memcpy(&res[pos], low, len);
        pos += len;
    } else if (num < 1000000000) {
        char * high = numberToWords(num / 1000000);
        char * low;
        if (num % 1000000 > 0) {
            low = numberToWords(num % 1000000);
        } else {
            low = malloc(1);
            low[0] = '\0';
        }
        len = strlen(high);
        memcpy(&res[pos], high, len);
        pos += len;
        memcpy(&res[pos], " Million ", 9);
        pos += 9;
        len = strlen(low);
        memcpy(&res[pos], low, len);
        pos += len;
    } else {
        char * high = numberToWords(num / 1000000000);
        char * low;
        if (num % 1000000000 > 0) {
            low = numberToWords(num % 1000000000);
        } else {
            low = malloc(1);
            low[0] = '\0';
        }
        len = strlen(high);
        memcpy(&res[pos], high, len);
        pos += len;
        memcpy(&res[pos], " Billion ", 9);
        pos += 9;
        len = strlen(low);
        memcpy(&res[pos], low, len);
        pos += len;
    }
    while (pos > 0 && res[pos-1] == ' ') pos--;
    res[pos] = '\0';
    return res;
}
