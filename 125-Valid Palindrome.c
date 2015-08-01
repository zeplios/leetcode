/********====================
×¢Òâ¿Õ´®
======================********/

bool isCh(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}
char igcase(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c + 'a' - 'A';
	}
	return c;
}
bool isPalindrome(char* s) {
    char *c = s;
    while (*c != '\0') {
    	c++;
	}
    int length = c - s;
    if (length <= 0) return true;
    char *first = s, *last = c - 1;
    while (true) {
        while (*first != '\0' && !isCh(*first)) first++;
        while (!isCh(*last)) last--;
        if (first >= last)
            break;
        char a = *first;
        char b = *last;
        if (igcase(a) != igcase(b)) {
            return false;
        } else {
            first++;
            last--;
        }
    }
    return true;
}