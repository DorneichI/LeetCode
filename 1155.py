class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        mod = 10 ** 9 + 7
        dp = [[-1 for _ in range(target)] for _ in range(n)]
        for i in range(min(k, target)):
            dp[0][i] = 1
        def nRTT(n, k, target):
            if n == 0 or target <= 0:
                return 0
            for i in reversed(range(target)):
                if dp[n - 1][target - 1] >= 0:
                    return dp[n - 1][target - 1]
                else:
                    total = 0
                    for j in range(1, k + 1):
                        total += nRTT(n - 1, k, target - j)
                    dp[n - 1][target - 1] = total % mod
                    return dp[n - 1][target - 1]
        
        return nRTT(n, k, target)
