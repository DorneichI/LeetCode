class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        dp = [0, 1]

        while len(dp) <= n:
            dp.append(dp[len(dp) - 1] + dp[len(dp) - 2])
        
        return dp[len(dp) - 1]
        # dp = [-1 for _ in range(n + 1)]

        # def fibHelp(n: int) -> int:
        #     if dp[n] > 0:
        #         return dp[n]
        #     else:
        #         if n == 0:
        #             return 0
        #         elif n == 1:
        #             return 1
        #         else:
        #             return fibHelp(n - 1) + fibHelp(n - 2)

        # return fibHelp(n)  
