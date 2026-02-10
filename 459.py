class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        def checkSubstrings(lenSubstring):
            i = 0
            j = lenSubstring
            while j + lenSubstring <= len(s):
                if s[i:j] != s[j:j+lenSubstring]:
                    return False
                i = j
                j += lenSubstring
            return True
                    
                
        for i in range(len(s) // 2):
            if len(s) % (i + 1) == 0:
                if checkSubstrings(i + 1):
                    return True
        return False
