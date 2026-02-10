class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        total = 0
        while x != 0 or y != 0:
            if x % 2 != y % 2:
                total += 1
            x = x // 2
            y = y // 2
        
        return total
