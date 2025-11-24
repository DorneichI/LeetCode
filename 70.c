int climbStairs(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    static int memo[46];
    if (memo[n] <= 0) {
        memo[n] = climbStairs(n-1) + climbStairs(n-2);
    }
    return memo[n];
}