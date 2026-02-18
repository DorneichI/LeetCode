class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        k = 4
        l = 1

        while l < n:
            l += k
            k *= 4

        if l == n:
            return True
        
        k = 8
        l = 2

        while l < n:
            l += k
            k *= 4
            
        return l == n
