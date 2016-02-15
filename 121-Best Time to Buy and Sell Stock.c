int maxProfit(int* prices, int pricesSize) {
    int lastmax = 0, newmax = 0, i;
    for (i = 1 ; i < pricesSize ; i++) {
        newmax += (prices[i] - prices[i-1]);
        if (newmax > lastmax) {
            lastmax = newmax;
        } else if (newmax < 0) {
            newmax = 0;
        }
    }
    return lastmax;
}

/* at first I come up with this method, not good
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0 || pricesSize == 1) {
        return 0;
    }
    int i;
    int * max = calloc(pricesSize, sizeof(int));
    int * min = calloc(pricesSize, sizeof(int));
    min[0] = prices[0];
    max[pricesSize - 1] = prices[pricesSize - 1];
    for (i = 1 ; i < pricesSize ; i++) {
        min[i] = prices[i] < min[i - 1] ? prices[i] : min[i - 1];
    }
    for (i = pricesSize - 2 ; i >= 0 ; i--) {
        max[i] = prices[i] > max[i + 1] ? prices[i] : max[i + 1];
    }
    int maxPro = max[0] - min[0];
    for (i = 1 ; i < pricesSize ; i++) {
        int m = max[i] - min[i];
        if (m > maxPro) maxPro = m;
    }
    return maxPro;
}
*/
