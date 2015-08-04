/*
看了看Discuss，当然最优方案跟我的一样都是logn的，不过思路稍有不同，这里解释一下。
从最低位开始遍历，比如23，首先看3，它有几个1,0-3总共有1个1，标记为count1，0-9总共也是1个1，标记为count2，
再加上第二位23，它有两部分组成，1x和x1，
针对1x，如果最高位是1，比如13，那么这样的数总共有（3+1）个，也就是right+1，
如果最高位不是1（当然也不会是0），那么这样的数有base个，base是10的倍数，当前数字后面有几位base就几个0，
针对x1，23的话就是有01、11、21,20的话就是有01、11，也就是说，0-（x-1）都是对应count2个，x对应count1个
*/
int countDigitOne(int n) {
    int a, right = 0, count1 = 0, count2 = 0, base = 1;
    do {
        a = n % 10;
        count1 = a * count2 + count1;
        count2 = 10 * count2;
        if (a == 1) {
            count1 += (right + 1);
        } else if (a > 1) {
            count1 += base;
        }
        count2 += base;
        right += a * base;
        n /= 10;
        base *= 10;
    } while (n > 0);
    return count1;
}