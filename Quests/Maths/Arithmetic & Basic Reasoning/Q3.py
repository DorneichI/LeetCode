class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        x = str(x)
        rev_x = ""
        for i in range(len(x)):
            rev_x += x[len(x) - i - 1]
        return x == rev_x
        return str(x) == str(x)[::-1]
