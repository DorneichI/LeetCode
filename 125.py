class Solution:
    def isPalindrome(self, s: str) -> bool:
        lst = []
        for c in s:
            if c.isalnum():
                lst.append(c)
        s2 = "".join(lst)
        s2 = s2.lower()
        return s2 == s2[::-1]
