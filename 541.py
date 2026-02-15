class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        s = "_" + s
        for i in range(1, len(s), 2*k):
            s = s[:i] + s[i+k-1:i-1:-1] + s[i+k:]
        s = s[1:]
        
        return s
