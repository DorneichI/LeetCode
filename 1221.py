class Solution:
    def balancedStringSplit(self, s: str) -> int:
        balanced = 0
        total = 0
        for i in s:
            if i == 'L':
                balanced -= 1
            else:
                balanced += 1
            if balanced == 0:
                total += 1
        return total
