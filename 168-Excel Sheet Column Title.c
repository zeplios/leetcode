char *convertToTitle(int n) {
    char * out = malloc(11);
    out[10] = '\0';
    int poi = 9;
    while (n > 0) {
		n--;
        out[poi--] = (n % 26) + 65;
        n = n / 26;
    }
    return out + poi + 1;
}