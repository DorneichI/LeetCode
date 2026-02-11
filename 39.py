class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        dp = [[] for _ in range(target)]
        for i in candidates:
            if i <= target:
                dp[i - 1].append([i])
        for i in range(target):
            for j in dp[i]:
                for k in candidates:
                    if k >= j[len(j) - 1] and i + k < target:
                        dp[i + k].append(j + [k])
                  
        return dp[target - 1]
        # res = []

        # def backtrack(start, path):
        #     total = sum(path)
        #     if total == target:
        #         res.append(path.copy())
        #         return
        #     elif total > target:
        #         return
            
        #     for i in range(start, len(candidates)):
        #         path.append(candidates[i])
        #         backtrack(i, path)
        #         path.pop()

        # backtrack(0, [])

        # return res
