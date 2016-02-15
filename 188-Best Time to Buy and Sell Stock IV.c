#define max(i,j) i > j ? i : j
// how many monotonic increasing segments can be split
// if the given k is very large, all the segments can be used
int countMonos(int* prices, int pricesSize, int* sum) {
    int i, count = 0;
    (*sum) = 0;
    bool asc = false;
    for (i = 1 ; i < pricesSize ; i++) {
        if (prices[i] > prices[i-1]) {
            (*sum) += prices[i] - prices[i-1];
            asc = true;
        } else if (asc) {
            count++;
            asc = false;
        }
    }
    if (asc) count++;
    return count;
}
int maxProfit(int k, int* prices, int pricesSize) {
    int i, j, sum = 0;
    if (k >= countMonos(prices, pricesSize, &sum)) {
        return sum;
    }
    
    // prof[k] is the profit after k-th buy and k-th sell
    // hold[k] is the money hold on hand after k-th buy and (k-1)-th sell
    int prof[k+1], hold[k+1];
    for (j = 0 ; j <= k ; j++) {
        prof[j] = 0;
        hold[j] = -prices[0];
    }
    for (i = 1 ; i < pricesSize ; i++) {
        for (j = 1 ; j <= k ; j++) {
            prof[j] = max(prof[j], hold[j] + prices[i]);
            hold[j] = max(hold[j], prof[j-1] - prices[i]);
        } 
    }
    
    return prof[k];
}


/* old solution, not good
int dp(int** maxmap, int* prices, int k, int start, int size) {
    if (k == 0 || start >= size) return 0;
    if (maxmap[start][k] >= 0) return maxmap[start][k];
    
    bool asc = false;
    int i, max = 0, lastmax = 0, curmax = 0;
    for (i = start+1 ; i < size ; i++) {
        curmax += prices[i] - prices[i-1];
        if (curmax >= lastmax) {
            lastmax = curmax;
            asc = true;
        } else if (lastmax > 0 && asc) {
            int sum = lastmax + dp(maxmap, prices, k-1, i, size);
            if (sum > max) max = sum;
            asc = false;
        }
        if (curmax < 0) curmax = 0;
    }
    if (asc && lastmax > max) {
        max = lastmax;
    }
    maxmap[start][k] = max;
    return max;
}
int countMonos(int* prices, int pricesSize, int* sum) {...
int maxProfit(int k, int* prices, int pricesSize) {
    int i, j, sum;
    if (k >= countMonos(prices, pricesSize, &sum)) {
        return sum;
    }
    
    int** maxmap = malloc(pricesSize * sizeof(int*));
    for (i = 0 ; i < pricesSize ; i++) {
        maxmap[i] = malloc((k+1) * sizeof(int));
        for (j = 0 ; j < k+1 ; j++) maxmap[i][j] = -1;
    }
    return dp(maxmap, prices, k, 0, pricesSize);
}
*/
