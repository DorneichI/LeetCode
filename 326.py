class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        i = 1
        while i < n:
            i *= 3
        return i == n

        # if n == 0:
        #     return False
        # while n % 3 == 0:
        #     n = n / 3
        # if n == 1:
        #     return True
        # else:
        #     return False

        # # if n == 0:
        # #     return False
        # # if n == 1:
        # #     return True
        # # if n % 3 == 0:
        # #     return self.isPowerOfThree(n / 3)
        # # else:
        # #     return False
