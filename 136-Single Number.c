！！！利用Storm的id异或！！！

int singleNumber(int* nums, int numsSize) {
    int num = 0, i;
    for (i = 0 ; i < numsSize ; i++) {
        num ^= nums[i];
    }
    return num;
}