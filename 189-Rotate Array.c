void rotate(int nums[], int n, int k) {
    if (k == 0 || n == k) {
        return;
    }
    for (int i = 0 ; i < maxyueshu(n, k) ; i++) {
        int swap = 0, cur = i, temp1 = nums[cur], temp2 = 0;
        while ((swap = (cur + k) % n) != i) {
            temp2 = nums[swap];
            nums[swap] = temp1;
            cur = swap;
            temp1 = temp2;
        }
        nums[i] = temp1;
    }
}

int maxyueshu(int n, int k) {
    if (n < k) {
        return maxyueshu(k, n);
    } else {
        if (n % k == 0) {
            return k;
        } else {
            return maxyueshu(k, n % k);
        }
    }
}