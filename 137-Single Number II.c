/**
 * 时间非常长，152ms，最笨的方法
    int ones = 0, twos = 0;
    for(int i = 0; i < A.length; i++){
        ones = (ones ^ A[i]) & ~twos;
        twos = (twos ^ A[i]) & ~ones;
    }
    return ones;
 */

int singleNumber(int* nums, int numsSize) {
    int i, j;
    for (i = 0 ; i < numsSize ; i++) {
        if (!nums[i]) continue;
        int find = 0;
        for (j = i + 1 ; j < numsSize ; j++) {
            if (nums[i] == nums[j]) {
                nums[j] = 0;
                find++;
                if (find == 2) {
                    break;
                }
            }
        }
        if (j == numsSize) {
            return nums[i];
        }
    }
    return 0;
}



/*======&&&&&&&&&&&&&&&================其他人的解决方案================&&&&&&&&&&&&&&&================*/
I think my solution is easier to understand.

First, here is my code for Single Number II

public int singleNumber(int[] nums) {
    int ones = 0, twos = 0 , threes = 0;
    for(int x:nums){
        threes = twos&x;
        twos = (ones&x|twos) & (~threes);
        ones = (ones|x)&(~threes);
    }
    return ones;
}
Run a loop for all elements in array. At the end of every iteration, maintain following three values.

threes: The bits that have appeared 3st time or 6th time or 9th time .. etc [times % 3 == 0 && times > 1].

ones: The bits that have appeared 2nd time or 5th time or 8th time .. etc. [times % 3 >= 2 && times%3 != 0, here so times%3 == 2]

ones: The bits that have appeared 2nd time or 5th time or 8th time .. etc. [times %3 >=1 && time %3 != 0, here (times %3 ==1 or times %3 == 2)]

each iteration, when x comes

cause pre twos is (times%3 == 2), then now threes = twos&x;

to calculate twos, first we get the bit satify times % 3 >= 2 , it's (ones&x|twos), then get rid of the bits that times%3 == 2 namely threes, then twos = (ones&x|twos) & (~threes);

to calculate twos, first we get the bit satify times % 3 >= 1, it's (ones|x) ,also we need to get rid of the bits that times%3 == 2 namely threes, then ones = (ones|x)&(~threes);

sorry for my English.

===============================================================================

for this problem,

Statement of our problem: "Given an array of integers, every element appears k (k >1) times except for one, which appears p times(p>=1, p % k != 0). Find that single one."

public int singleNumber(int[] nums) {
    int ones = 0, twos = 0 , threes = 0;
    for(int x:nums){
        ks = k_1s&x;
        k_1s = (k_2s&x|k_1s) & (~ks);
        k_2s = (k_3s&x|k_2s) & (~ks);
        .......
        twos = (ones&x|twos) & (~ks);
        ones = (ones|x)&(~ks);
    }
    return ps;
}

/*======&&&&&&&&&&&&&&&================其他人的解决方案================&&&&&&&&&&&&&&&================*/

int singleNumber(int A[], int n) {
int r = 0, c = 0; 
// r A c | r  c
// 0 0 0 | 0  0
// 0 0 1 | 0  1
// 0 1 0 | 1  0  ==> r = (~r & A & ~c) | (r & ~A & ~c)
// 0 1 1 | 0  0  ==> c = (~r & ~A & c) | (r & A & ~c)
// 1 0 0 | 1  0
// 1 0 1 | 0  0
// 1 1 0 | 0  1
// 1 1 1 | 0  0

while(n > 0) {
    --n;
    int t =  (~r & A[n] & ~c) | (r & ~A[n] & ~c); 
    c = (~r & ~A[n] & c) | (r & A[n] & ~c);
    r = t;
}
return r; 
}

for each bit, it needs a counter. Since the max value of the counter is 3 (0b11), it needs 2 bits, so "r" is the base bit, and "c" is the carry. The truth table shows the accumulation: when "c" is "1", it means the current counter is 2, then if A is "1", the counter will be reset.

/*======&&&&&&&&&&&&&&&================其他人的解决方案================&&&&&&&&&&&&&&&================*/