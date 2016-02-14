int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    int base[primesSize], ugly[n];
    int i, idx = 0;
    ugly[idx++] = 1;
    for (i = 0 ; i < primesSize ; i++) {
        base[i] = 0;
    }
    
    while (idx < n) {
        int min = INT_MAX;
        for (i = 0 ; i < primesSize ; i++) {
            int next = ugly[base[i]] * primes[i];
            min = min < next ? min : next;
        }
        ugly[idx++] = min;
        for (i = 0 ; i < primesSize ; i++) {
            while (ugly[base[i]] * primes[i] <= min) base[i]++;
        }
    }
    return ugly[n-1];
}
