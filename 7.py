class Solution:
    def reverse(self, x: int) -> int:
        sign = 1
        if x < 0:
            sign = -1
            x *= -1

        x = int(str(x)[::-1]) * sign

        if x > (1 << 31) - 1 or x < -(1 << 31):
            return 0
        
        return x
