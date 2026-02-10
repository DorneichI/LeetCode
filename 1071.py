class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        def divides(s, i):
            d = s[:i]
            for j in range(len(s) // i):
                if s[j * i: j * i + i] != d:
                    return False
            return True
        
        
        index = 0
        while index < len(str1) and index < len(str2):
            if str1[index] != str2[index]:
                return ""
            index += 1
        for i in reversed(range(1, len(str1) + 1)):
            if len(str1) % i == 0 and len(str2) % i == 0:
                if divides(str1, i) and divides(str2, i):
                    return str1[:i]
        return ""
