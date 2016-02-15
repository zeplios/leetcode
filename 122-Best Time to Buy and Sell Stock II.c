int maxProfit(int* prices, int pricesSize) {
    int i, total = 0, lastmax = 0, newmax = 0;
    for (i = 1 ; i < pricesSize ; i++) {
        newmax += (prices[i] - prices[i-1]);
        if (newmax > 0 && newmax > lastmax) {
            lastmax = newmax;
        } else {
            total += lastmax;
            newmax = 0;
            lastmax = 0;
        }
    }
    total += lastmax;
    return total;
}
