/*=================================================
别人很巧的方法：
int climbStairs(int n) {
    int a = 1, b = 1;
    while (n--)
        a = (b += a) - a;
    return a;
}
Variable a tells you the number of ways to reach the current step, and b tells you the number of ways to reach the next step. So for the situation one step further up, the old b becomes the new a, and the new b is the old a+b, since that new step can be reached by climbing 1 step from what b represented or 2 steps from what a represented.
===================================================*/


int climbStairs(int n) {
    if (n == 0 || n == 1) return 1;
    if (n == 2) return 2;
    int num[n+1], i;
    num[0] = num[1] = 1;
    num[2] = 2;
    for (i = 3 ; i <= n ; i++) {
        num[i] = num[i-1] + num[i-2];
    }
    return num[n];
}