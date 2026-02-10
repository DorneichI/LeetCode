class Solution:
    def hammingWeight(self, n: int) -> int:
        weight = 0
        while n > 0:
            if n % 2 != 0:
                weight += 1
            n = n // 2
        return weight
