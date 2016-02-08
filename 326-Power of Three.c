bool isPowerOfThree(int n) {
    // recursion version
    // return (n == 1) || (n > 0 && (n % 3 == 0) && isPowerOfThree(n/3));
    // 1162261467 == 3^19, the biggest integer which are power of three 
    return (n > 0 && 1162261467 % n==0);
}
