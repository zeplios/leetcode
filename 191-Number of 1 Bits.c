int hammingWeight(uint32_t n) {
    int num = 0;
    while (n != 0) {
        num += n & 0x1;
        n = n >> 1;
    }
    return num;
}