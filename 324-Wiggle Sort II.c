void swap(int* nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j]; nums[j] = tmp;
}
int nth_element(int* array, int length, int n) {
    int i, j, k = 0, l = length-1, m;
    if (length < 0 || n < 0 || n > length) return;
	
    while(true) {
        if (l <= k + 1) {
            if (l == k + 1 && array[l] < array[k]) {
                swap(array, k, l);
            }
            return array[n];
        } else {
            m = (k+l) >> 1; 
            swap(array, m, k+1);

            if (array[k] > array[l]) {
                swap(array, k, l);
            }
            if (array[k+1] > array[l]) {
                swap(array, k+1, l);
            }
            if (array[k] > array[k+1]) {
                swap(array, k, k+1);
            }
			
            i = k+1; 
            j = l;

            while (true) { 
                do i++; while (array[i] < array[k+1]);
                do j--; while (array[j] > array[k+1]);
                if (j < i) break;
                swap(array, i, j);
            } 

            swap(array, k+1, j);
            if ( j >= n ) l = j-1; 
            if ( j <= n ) k = i; 
        }
    }
}	

void wiggleSort(int* nums, int numsSize) {
    if (numsSize <= 1) return;
    int mid = nth_element(nums, numsSize, numsSize >> 1);
    
    // nums[l] is the first place hold a small number, but should be a big number
    // nums[r] is the last place hold a big number, but should be a small number
    int l = 1, r = numsSize - 1, i;
    if ((r & 1) == 1) r--;
    for (; l < r ; l+=2, r-=2) {
        swap(nums, l, r);
    }
    
    // if even index hold the number equals mid, move to front (move to nums[l])
    // if odd index hold the number equals mid, move to last (move to nums[r])
    l = 0, r = numsSize - 1;
    if ((r & 1) == 0) r--;
    for (i = 0 ; i < numsSize ; i++) {
        while ((i & 1) == 1 && nums[i] == mid && i < r) {
            swap(nums, i, r);
            r -= 2;
        }
        while ((i & 1) == 0 && nums[i] == mid && i > l) {
            swap(nums, i, l);
            l += 2;
        }
    }
}
