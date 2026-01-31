class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []

        def backtrack(start, path):
            total = sum(path)
            if total == target:
                res.append(path.copy())
                return
            elif total > target:
                return
            
            for i in range(start, len(candidates)):
                path.append(candidates[i])
                backtrack(i, path)
                path.pop()

        backtrack(0, [])

        return res
