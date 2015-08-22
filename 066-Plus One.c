/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int * res;
    (* returnSize) = 0;
    if (digits[0] == 9 && digits[digitsSize-1] == 9) {
        res = malloc((digitsSize+1)*sizeof(int));
        (* returnSize) = digitsSize + 1;
    } else {
        res = malloc(digitsSize*sizeof(int));
        (* returnSize) = digitsSize;
    }
    int pos = (* returnSize) - 1;
    int carry= 1, i;
    for ( ; pos >= 0 ; pos--) {
        res[pos] = (digitsSize > 0 ? digits[--digitsSize] : 0) + carry;
        if (res[pos] > 9) {
            res[pos] = 0;
        } else {
            carry = 0;
        }
    }
    return res;
}